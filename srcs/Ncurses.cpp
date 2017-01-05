# include	<Ncurses.hpp>

Ncurses::Ncurses() :
  _ch()
{}

Ncurses::~Ncurses()
{}

const int	Ncurses::getCh() const
{
  return _ch;
}

bool		Ncurses::getCh(int ch)
{
  _ch = ch;
}
