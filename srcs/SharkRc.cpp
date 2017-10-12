# include	<fstream>
#include <iostream>

# include	"SharkRc.hpp"

SharkRc::SharkRc( std::shared_ptr< SharkEnv > sharkEnv ) :
  _sharkEnv( sharkEnv )
{}

SharkRc::~SharkRc()
{}

void	SharkRc::defaultValue()
{
  _sharkEnv->setEnv("PROMPT=sharkShell~~>");
  // default path
  // default alias ?
  // defualt conf bool [ colors | ... ]*
}

void		SharkRc::customValue( std::ifstream & infile )
{
  std::string	line;

  while ( std::getline( infile, line ) )
    if (!line.find("export ")) // _sharkParser(line);
      _sharkEnv->setEnv(line.erase(0, 7));
  infile.close();

}

void			SharkRc::rcFile()
{
  std::string		home = _sharkEnv->get( "HOME" );
  std::ifstream		infile;

  infile.open ( home + "/.sharkshellrc" ); // use directly ~ ? no more envp @ boot

  if ( !home.empty()
       && infile.is_open() )
    this->customValue(infile);
  else
    this->defaultValue();

}
