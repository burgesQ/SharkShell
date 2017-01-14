# include	"SharkExec.hpp"

SharkExec::SharkExec( std::shared_ptr< SharkEnv > sharkEnv ) :
  _sharkBuiltIn( std::make_shared< SharkBuiltIn > ( sharkEnv ) )
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
