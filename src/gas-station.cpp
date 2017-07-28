#include <cstdio>
#include <vector>
using namespace std;

/***
 * O(n^2): Limit Time Exceeded
 **/
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int gs = gas.size(), cs = cost.size();
		if (gs == 0)
			return -1;
		for (int i = 0; i < gs; i++)
		{
			int j = i;
			int curgas = gas[j];
			while (curgas >= cost[j])
			{
				curgas -= cost[j];
				j = (j + 1) % gs;
				if (j == i)
					return i;
				curgas += gas[j];
			}
		}
		return -1;
	}
};


/***
 * O(n)
 **/
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int gs = gas.size(), cs = cost.size();
		if (gs == 0)
			return -1;
		int sum = 0;   //current reserve
		int total = 0; //total reserve
		int start = 0;
		for (int i = 0; i < gs; i++)
		{
			sum += gas[i] - cost[i];
			total += gas[i] - cost[i];
			if (sum < 0)  //form the start to current, the gas is not enough
			{
				start = i + 1;
				sum = 0;
			}
		}
		if (total < 0)
			return -1;
		else
			return start;
	}
};
