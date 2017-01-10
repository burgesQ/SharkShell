#ifndef		__SHARK_BUILTIN_HPP__
# define	__SHARK_BUILTIN_HPP__

# include	<map>
# include	<vector>

# define	builtInCall(instance, ptr) ((instance).*(ptr))

class		SharkBuiltIn
{

public :

  explicit SharkBuiltIn();
  ~SharkBuiltIn();

  typedef std::pair< bool, int >	(SharkBuiltIn::*builtIn)( const std::vector< std::string > & cmd );

  std::pair< bool, int >		exit( const std::vector< std::string > & cmd );

  // std::vector< int >		env(std::vector< const std::string & > cmd );
  // std::vector< int >		setenv(std::vector< const std::string & > cmd );
  // std::vector< int >		unsetenv(std::vector< const std::string & > cmd );

  // std::vector< int >		echo(std::vector< const std::string & > cmd );

  // std::vector< int >		alias(std::vector< const std::string & > cmd );

  // std::vector< int >		socket(std::vector< const std::string & > cmd );

  // std::vector< int >		cd(std::vector< const std::string & > cmd );

  bool				isBuiltIn( const std::string & cmd ) const;
  std::pair< bool, int >	execBuiltIn( const std::vector< std::string > & cmd );

private :

  std::map< std::string , builtIn >	_builtIn;

};

# endif		// !__SHARK_BUILTIN_HPP__
