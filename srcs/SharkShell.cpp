# include               "SharkShell.hpp"

SharkShell::SharkShell()
{
  std::cout << "SharkShell" << std::endl;
}

SharkShell::~SharkShell()
{}

int                     SharkShell::run()
{
  bool                  run = true;

  while (run)
    {
      _nc.update();
      _nc.handleEvent();

      // input is not null since now

      _nc.refreshScreen();
    }
  _nc.close();
  return (0);
}
