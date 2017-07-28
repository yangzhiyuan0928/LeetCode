#include <string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		int len = s.length();
		int m = numRows;
		if (m <= 1)
			return s;

		int row;
		string res = "";
		for (int i = 0; i < len; i += 2 * m - 2)//row == 0
			res.push_back(s[i]);
			
		for (row = 1; row < m - 1; ++row)  //row == 1 ~ numRows-2
		{
			for (int i = 0; i < len; i += 2*m-2)
			{
				if (row + i < len)
				{
					res.push_back(s[i + row]);
				}
				if (i + 2 * m - 2 - row < len)
				{	
					res.push_back(s[i + 2 * m - 2 - row]);
				}
			}
		}

		for (int i = m - 1; i < len; i += 2*m-2)  //row == numRows-1
		{
			res.push_back(s[i]);
		}

		return res;
	}
};