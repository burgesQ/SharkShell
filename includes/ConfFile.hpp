#ifndef		__CONFFILE_HPP__
# define	__CONFFILE_HPP__

# include	<map>

class		ConfFile
{

public :

  explicit	ConfFile(char ** envp);
  ~ConfFile();

  std::map<const std::string, std::string >	getEnv();

private :

  void						setEnv( const std::string & envLine );

  char **					_tabEnvp;
  std::map<const std::string, std::string>	_mapEnvp;

};

# endif		// !__CONFFILE_HPP__
