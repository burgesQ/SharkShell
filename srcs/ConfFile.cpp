# include	<iostream>
# include	<fstream>

# include	"ConfFile.hpp"

ConfFile::ConfFile( std::shared_ptr< SharkEnv > envp )
  :  _sharkEnv( envp )
{}

ConfFile::~ConfFile()
{}

void	ConfFile::rcFile()
{
  std::string		home = _sharkEnv->get( "HOME" );
  std::ifstream		infile;

  infile.open ( home + "/.sharkshellrc" );

  if ( !home.empty()
       && infile.is_open() )
    {
      std::cout << "let set customs value" << std::endl;
      std::string				line;

      while ( std::getline( infile, line ) )
	if ( !line.find( "export " ) )
	  _sharkEnv->setEnv( line );
      infile.close();
    }
  else
    std::cout << "let set the default value" << std::endl;
}
