# include	<Ncurses.hpp>
# include	<ncurses.h>

Ncurses::Ncurses() : _ch(),
                     _inputBuffer()
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

void                    Ncurses::close()
{
  endwin();
}

int                     Ncurses::getCh() const
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

// debug
#include<iostream>

void                    Ncurses::handleEvent()
{
  static unsigned int   y = 0;
  int                   i = 0;

  switch (_ch)
    {

    case KEY_BACKSPACE:
      if (!_inputBuffer.empty())
        _inputBuffer.pop_back();
      --y;
      break;

    case KEY_LEFT:
      if (y)
        --y;
      break;

    case KEY_RIGHT:
      if (y < _inputBuffer.size())
        ++y;
      break;

    case KEY_SLEFT:
      for (i = y - 1; isalpha(_inputBuffer[i]); --i);
      if (_inputBuffer[i] == ' ' && _inputBuffer[i - 1] == ' ')
        for (; _inputBuffer[i] == ' '; --i);
      y = (i < 0 ? 0 : i);
      break;

    case KEY_SRIGHT:
      for (i = y + 1; isalpha(_inputBuffer[i]); ++i);
      if (_inputBuffer[i] == ' ' && _inputBuffer[i + 1] == ' ')
        for (; _inputBuffer[i] == ' '; ++i);
      y = i;
      if (y > _inputBuffer.size())
        y = _inputBuffer.size();
      break;

    default:
      if (_ch >= 32 && _ch <= 126)
        {
          _inputBuffer.insert(y, std::string(1, _ch));
          ++y;
        }
      break;
    }

  if (_ch)
    {
      clear();
      write(_inputBuffer);
    }
  move(0, y);
}
