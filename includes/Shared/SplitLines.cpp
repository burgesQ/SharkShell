# include			"MobyDick.h"

std::vector <  std::string >	MobyDick::SplitLines(const std::string& line, char sep)
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
    throw new SharkException ("::splitLine::" + se.guessWhat());
  }
  return vec;
}

std::string			MobyDick::reformatPath(const std::string& line, char sep)
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
    throw new SharkException ("::reformatPath::" + se.guessWhat());
  }
  return formatedPath;
}
