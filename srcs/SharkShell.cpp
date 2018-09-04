# include	<iostream>

# include	"SharkShell.hpp"

SharkShell::SharkShell( char ** envp ) :
  _sharkAlias( std::make_shared< SharkAlias > () ),
  _sharkEnv( std::make_shared< SharkEnv > ( envp ) ),
  _sharkRc( std::make_shared< SharkRc > ( _sharkEnv ) ),
  _sharkParser( std::make_shared< SharkParser > ( _sharkEnv ) )
{
  std::cout << "SharkShell" << std::endl;
  _sharkRc->rcFile();
}

SharkShell::~SharkShell()
{}

int				SharkShell::run()
{
  std::pair< bool, int >	run = { true, 0 };
  std::string			input;
  std::string			prompt = _sharkEnv->get( "PROMPT" ); // next SharkEnv w/ overload<<

  while (run.first)
    {
      std::cout << prompt ;
      std::getline( std::cin, input );

      run = _sharkParser->parsLine( input );
    }

  return (run.second);
}
