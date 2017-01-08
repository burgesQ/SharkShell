# include	<Ncurses.hpp>
# include	<ncurses.h>

Ncurses::Ncurses() : _selector(0),
                     _inputDetected(false)
{
  initscr();
}

Ncurses::~Ncurses()
{}

void                    Ncurses::update()
{
  keypad(stdscr, TRUE);
  noecho();
  _ch = getch();
}

void                    Ncurses::refreshScreen()
{
  refresh();
}

void                    Ncurses::clearScreen()
{
  clear();
}

void                    Ncurses::close()
{
  endwin();
}

const int               Ncurses::getCh() const
{
  return _ch;
}

void                    Ncurses::setCh(const int ch)
{
  _ch = ch;
}

void                    Ncurses::write(const int ch)
{
  attron(A_BOLD | A_UNDERLINE);
  printw("%c", ch);
  attroff(A_BOLD | A_UNDERLINE);
}

void                    Ncurses::write(const std::string &sentence)
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

void                    Ncurses::handleEvent()
{
  static unsigned int   y = 0;

  switch (_ch)
    {
    case KEY_BACKSPACE:
      if (!_inputBuffer.empty())
        _inputBuffer.pop_back();
      _inputDetected = true;
      --y;
      break;

    case KEY_LEFT:
      if (y)
        y--;
      _inputDetected = true;
      break;

    case KEY_RIGHT:
      if (y < _inputBuffer.size())
        y++;
      _inputDetected = true;
      break;

    default:
      if (_ch >= 32 && _ch <= 126)
        {
          char ch = _ch;
          std::string str;
          str+=ch;
          _inputBuffer.insert(y, str);
          y++;
        }
      _inputDetected = true;
      break;
    }

  if (_inputDetected)
    {
      this->clearScreen();
      this->write(_inputBuffer);
      _inputDetected = false;
    }
  move(0, y);
}
