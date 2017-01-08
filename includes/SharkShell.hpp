#ifndef                 __SHARK_SHELL_HPP__
# define                __SHARK_SHELL_HPP__

# include               <iostream>
# include               <vector>
# include               "Ncurses.hpp"

class                   SharkShell
{
public:
  explicit SharkShell();
  ~SharkShell();

  int                   run();

private:
  Ncurses               _nc;
};

#endif                  // !__SHARK_SHELL_HPP__
