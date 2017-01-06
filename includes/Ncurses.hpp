#ifndef         __NCURSES_HPP__
# define        __NCURSES_HPP__

# include	<ncurses.h>

class		Ncurses
{

public :

  explicit Ncurses();
  ~Ncurses();

  void          clear();
  void          update();
  void          close();
  void          displayChar(const int ch);
  const int	getCh() const;
  void		setCh(const int ch);

private :
  int	_ch;
};

#endif          // !__NCURSES_HPP__
