#ifndef		__SHARK_RC_HPP__
# define	__SHARK_RC_HPP__

# include	<memory>

# include	"SharkEnv.hpp"

class		SharkRc
{

public :

  explicit SharkRc( std::shared_ptr< SharkEnv > envp );
  ~SharkRc();

  void		rcFile();

private :

  void				defaultValue();
  void				customValue( std::ifstream & infile );

  std::shared_ptr< SharkEnv >	_sharkEnv;

};

# endif		// !__SHARK_RC_HPP__
