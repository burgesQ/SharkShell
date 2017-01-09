# include               "SharkShell.hpp"

SharkShell::SharkShell( char ** envp ) :
  _sharkAlias( std::make_shared< SharkAlias >() ),
  _sharkEnv( std::make_shared< SharkEnv >( envp ) ),
  _confFile( std::make_shared< ConfFile >( _sharkEnv ) ),
  _sharkParser( std::make_shared< SharkParser >() )
{
  std::cout << "SharkShell" << std::endl;
}

SharkShell::~SharkShell()
{}

int                     SharkShell::run()
{
  bool                  run = true;
  _confFile->rcFile();
  while (run)
    {

      std::string input;


      std::string prompt = _sharkEnv->get( std::string("PROMPT") );

      std::cout << prompt ;
      std::getline(std::cin, input);

      _sharkParser->parsLine( input );

      if ( input == "exit" )
	run = false;
    }
  return (0);
}
