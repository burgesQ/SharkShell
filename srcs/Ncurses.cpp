# include	<Ncurses.hpp>
# include	<ncurses.h>

Ncurses::Ncurses() :
  _ch()
{
  initscr();
}

Ncurses::~Ncurses()
{}

void            Ncurses::clear()
{
  keypad(stdscr, TRUE);
  noecho();
  _ch = getch();
}

void            Ncurses::update()
{
  refresh();
}

void            Ncurses::close()
{
  endwin();
}

const int	Ncurses::getCh() const
{
  return _ch;
}

void		Ncurses::setCh(const int ch)
{
  _ch = ch;
}

void            Ncurses::displayChar(const int ch)
{
  attron(A_BOLD | A_UNDERLINE);
  printw("%c", ch);
  attroff(A_BOLD | A_UNDERLINE);
}
