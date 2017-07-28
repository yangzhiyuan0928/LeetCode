#include <string>
#include <vector>
#include <iostream>
using namespace std;

/***
 * 暴力遍历，将回文串及长度保存在map中，输出最大map.value对应的回文串
 */
//实现：略

/***
 * (Manacher Algorithm): A clever application of DP. O(n)
 **/ 
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() < 2) {
			return s;
		}
		string str = fillChars(s);
		vector<int> p(str.size(),1);  //p[i] is the position i palindroic substring length.
		int id = 0, mx = 0; //id is the center position of longest palindroic substring, mx is the correspond right edge ,and mx - id + 1 = p[id], they are all index.
		int i;
		for(i=1;i<str.size();i++)  //the key of Manacher
		{
			if(mx + 1 > i)
			{
				p[i] = min(p[2*id-i],mx-i+1);
			}
			else
			{
				p[i] = 1;
			}
			while(i-p[i] >= 0 && i+p[i] < str.size() && str[i-p[i]] == str[i+p[i]])  // 
			{
				p[i] = p[i] + 1;
			}
			if(i+p[i]-1 > mx)
			{
				mx = i+p[i]-1;
				id = i;
			}
		}

		int max = 0, index;
		for(int i=0;i<str.size();i++)
		{
			if(p[i] > max)
			{
				index = i;
				max = p[i];
			}
		}
		
		int start = index - max + 1;
		int end = index + max - 1;
		string res;
		for(int i=start;i<=end;i++)
		{
			if(str[i] != '#')
			{
				res.push_back(str[i]);
			}
		}
		
		return res;
	}
private:
	static const char UNUSED_CHAR_HEAD = '$';
	static const char UNUSED_CHAR = '#';

	// Fill the string with unused chars, 
	// so that every palindromic substring has odd length.
	string fillChars(string s) {
		string res;
		int ls = s.size();

		int i;
		res.push_back(UNUSED_CHAR_HEAD);
		res.push_back(UNUSED_CHAR);
		for (i = 0; i < ls; ++i) {
			res.push_back(s[i]);
			res.push_back(UNUSED_CHAR);
		}
		return res;
	}
};

int main()
{
	string s;
	getline(cin,s);
	Solution su;
	cout << su.longestPalindrome(s) << endl;
	return 0;
}

