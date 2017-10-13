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
  if (cmd.size() != 2)
    std::cerr << "setEnv <var=var>" << std::endl;
  else
    _sharkEnv->setEnv(cmd[1]);
  return { true, 0 };
}

std::pair< bool, int >	SharkBuiltIn::unSetEnv( const std::vector< std::string > & cmd )
{
  if (cmd.size() != 2)
    std::cerr << "unSetEnv <key>" << std::endl;
  else if (_sharkEnv->get(cmd[1]).empty())
    std::cerr << "Key does not exist" << std::endl;
  else
    _sharkEnv->unSetEnv(cmd[1]);
  return { true, 0 };
}
