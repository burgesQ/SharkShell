#ifndef		__SHARK_BUILTIN_HPP__
# define	__SHARK_BUILTIN_HPP__

# include	<map>
# include	<vector>
# include	<memory>

# include	"SharkEnv.hpp"

# define	builtInCall(instance, ptr) ((instance).*(ptr))

class		SharkBuiltIn
{

public :

  explicit SharkBuiltIn( std::shared_ptr< SharkEnv > sharkEnv );
  ~SharkBuiltIn();

  typedef std::pair< bool, int >	(SharkBuiltIn::*builtIn)( const std::vector< std::string > & cmd );

  std::pair< bool, int >		exit( const std::vector< std::string > & cmd );
  std::pair< bool, int >		help( const std::vector< std::string > & cmd );

  std::pair< bool, int >		env( const std::vector< std::string > & cmd );
  std::pair< bool, int >		setEnv( const std::vector< std::string > & cmd );
  std::pair< bool, int >		unSetEnv( const std::vector< std::string > & cmd );
  std::pair< bool, int >		pwd( const std::vector< std::string > & cmd );
  std::pair< bool, int >		cd( const std::vector< std::string > & cmd );

  // std::pair< bool, int >		echo(std::vector< const std::string & > cmd );

  // std::pair< bool, int >		alias(std::vector< const std::string & > cmd );

  // std::pair< bool, int >		socket(std::vector< const std::string & > cmd );

  // std::pair< bool, int >		cd(std::vector< const std::string & > cmd );

  bool					isBuiltIn( const std::string & cmd ) const;
  std::pair< bool, int >		execBuiltIn( const std::vector< std::string > & cmd );

private :

  std::shared_ptr< SharkEnv >		_sharkEnv;
  std::map< std::string , builtIn >	_builtIn;
  std::string				_oldPwd;
  std::string				_pwd;



  /// cd

  void					_cdBack(const std::string &);
  void					_cdClassic(const std::string &);
  void					_cdOldPwd(const std::string &);
};

# endif		// !__SHARK_BUILTIN_HPP__
