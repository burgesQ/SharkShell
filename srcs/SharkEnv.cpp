# include	<iostream>

# include	"SharkEnv.hpp"

SharkEnv::SharkEnv( char ** envp )
  : _mapEnvp()
{
  for ( int i = 0; envp[i]; ++i )
    {
      std::string line ( envp[i] ) ;
      this->setEnv( line );
    }
}

SharkEnv::~SharkEnv()
{}

void		SharkEnv::setEnv( const std::string & envLine )
{
  bool		equal = false;
  std::string	value;
  std::string	key;

  std::cout << envLine << std::endl;

  for ( int i = 0; envLine[i]; ++i )
    if ( envLine[i] == '=' && !equal )
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
  return nullptr;
}
