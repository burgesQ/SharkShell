#ifndef		_SHARK_EXCEPTION_HPP_
# define	_SHARK_EXCEPTION_HPP_

# include	<exception>

class	        SharkException : public std::exception
{
public:
  SharkException(const std::string &what) throw() : _what(what)
  {
  }

  virtual ~SharkException() throw()
  {
  }

  virtual const char *what() const throw()
  {
    return _what.c_str();
  }

  const std::string& guessWhat() const
  {
    return _what;
  }

private:
  std::string	_what;

};

#endif		// _SHARK_EXCEPTION_HPP_
