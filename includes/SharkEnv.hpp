#ifndef		__SHARKENV_HPP__
# define	__SHARKENV_HPP__

# include	<map>

class		SharkEnv
{

public :

  SharkEnv( char ** envp );
  ~SharkEnv();

  void						setEnv( const std::string & envLine );

  const std::string				get( const std::string & key ) const;

private :

  std::map<const std::string, std::string>	_mapEnvp;

};

# endif		// !__SHARKENV_HPP__
