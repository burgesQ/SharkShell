# include	<unistd.h>
# include	<sys/types.h>
# include	"SharkExec.hpp"
# include	"MobyDick.h"

SharkExec::SharkExec( std::shared_ptr< SharkEnv > sharkEnv ) :
  _sharkBuiltIn( std::make_shared< SharkBuiltIn > ( sharkEnv ) ),
  _sharkEnv(std::make_shared< SharkEnv > (*sharkEnv))
{}

SharkExec::~SharkExec()
{}

const std::shared_ptr< SharkBuiltIn > &	SharkExec::getSharkBuiltIn() const
{
  return _sharkBuiltIn;
}

std::pair< bool, int >	SharkExec::execBuiltIn( const std::vector< std::string > cmd )
{
  return _sharkBuiltIn->execBuiltIn( cmd );
}

std::string		SharkExec::isExecutable(const std:: string & cmd)
{
  const std::vector<std::string> getPaths = MobyDick::SplitLines(_sharkEnv->get("PATH"), ':');
  std::vector<std::string>::const_iterator it = getPaths.begin();
  for (; it != getPaths.end(); ++it) {
    std::string testCmd(*it + "/" + cmd);
    if (MobyDick::fileExist(testCmd) && MobyDick::fileIsExecutable(testCmd))
      return *it;
  }
  return "";
}

void	SharkExec::execCmd( const std::vector<std::string> cmd,
 			    const std::string & pathToBin)
{
  try {

    const unsigned int nbParams = cmd.size();

    char ** const	cmdToTab = (char **)malloc(sizeof(char *) * (nbParams));
    if (cmdToTab == NULL && nbParams < 1)
      throw new SharkException("malloc failed");

    char * const	envp[2] = {
      const_cast<char *>(_sharkEnv->get("PATH").c_str()),
      NULL
    };

    unsigned int cmdIndex = 0;
    std::string fullCmd(pathToBin + "/"+ cmd[0]);
    for (const auto &it : cmd)
      cmdToTab[cmdIndex++] = const_cast<char *>(cmdIndex == 0 ? fullCmd.c_str() : it.c_str());
    cmdToTab[cmdIndex] = NULL;

    pid_t pid;
    if ((pid = fork()) == -1)
      perror("fork error");
    else if (pid == 0) {
      int ret = execve(fullCmd.c_str(), cmdToTab, envp);
      if (ret == -1)
	throw new SharkException("excve failed");
    }

  } catch (SharkException se) {
    std::cerr << "execCmd::" << se.what() << std::endl;
  }
}
