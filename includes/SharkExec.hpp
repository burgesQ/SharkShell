#ifndef		__SHARK_EXEC_HPP__
# define	__SHARK_EXEC_HPP__

# include	<string>
# include	<memory>

# include	"SharkBuiltIn.hpp"

class		SharkExec
{

public :

  explicit SharkExec( std::shared_ptr< SharkEnv > sharkEnv );
  ~SharkExec();

  const std::shared_ptr< SharkBuiltIn > &	getSharkBuiltIn() const;

  void						execCmd( const std::string & line, const std::string & path );
  std::pair< bool, int >			execBuiltIn( std::vector< std::string > oneCmd );

private :

  std::shared_ptr< SharkBuiltIn >	_sharkBuiltIn;


};

# endif		// !__SHARK_EXEC_HPP__
