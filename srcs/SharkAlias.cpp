# include	<iostream>

# include	"SharkAlias.hpp"

SharkAlias::SharkAlias()
  : _mapAlias()
{}

SharkAlias::~SharkAlias()
{}

void		SharkAlias::setAlias( const std::string & aliasLine )
{
  bool		equal = false;
  std::string	value;
  std::string	key;

  std::cout << aliasLine << std::endl;

  for ( int i = 0; aliasLine[i]; ++i )
    if ( aliasLine[i] == '=' && !equal )
      equal = true;
    else if (!equal)
      key += aliasLine[i];
    else
      value += aliasLine[i];

  _mapAlias.emplace( key, value );
}

const std::string	SharkAlias::get( const std::string & key ) const
{
  auto			it = _mapAlias.find(key);

  if ( it != _mapAlias.end() )
    return it->second;
  return nullptr;
}
