#ifndef                 __SHARK_SHELL_HPP__
# define                __SHARK_SHELL_HPP__

# include               <iostream>
# include               <memory>
# include               <vector>
# include               "SharkAlias.hpp"
# include               "SharkEnv.hpp"
# include               "ConfFile.hpp"
# include               "Ncurses.hpp"

class                           SharkShell
{
public:
  explicit SharkShell(char **envp);
  ~SharkShell();

  int                           run();

private:
  Ncurses                       _nc;
  std::shared_ptr<SharkAlias>   _sharkAlias;
  std::shared_ptr<SharkEnv>     _sharkEnv;
  std::shared_ptr<ConfFile>     _confFile;
};

#endif                  // !__SHARK_SHELL_HPP__
