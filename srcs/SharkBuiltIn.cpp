# include	"SharkBuiltIn.hpp"

SharkBuiltIn::SharkBuiltIn() :
 _builtIn{ { "exit" , &SharkBuiltIn::exit } }
{}

SharkBuiltIn::~SharkBuiltIn()
{}

std::pair< bool, int >	SharkBuiltIn::exit( const std::vector< std::string > & cmd )
{
  if (cmd.size() == 1)
    return { false, 0 };
  return { false, std::atoi(cmd[1].c_str()) };
}

bool		SharkBuiltIn::isBuiltIn( const std::string & cmd ) const
{
  return ( _builtIn.find( cmd ) == _builtIn.end() ) ? false : true;
}

std::pair< bool, int >	SharkBuiltIn::execBuiltIn( const std::vector< std::string > & cmd )
{
  return builtInCall(*this, _builtIn[cmd[0]])(cmd);
}
