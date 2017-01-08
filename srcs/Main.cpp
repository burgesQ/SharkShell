# include	<iostream>
# include	<memory>

# include	"ConfFile.hpp"

int		main(int ac, char ** av, char ** envp)
{
  std::cout << "SharkShell" << std::endl;

  if (envp[0] == NULL)
    return false;

  std::shared_ptr< ConfFile >	confFile = std::make_shared< ConfFile >(envp);

  confFile->getEnv();

  return 0;
}
