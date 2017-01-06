# include	<iostream>
# include	<ncurses.h>

int	main(int ac, char **av, char **envp)
{

  std::cout << "SharkShell" << std::endl;

  int run = 11;
  int ch;

  initscr();/* Start curses mode */
  bool isrunning = true;
  while (isrunning)
    {

      // raw();/* Line buffering disabled*/

      keypad(stdscr, TRUE);/* We get F1, F2 etc..*/
      noecho();/* Don't echo() while we do getch */

      ch = getch();/* If raw() hadn't been called
		    * we have to press enter before it
		    * gets to the program */


      if(ch == KEY_F(1))/* Without keypad enabled this will */
	printw("F1 Key pressed");/*  not get to us either*/
      else if (ch == KEY_BACKSPACE)
        continue;
      /* Without noecho() some ugly escape
       * charachters might have been printed
       * on screen*/
      else
	{
	  attron(A_BOLD | A_UNDERLINE);
	  printw("%c", ch);
	  attroff(A_BOLD | A_UNDERLINE);
	}
      refresh();/* Print it on to the real screen */
    }

  endwin();

  return 0;
}
