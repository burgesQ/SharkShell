# include	<unistd.h>
# include	"SharkExec.hpp"
# include	"MobyDick.h"
# include	<iostream>

SharkExec::SharkExec( std::shared_ptr< SharkEnv > sharkEnv ) :
  _sharkBuiltIn( std::make_shared< SharkBuiltIn > ( sharkEnv ) ),
  _sharkEnv(std::make_shared< SharkEnv > (*sharkEnv))
{}

SharkExec::~SharkExec()
{}

const std::shared_ptr< SharkBuiltIn > &	SharkExec::getSharkBuiltIn() const
{
  return _sharkBuiltIn;
}

void	SharkExec::execCmd( const std::string & ,
			    const std::string &  )
{}

std::pair< bool, int >	SharkExec::execBuiltIn( const std::vector< std::string > cmd )
{
  return _sharkBuiltIn->execBuiltIn( cmd );
}

std::string		SharkExec::isExecutable(const std:: string & cmd)
{
  for (auto it : MobyDick::SplitLines(_sharkEnv->get("PATH"), ':'))
    {
      std::string path = it + "/" + cmd;
      if (access(path.c_str(), F_OK) != -1)
	return path;
    }
  return "";
}

