# ifndef	__SHARKPARSER_HPP__
# define	__SHARKPARSER_HPP__

# include	<memory>
# include	<vector>

# include	"SharkExec.hpp"

class		SharkParser
{

public :

  explicit SharkParser();
  ~SharkParser();

  std::pair< bool, int >	parsLine( const std::string & line );

private :

  std::vector <  std::string >	splitLine( const std::string & line );

  std::shared_ptr< SharkExec >	_sharkExec;

};

# endif		// !__SHARKPARSER_HPP__
