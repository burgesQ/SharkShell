# include	<vector>
# include	<iostream>
# include	<string>
# include	"SharkException.hpp"

class		MobyDick
{
 public:

  static bool directoryExist(const std::string& dirName);
  static bool fileExist(const std::string& fileName);
  static bool fileIsExecutable(const std::string& fileName);

  static const std::vector< std::string > SplitLines( const std::string& line, const char sep);
  static std::string reformatPath(const std::string& line, const char sep);
  static bool startsWith(const std::string& src, const std::string& token);

  static bool IsMatchCaseInsensitiveSomeWhere(const std::string& s1, const std::string& s2);
  static bool IsMatchCaseInsensitive(const std::string& s1, const std::string& s2);
};
