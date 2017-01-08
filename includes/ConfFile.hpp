#ifndef		__CONFFILE_HPP__
# define	__CONFFILE_HPP__

# include	<memory>

# include	"SharkEnv.hpp"

class		ConfFile
{

public :

  explicit	ConfFile(  std::shared_ptr< SharkEnv > envp);
  ~ConfFile();

  std::map<const std::string, std::string >	rcFile();

private :

  void						setEnv( const std::string & envLine );

  char **					_tabEnvp;
  std::map<const std::string, std::string>	_mapEnvp;

};

# endif		// !__CONFFILE_HPP__
