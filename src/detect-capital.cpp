#include <string>
using namespace std;
class Solution {
public:
	bool detectCapitalUse(string word) {
		int ls = word.size();
		if ('A' <= word[0] && word[0] <= 'Z')
		{
			int i = 1, j = 1;
			for (int k = 1; k < ls; k++)
			{
				if ('A' <= word[k] && word[k] <= 'Z')
					++i;
				if ('a' <= word[k] && word[k] <= 'z')
					++j;
			}
			if (i == ls || j == ls)
				return true;
			else
				return false;
		}
		else
		{
			int m = 1;
			for (int k = 1; k < ls; k++)
			{
				if ('a' <= word[k] && word[k] <= 'z')
				{
					++m;
				}
			}
			if (m == ls)
				return true;
			else
				return false;
		}
	}
};