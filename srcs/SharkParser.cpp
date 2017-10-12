# include	<iostream>
# include	"SharkParser.hpp"
# include	"MobyDick.h"

SharkParser::SharkParser( std::shared_ptr< SharkEnv > sharkEnv ) :
  _sharkExec( std::make_shared< SharkExec > ( sharkEnv ) )
{}

SharkParser::~SharkParser()
{}

std::pair< bool, int >		SharkParser::parsLine( const std::string & line )
{
  try {
    std::vector< std::string >	oneCmd = MobyDick::SplitLines(line, ' ');
  
    if ( _sharkExec->getSharkBuiltIn()->isBuiltIn( oneCmd[0] ) )
      return _sharkExec->execBuiltIn( oneCmd );

    std::string pathToCmd = _sharkExec->isExecutable( oneCmd[0] );

    if (!pathToCmd.empty())
      std::cout << "EXECUTABLE!! :: " << pathToCmd << std::endl; 
    else
      std::cout << "Command not found : " << oneCmd[0] << std::endl;
  } catch (SharkException e) {
    std::cerr << e.what() << std::endl;
  }

  return { true, 0 };
}
