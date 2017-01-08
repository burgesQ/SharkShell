# include	<iostream>
# include	<fstream>

# include	"ConfFile.hpp"

ConfFile::ConfFile( char ** envp )
  :  _tabEnvp(envp),
  _mapEnvp()

{
  for ( int i = 0; _tabEnvp[i]; ++i )
    {
      std::string line ( _tabEnvp[i] ) ;
      this->setEnv( line );
    }
}

ConfFile::~ConfFile()
{}

void		ConfFile::setEnv( const std::string & envLine )
{
  bool		equal = false;
  std::string	value;
  std::string	key;

  std::cout << envLine << std::endl;

  for ( int i = 0; envLine[i]; ++i )
    if ( envLine[i] == '=' && !equal )
      equal = true;
    else if (!equal)
      key += envLine[i];
    else
      value += envLine[i];

  _mapEnvp.emplace( key, value );

}


std::map<const std::string, std::string >	ConfFile::getEnv()
{
  auto						home = _mapEnvp.find( "HOME" );
  std::ifstream					infile;

  infile.open ( home->second + "/.sharkshellrc" );

  if ( home != _mapEnvp.end()
       && infile.is_open() )
    {
      std::cout << "let set customs value" << std::endl;
      std::string				line;

      while ( std::getline( infile, line ) )
	if ( !line.find( "export " ) )
	  this->setEnv( line );
      infile.close();
    }
  else
    std::cout << "let set the default value" << std::endl;
  return _mapEnvp;
}
