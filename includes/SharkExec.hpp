#ifndef		__SHARK_EXEC_HPP__
# define	__SHARK_EXEC_HPP__

# include	<string>
# include	<memory>
# include	<vector>
# include	"SharkBuiltIn.hpp"

class		SharkExec
{

public :

  explicit SharkExec( std::shared_ptr< SharkEnv > sharkEnv );
  ~SharkExec();

  const std::shared_ptr< SharkBuiltIn > &	getSharkBuiltIn() const;

  void						execCmd( const std::vector<std::string> cmd,
							 const std::string & pathToCmd );
  std::pair< bool, int >			execBuiltIn( std::vector< std::string > oneCmd );
  std::string					isExecutable(const std::string & cmd);

private :

  std::shared_ptr< SharkBuiltIn >		_sharkBuiltIn;
  std::shared_ptr< SharkEnv >			_sharkEnv;

  const std::vector< std::string >		_getPaths();

};

# endif		// !__SHARK_EXEC_HPP__
