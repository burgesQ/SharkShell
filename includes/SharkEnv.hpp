#ifndef		__SHARK_ENV_HPP__
# define	__SHARK_ENV_HPP__

# include	<map>

class		SharkEnv
{

public :

  SharkEnv( char ** envp );
  ~SharkEnv();

  std::map< const std::string, std::string >	getMapEnv() const;

  void						setEnv( const std::string & envLine );

  const std::string				get( const std::string & key ) const;
  void getPaths();

private :

  std::map<const std::string, std::string >	_mapEnvp;

};

# endif		// !__SHARK_ENV_HPP__
