#ifndef         __NCURSES_HPP__
# define        __NCURSES_HPP__

# include	<ncurses.h>
# include       <string>

class		Ncurses
{

public :

  explicit Ncurses();
  ~Ncurses();

  void          update();
  void          clearScreen();
  void          refreshScreen();
  void          close();
  void          write(const int ch);
  void          write(const std::string &sentence);
  void          handleEvent();
  const std::string&   getInputBuffer() const;
  const int	getCh() const;
  void		setCh(const int ch);

private :

  int           _ch;
  int           _selector;
  bool          _inputDetected;
  std::string   _inputBuffer;
};

#endif          // !__NCURSES_HPP__
