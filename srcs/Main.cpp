# include	<iostream>
# include	<memory>

# include	"ConfFile.hpp"
# include	"SharkEnv.hpp"
# include	"SharkAlias.hpp"

int		main(int, char **, char ** envp)
{
  std::cout << "SharkShell" << std::endl;

  if (envp[0] == NULL)
    return false;

  std::shared_ptr< SharkAlias >	sharkAlias = std::make_shared< SharkAlias >();
  std::shared_ptr< SharkEnv >	sharkEnv = std::make_shared< SharkEnv >( envp );
  std::shared_ptr< ConfFile >	confFile = std::make_shared< ConfFile >( sharkEnv );

  confFile->rcFile();

  return 0;
}
