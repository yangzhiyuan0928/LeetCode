// two sum.cpp : 定义控制台应用程序的入口点。

#include <vector>  //O(n^2)
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int>::iterator itrp, itrn;  
		int i = 0, j;

		vector<int> index;
		for(itrp=nums.begin();itrp!=nums.end();itrp++,i++)
		{
			for(itrn=nums.end()-1,j=nums.size()-1;itrn!=itrp;itrn--,j--)
			{
				if(*itrp + *itrn == target)
				{
					index.push_back(i);
					index.push_back(j);
				}
			}
		}
		return index;
	}
};


#include <unordered_map>
using std::unordered_map;

class Solution {  //key对应nums[i], value对应index
public:
	vector<int> twoSum(vector<int>& nums, int target) {  //O(n)
		unordered_map<int, int> um;
		int n = nums.size();
		int i;
		vector<int> res(2);
		for (i = 0; i < n; ++i) {
			if (um.find(target - nums[i]) != um.end()) {
				res[0] = um[target - nums[i]];
				res[1] = i;
				break;
			} else {
				um[nums[i]] = i;
			}
		}
		um.clear();
		return res;
	}
};
