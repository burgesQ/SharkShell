# include               <iostream>
# include               <vector>
# include               "Ncurses.hpp"

int                     main(int ac, char **av, char **envp)
{

  std::cout << "SharkShell" << std::endl;

  bool                  run = true;
  bool                  inputDetected = false;
  Ncurses               nc;
  std::vector<int>      buffer;

  while (run)
    {
      nc.clear();
      // raw();/* Line buffering disabled*/

      if (nc.getCh() == KEY_F(1))
	printw("F1 Key pressed");/*  not get to us either*/
      else if (nc.getCh() == KEY_BACKSPACE && !buffer.empty())
        {
          buffer.pop_back();
          inputDetected = true;
        }
      else
	{
          buffer.push_back(nc.getCh());
          inputDetected = true;
	}
      if (inputDetected)
        {
          clear();
          for (unsigned int i = 0; i < buffer.size(); ++i)
            nc.displayChar(buffer[i]);
          inputDetected = false;
        }

      nc.update();
    }
  nc.close();
  return 0;
}
