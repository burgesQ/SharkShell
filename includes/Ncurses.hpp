# include	<ncurses.h>

class		Ncurses
{

public :

  Ncurses();
  ~Ncurses();

  const int	getCh() const;
  bool		setCh(int ch);

private :
  int	_ch;
}
