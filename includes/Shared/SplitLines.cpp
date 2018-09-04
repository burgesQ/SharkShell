# include			"MobyDick.h"

const std::vector < std::string >	MobyDick::SplitLines(const std::string& line, const char sep)
{
  std::vector < std::string >	vec;
  try {
    std::string			chunk = "";
    for (auto it : line)
      {
	if (it != sep)
	  chunk += it;
	else
	  {
	    if (!chunk.empty())
	      vec.push_back(chunk);
	    chunk.clear();
	  }
      }
    if (!chunk.empty())
      vec.push_back(chunk);
  } catch (SharkException se) {
    std::cerr << se.what() << std::endl;
  }
  return vec;
}

std::string			MobyDick::reformatPath(const std::string& line, const char sep)
{
  std::string			 formatedPath = std::string(1, sep);
  try {
    const std::vector<std::string> pwdPaths = MobyDick::SplitLines(line, sep);
    for (unsigned int i = 0; i < pwdPaths.size(); i++)
      {
	formatedPath += pwdPaths[i];
	if (i < pwdPaths.size() - 1)
	  formatedPath += sep;
      }
  } catch (SharkException se) {
    std::cerr << se.what() << std::endl;
  }
  return formatedPath;
}

bool				MobyDick::startsWith(const std::string& src, const std::string& token)
{
  return src.substr(0, token.length()) == token;
}
