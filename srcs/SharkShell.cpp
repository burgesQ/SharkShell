# include               "SharkShell.hpp"

SharkShell::SharkShell(char **envp) : _nc(),
                                      _sharkAlias(std::make_shared<SharkAlias>()),
                                      _sharkEnv(std::make_shared<SharkEnv>(envp)),
                                      _confFile(std::make_shared<ConfFile>(_sharkEnv))
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
