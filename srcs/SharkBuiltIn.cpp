# include	<iostream>
# include	<unistd.h>
# include	"SharkBuiltIn.hpp"
# include	"MobyDick.h"

//TODO cd, echo
SharkBuiltIn::SharkBuiltIn( std::shared_ptr< SharkEnv > sharkEnv ) : _sharkEnv( sharkEnv ),
								     _sharkAlias(),
								     _pwd(get_current_dir_name()),
 _builtIn {
  { "exit" , &SharkBuiltIn::exit },
    {"pwd", &SharkBuiltIn::pwd },
      { "alias", &SharkBuiltIn::alias },
      	{ "cd", &SharkBuiltIn::cd },
	        { "help" , &SharkBuiltIn::help },
	          { "env" , &SharkBuiltIn::env },
	            { "setEnv" , &SharkBuiltIn::setEnv },
		            { "unSetEnv" , &SharkBuiltIn::unSetEnv } }
{}

SharkBuiltIn::~SharkBuiltIn()
{}

std::pair< bool, int >		SharkBuiltIn::alias(const std::vector< std::string > & cmd )
{
  if (cmd.size() == 2)
    {
      _sharkAlias->setAlias(cmd[1]);
      std::cout << "ICI=>" << _sharkAlias->get(cmd[1]) << std::endl;

      if (MobyDick::IsExecutable(cmd[1]))
	{

	  std::cout << "alias can work" << cmd[1] << std::endl;
	}
      else
	{
	  std::cout << "alias canot work" << cmd[1] << std::endl;
	}
    }
  else if (cmd.size() == 3)
    {

    }
  return { true, 0 };
}

std::pair< bool, int >	SharkBuiltIn::pwd( const std::vector< std::string > & cmd )
{
  std::cout << _pwd << std::endl;
  return { true, 0 };
}

std::pair< bool, int >	SharkBuiltIn::exit( const std::vector< std::string > & cmd )
{
  if (cmd.size() == 1)
    return { false, 0 };
  return { false, std::atoi(cmd[1].c_str()) };
}

std::pair< bool, int >	SharkBuiltIn::help( const std::vector< std::string > & )
{
  std::cout << "This will be a amazing help page; maybe a man page !" << std::endl;
  return { true, 0 };
}

bool		SharkBuiltIn::isBuiltIn(  const std::string & cmd ) const
{
  return ( _builtIn.find( cmd ) == _builtIn.end() ) ? false : true;
}

std::pair< bool, int >	SharkBuiltIn::execBuiltIn( const std::vector< std::string > & cmd )
{
  return builtInCall(*this, _builtIn[cmd[0]])(cmd);
}
