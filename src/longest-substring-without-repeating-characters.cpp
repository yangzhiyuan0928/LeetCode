#include <string>
#include <iostream>
using namespace std;

#include <map>
using std::max;
class Solution {  
public:
	int lengthOfLongestSubstring(string s) {
		map<char,int> mapstr;
		int start = -1, maxlen = 0;
		for(int i=0;i<s.length();i++)
		{
			if(mapstr.count(s[i])>0)
				start = max(start, mapstr[s[i]]); //delete the dispared substring
			mapstr[s[i]] = i;
			maxlen = max(maxlen, i-start);
		}
		return maxlen;
	}
};
