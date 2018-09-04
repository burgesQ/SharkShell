# include	<unistd.h>
# include	<sys/stat.h>
# include	"MobyDick.h"

bool		MobyDick::directoryExist(const std::string& dirName)
{
  struct stat	sb;
  return (stat(dirName.c_str(), &sb) == 0 && S_ISDIR(sb.st_mode));
}

bool		MobyDick::fileExist(const std::string& fileName)
{
  return (access(fileName.c_str(), F_OK) != -1);
}

bool		MobyDick::IsExecutable(const std::string& fileName)
{
  struct stat sb;
  return (stat(fileName.c_str(), &sb) == 0 && sb.st_mode & S_IXUSR);
}
