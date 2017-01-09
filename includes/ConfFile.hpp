#ifndef		__CONFFILE_HPP__
# define	__CONFFILE_HPP__

# include	<memory>

# include	"SharkEnv.hpp"

class		ConfFile
{

public :

  explicit	ConfFile( std::shared_ptr< SharkEnv > envp );
  ~ConfFile();

  void		rcFile();

private :

  void		defaultValue();
  void		customValue(  std::ifstream & infile );

  std::shared_ptr<SharkEnv>	_sharkEnv;

};

# endif		// !__CONFFILE_HPP__
