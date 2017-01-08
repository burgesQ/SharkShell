# include               "SharkShell.hpp"

int                     main(int ac, char **av, char **envp)
{
  if (!envp[0])
    return false;
  SharkShell            shark(envp);

  return shark.run();
}
