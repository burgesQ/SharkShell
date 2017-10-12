# include			"MobyDick.h"

std::vector <  std::string >	MobyDick::SplitLines(const std::string& line, char sep)
{
  std::vector < std::string >	vec;

  try {
    std::string			chunk = "";
    for (auto it : line)
      if (it != sep)
	chunk += it;
      else
	{
	  vec.push_back(chunk);
	  chunk.clear();
	}
    vec.push_back(chunk);
  } catch (SharkException se) {
    throw new SharkException ("::MobyDick::splitLine::" + se.guessWhat());
  }
  return vec;
}
