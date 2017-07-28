#include <cstdio>
#include <vector>
using namespace std;

/***
 * brute force: O(n)
 **/
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int ls = nums.size();
		int i, index;
		for (i = ls - 1; i >= 0; i--)
		{
			if (nums[i] == target)
			{
				index = i;
				break;
			}
		}
		if (i == -1)
			index = -1;
		return index;
	}
};


/***
 * find the pivot & bin-search: O(logn)
 **/
