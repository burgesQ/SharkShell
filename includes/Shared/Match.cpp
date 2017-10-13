# include		<ctype.h>
# include		"MobyDick.h"

bool			MobyDick::IsMatchCaseInsensitive(const std::string& s1, const std::string& s2)
{
  const unsigned int	sizeS1 = s1.size();

  if (s2.size() != sizeS1)
    return false;
  for (unsigned int i = 0; i < sizeS1; ++i)
    if (tolower(s1[i]) != tolower(s2[i]))
      return false;
  return true;
}

bool			MobyDick::IsMatchCaseInsensitiveSomeWhere(const std::string& s1, const std::string& s2)
{
  bool stillMatch = false;
  // for (unsigned int i = 0; i < s1.size(); ++i)
  //   {
  //     if (tolower(s1[i]) == tolower(s2[i]))
	
      
		      
  //   }
  return stillMatch;
}

