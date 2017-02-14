# include	<iostream>

# include	"SharkBuiltIn.hpp"

std::pair< bool, int >	SharkBuiltIn::env( const  std::vector< std::string > & cmd )
{
  for ( auto it : _sharkEnv->getMapEnv() )
    std::cout << it.first + "=" + it.second << std::endl;
  return { true, 0 };
}

std::pair< bool, int >	SharkBuiltIn::setEnv( const std::vector< std::string > & cmd )
{
  std::string key = cmd;

  key.erase(0, 7);

  std::cout << key << std::endl;


  return { true, 0 };
}

std::pair< bool, int >	SharkBuiltIn::unSetEnv( const std::vector< std::string > & cmd )
{
  return { true, 0 };
}
