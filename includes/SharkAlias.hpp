#ifndef		__SHARK_ALIAS_HPP__
# define	__SHARK_ALIAS_HPP__

# include	<map>

class		SharkAlias
{

public :

  SharkAlias();
  ~SharkAlias();

  void			setAlias( const std::string & aliasLine );

  const std::string	get( const std::string & key ) const;

private :

  std::map<const std::string, std::string>	_mapAlias;

};

# endif		// !__SHARK_ALIAS_HPP__
