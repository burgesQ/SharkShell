# include               "SharkShell.hpp"

int                     main(int , char **, char **envp)
{
  if (!envp[0])
    return false;

  std::shared_ptr< SharkShell > shark = std::make_shared< SharkShell > ( envp );

  return shark->run();
}
