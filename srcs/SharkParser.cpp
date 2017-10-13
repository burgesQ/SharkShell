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
  const std::vector< std::string > oneCmd = MobyDick::SplitLines(line, ' ');

  if ( _sharkExec->getSharkBuiltIn()->isBuiltIn( oneCmd[0] ) )
    return _sharkExec->execBuiltIn( oneCmd );

  std::string pathToCmd;
  pathToCmd = _sharkExec->isExecutable( oneCmd[0] );
  if (!pathToCmd.empty())
    {
      _sharkExec->execCmd(oneCmd, pathToCmd);
      std::cout << "EXECUTABLE!! :: " << pathToCmd + "/" + oneCmd[0]<< std::endl;
      // _sharkExec->exec(pathToCmd);
    }
  else
    std::cout << "Command not found : " << oneCmd[0] << std::endl;

  return { true, 0 };
  } catch (SharkException se) {
    std::cerr << "HALLO:" << se.what() << std::endl;
  }
}
