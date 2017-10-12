#include <iostream>
# include	"SharkEnv.hpp"

SharkEnv::SharkEnv( char ** envp ) :
  _mapEnvp()
{
  for ( int i = 0; envp[i]; ++i )
    this->setEnv( std::string( envp[i] ) );
}

SharkEnv::~SharkEnv()
{}

std::map< const std::string, std::string >	SharkEnv::getMapEnv() const
{
  return _mapEnvp;
}

void		SharkEnv::setEnv( const std::string & envLine )
{
  bool		equal = false;
  std::string	value;
  std::string	key;

  for ( int i = 0; envLine[i]; ++i )
    if (envLine[i] == '=' && !equal)
      equal = true;
    else if (!equal)
      key += envLine[i];
    else
      value += envLine[i];

  _mapEnvp.emplace( key, value );
}

const std::string	SharkEnv::get( const std::string & key ) const
{
  auto			it = _mapEnvp.find(key);

  if ( it != _mapEnvp.end() )
    return it->second;
  return "";
}
