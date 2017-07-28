#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/***
 * Use a boolean vector dp[]. dp[i] setted to true if a valid word end at i-1. 
 * for example, s = "leetcode" and dict = {"leet","code"}, the correspond of dp[s.seze()+1] will be {1,0,0,0,1,0,0,0,1}
 **/
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int slen = s.length();
		int size = wordDict.size();
		if (size == 0)
			return false;
		vector<bool> dp(slen + 1, false);
		dp[0] = true;  //(-INF,0) is matched
		for (int i = 1; i < dp.size(); i++)
		{
			for (int j = i - 1; j >= 0; j--)  
			{
				if (dp[j])  //dp[j] = true, mean that [0,j-1) is matched.
				{
					string word = s.substr(j, i - j);
					vector<string>::iterator iter;
					for (iter = wordDict.begin(); iter != wordDict.end(); ++iter)
					{
						if (*iter == word)
							break;
					}
					if (iter != wordDict.end())
					{
						dp[i] = true;
						break;
					}
				}
			}
		}
		return dp[slen];
	}
};

/*
int main()
{
	string s = "leetcode";
	vector<string> vstr;
	vstr.push_back("code");
	vstr.push_back("leet");

	Solution st;
	cout << st.wordBreak(s, vstr) << endl;
	return 0;
}
*/