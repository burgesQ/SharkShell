# include               "SharkShell.hpp"

int                     main(int , char **, char **envp)
{
  if (!envp[0])
    return false;
  SharkShell            shark(envp);

  return shark.run();
}
