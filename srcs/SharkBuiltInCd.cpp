# include	<unistd.h>
# include	"SharkBuiltIn.hpp"
# include	"MobyDick.h"

void			SharkBuiltIn::_cdBack()
{
  try {
    std::string		newPwd;
    unsigned int	pathIndex = 0;
    const std::vector<std::string> pwdPaths = MobyDick::SplitLines(_pwd, '/');

    for (const auto &it : pwdPaths) {
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
    std::cerr << se.what() << std::endl;
  }
}

void			SharkBuiltIn::_cdOldPwd()
{
  try {
    if (_oldPwd.empty())
      std::cout << "Previous directory is empty actually.." << std::endl;
    else if (chdir(_oldPwd.c_str()) == -1)
      throw new SharkException("Error with pwd");
    else {
      std::string	tmp = _oldPwd;
      _pwd = _oldPwd;
      _oldPwd = tmp;
    }
  } catch (SharkException se) {
    std::cerr << se.what() << std::endl;
  }
}

void			SharkBuiltIn::_cdClassic(const std::string &cmd)
{
  try {
    std::string		currentCmd(MobyDick::startsWith(cmd, "./") ? cmd.substr(2, cmd.size()) : cmd);
    std::string		fromRoot(_pwd + "/" + currentCmd);

    if (MobyDick::directoryExist(fromRoot)) {
      if (chdir(fromRoot.c_str()) == -1)
	throw new SharkException("Error with pwd");
      _oldPwd = _pwd;
      _pwd = (_pwd[0] != '/' ? "/" : "") + MobyDick::reformatPath(fromRoot, '/');

    } else if (MobyDick::directoryExist(currentCmd)) {
      if (chdir(currentCmd.c_str()) == -1)
	throw new SharkException("Error with pwd");
      _oldPwd = _pwd;
      _pwd = MobyDick::reformatPath(currentCmd, '/');

    } else {
      std::cerr << "wrong path : " + currentCmd << std::endl;
      return ;
    }
  } catch (SharkException se) {
    std::cerr << se.what() << std::endl;
  }
}

std::pair<bool, int>	SharkBuiltIn::cd(const std::vector<std::string> &cmd)
{
  try {
    const unsigned int cmdSize = cmd.size();
    if (cmd[0] == "cd.." && cmdSize == 1)
      _cdBack();
    if (cmdSize == 2) {
      if (cmd[1] == "-")
	_cdOldPwd();
      else if (cmd[1] == "..")
	_cdBack();
      else if (cmd[1] == "." || cmd[1] == "./")
	return {true, 0};
      else
	_cdClassic(cmd[1]);
      std::cout << _pwd << std::endl;
    }
    else
      std::cerr << "cd take only 1 argument : cd <directoryToChange>" << std::endl;
  } catch (SharkException se) {
    std::cerr << "BuiltIn::cd::" << se.what() << std::endl;
  }
  return {true, 0};
}
