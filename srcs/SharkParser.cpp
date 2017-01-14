# include	"SharkParser.hpp"

SharkParser::SharkParser( std::shared_ptr< SharkEnv > sharkEnv ) :
  _sharkExec( std::make_shared< SharkExec > ( sharkEnv ) )
{}

SharkParser::~SharkParser()
{}

std::vector <  std::string >	SharkParser::splitLine( const std::string & line )
{
  std::vector < std::string >	oneCmd;
  std::string			chunk;

  chunk.clear();

  for ( auto it : line )
    if ( it != ' ' )
      chunk += it;
    else
      {
	oneCmd.push_back(  chunk );
	chunk.clear();
      }
  oneCmd.push_back( chunk );

  return oneCmd;
}

std::pair< bool, int >		SharkParser::parsLine( const std::string & line )
{
  std::vector< std::string >	oneCmd = this->splitLine(line);

  if ( _sharkExec->getSharkBuiltIn()->isBuiltIn( oneCmd[0] ) )
    return _sharkExec->execBuiltIn( oneCmd );
  // else if in path
  // exec
  // else
  // cmd not found

  return { true, 0 };
}
