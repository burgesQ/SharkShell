# include	<Ncurses.hpp>
# include	<ncurses.h>

Ncurses::Ncurses() : _inputDetected(false)
{
  initscr();
}

Ncurses::~Ncurses()
{}

void            Ncurses::update()
{
  keypad(stdscr, TRUE);
  noecho();
  _ch = getch();
}

void            Ncurses::refreshScreen()
{
  refresh();
}

void            Ncurses::clearScreen()
{
  clear();
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

void            Ncurses::write(const int ch)
{
  attron(A_BOLD | A_UNDERLINE);
  printw("%c", ch);
  attroff(A_BOLD | A_UNDERLINE);
}

void            Ncurses::write(const std::string &sentence)
{
  for (unsigned int i = 0; i < sentence.size(); ++i)
    {
      attron(A_BOLD | A_UNDERLINE);
      printw("%c", sentence[i]);
      attroff(A_BOLD | A_UNDERLINE);
    }
}

const std::string&      Ncurses::getInputBuffer() const
{
  return _inputBuffer;
}

void            Ncurses::handleEvent()
{
  if (_ch == KEY_BACKSPACE)
    {
      if (!_inputBuffer.empty())
        _inputBuffer.pop_back();
      _inputDetected = true;
    }
  else
    {
      _inputBuffer.push_back(_ch);
      _inputDetected = true;
    }
  if (_inputDetected)
    {
      this->clearScreen();
      this->write(_inputBuffer);
      _inputDetected = false;
    }
}
