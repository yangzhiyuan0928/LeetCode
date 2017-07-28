#include <string>
using namespace std;

#include <cctype>
#include <climits>
#include <cstdint>

class Solution {
public:
	int myAtoi(string str) {
		const int R = 10;

		int len = str.size();
		int64_t res = 0;
		int i = 0;
		while (i < len && str[i] == ' ') {  /* ommit the space & Tab */
			++i;
		}
		if (i >= len) {
			return res;
		}

		int sign = 1;  /* check the '+' '-' or number */
		if (str[i] == '+') {
			sign = 1;
			++i;
		}
		else if (str[i] == '-') {
			sign = -1;
			++i;
		}
		while (i < len) {
			if (!isdigit(str[i])) {
				return sign * res;
			}
			res = res * R + (str[i] - '0');
			if (sign * res < INT_MIN) {
				return INT_MIN;
			}
			if (sign * res > INT_MAX) {
				return INT_MAX;
			}
			++i;
		}
		return sign * res;
	}
};

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
/*
int main()
{
	string str = "  abc-123+567cd";
	Solution su;
	unsigned int res = su.myAtoi(str);

	cout << res << endl;
	cout << atoi(str.c_str()) << endl;

	return 0;
}
*/