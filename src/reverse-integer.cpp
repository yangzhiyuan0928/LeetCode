#include <string>

#include <climits>
#include <vector>
using namespace std;
class Solution {
public:
	int reverse(int x) {
		if (x <= INT_MIN)
			return 0;
		const int R = 10;
		vector<int> res;
		bool isneg = false;
		if (x < 0)
		{
			x = -x;
			isneg = true;
		}
		while (x / R)
		{
			res.push_back(x % 10);
			x /= R;
		}
		res.push_back(x);
		int64_t ret = 0;
		for (int i = 0; i < res.size(); i++)
		{
			ret = ret * 10 + res[i];
			if (ret > INT_MAX)
				return 0;
		}
		if (isneg)
			ret = -ret;
		return ret;
	}
};