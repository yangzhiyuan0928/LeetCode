#include <string>
using namespace std;
class Solution {
public:
	int findLUSlength(string a, string b) {
		int lsa = a.size();
		int lsb = b.size();

		if (lsa == lsb)
		{
			int i;
			for (i = 0; i < lsa; i++)
			{
				if (a[i] != b[i])
				{
					return lsa;
				}
			}
			if (i == lsa)
				return -1;
		}

		else
			return lsa > lsb ? lsa : lsb;
	}
};