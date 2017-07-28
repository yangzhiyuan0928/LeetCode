#include <string> 
using namespace std;

/***
 * case: -2147483648 -1  Time Limit Exceeded
 ***/

class Solution {
public:
	int divide(int dividend, int divisor) {  // return dividend/divisor
		int64_t end = dividend;
		int64_t sor = divisor;
		if (sor == 0)
			return INT_MAX;
		if (end == 0)
			return 0;
		int flag = 1;
		if (end > 0 && sor < 0 || end < 0 && sor>0)  //tranform positive
		{
			flag = -1;
		}
		if (end < 0)
			end = -end;
		if (sor < 0)
			sor = -sor;

		int64_t res = 0;
		while (end > 0)
		{
			end -= sor;
			if (end >= 0)
				++res;
			if (flag * res < INT_MIN) {
				return INT_MIN;
			}
			if (flag * res > INT_MAX) {
				return INT_MAX;
			}
		}
		return flag * res;
	}
};


class Solution {
public:
	int divide(int dividend, int divisor) {
		int64_t n1 = dividend;
		int64_t n2 = divisor;

		if (n1 == 0) {
			return 0;
		}

		int flag = 1;
		if (n1 < 0) {
			flag = -flag;
			n1 = -n1;
		}
		if (n2 < 0) {
			flag = -flag;
			n2 = -n2;
		}

		int64_t b = 1;
		int64_t d = n2;
		while ((d << 1) <= n1) {
			b <<= 1;
			d <<= 1;
		}

		int64_t res = 0;
		
		while (b > 0) {
			if (n1 >= d) {
				res += b;
				n1 -= d;
			}
			b >>= 1;
			d >>= 1;
		}
				
		if (flag == -1) {
			res = -res;
		}

		if (res < INT_MIN || res > INT_MAX) {
			res = INT_MAX;
		}
		return res;
	}
};

int main()
{
	Solution su;
	su.divide(-2147483648, -1);
	su.divide(-1, -1);
	su.divide(0, -1);
	return 0;
}
