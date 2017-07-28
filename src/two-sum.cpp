// two sum.cpp : �������̨Ӧ�ó������ڵ㡣

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

class Solution {  //key��Ӧnums[i], value��Ӧindex
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
