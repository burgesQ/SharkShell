# include	<unistd.h>
# include	"SharkBuiltIn.hpp"
# include	"MobyDick.h"

void			SharkBuiltIn::_cdBack(const std::string &)
{
  try {
    std::string		newPwd;
    unsigned int		pathIndex = 0;
    const std::vector<std::string> pwdPaths = MobyDick::SplitLines(_pwd, '/');

    for (const auto &it : pwdPaths)
      {
	pathIndex++;
	if (pathIndex && pathIndex < pwdPaths.size() && !it.empty())
	  newPwd += "/" + it;
      }
    _oldPwd = _pwd;
    _pwd = newPwd;
    if (_pwd.empty())
      _pwd = "/";
    if (chdir(_pwd.c_str()) == -1)
      throw new SharkException("Error with pwd");
  } catch (SharkException se) {
    throw new SharkException(se.guessWhat());
  }    
}

void			SharkBuiltIn::_cdOldPwd(const std::string &)
{
  try {
    if (_oldPwd.empty())
      std::cout << "Previous directory is empty actually.." << std::endl;
    else if (chdir(_oldPwd.c_str()) == -1)
      throw new SharkException("Error with pwd");
    else
      {
	std::string tmp = _oldPwd;	
	_pwd = _oldPwd;
	_oldPwd = tmp;
      }
  } catch (SharkException se) {
    throw new SharkException (se.guessWhat());
  }
}

void			SharkBuiltIn::_cdClassic(const std::string &cmd)
{
  try {
    std::string fromRoot(_pwd + "/" + cmd);

    if (MobyDick::directoryExist(fromRoot)) {
      if (chdir(fromRoot.c_str()) == -1)
	throw new SharkException("Error with pwd");
      _oldPwd = _pwd;
      _pwd = "/" + MobyDick::reformatPath(fromRoot, '/');

    } else if (MobyDick::directoryExist(cmd)) {
      if (chdir(cmd.c_str()) == -1)
	throw new SharkException("Error with pwd");
      _oldPwd = _pwd;
      _pwd = MobyDick::reformatPath(cmd, '/');

    } else {
      std::cerr << "You must provide a directory to change" << std::endl;
      return ;
    }
  } catch (SharkException se) {
    throw new SharkException (se.guessWhat());
  }
}

std::pair<bool, int>	SharkBuiltIn::cd(const std::vector<std::string> &cmd)
{
  try {
  if (cmd.size() < 3) {
    for (unsigned int i = 1; i < cmd.size(); i++) {
      if (cmd[i] == "-")
	_cdOldPwd(cmd[i]);
      else if (cmd[i] == "..")
	_cdBack(cmd[i]);
      else if (cmd[i] == "." || cmd[i] == "./")
	continue;
      else
	_cdClassic(cmd[i]);
    }
  }
  else
    std::cerr << "cd can take 3 arguments : cd <option> <directory>" << std::endl;
  } catch (SharkException se) {
    throw new SharkException ("cd::" + se.guessWhat());
  }  
  return {true, 0};
}
