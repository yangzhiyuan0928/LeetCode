#include <cstdio>
#include <string>
using namespace std;
/***
 * Notice: "a*b" means "ab" or "aaa...ab"
 **/

/***
 * 
 **/
class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty()) 
		{
			if (s.empty())
				return true;
			else
				return false;
		}
		if (p.length() == 1)
		{
			if (s.length() == 1 && ((s[0] == p[0]) || (p[0] == '.')))
				return true;
			else
				return false;
		}
		if (p[1] != '*')
		{
			if (s.empty())
				return false;
			else if (s[0] == p[0] || p[0] == '.')
				return isMatch(s.substr(1), p.substr('.'));
			else
				return false;
		}
		//p[1] == '*'
		while (!s.empty() && (s[0] == p[0] || p[0] == '.'))
		{
			if (isMatch(s, p.substr(2)))  //p[1] == '*'
				return true;
			s = s.substr(1);
		}
		return isMatch(s, p.substr(2));
	}
};