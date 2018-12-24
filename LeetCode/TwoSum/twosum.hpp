#include<vector>
#include<unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> solution(2, 0);
		unordered_map<int, int> hash;
		auto end = hash.end();
		for (int i = 0; i < nums.size(); i++)
		{
			auto find = hash.find(target - nums[i]);

			if (find == end)
			{
				hash.emplace(nums[i], i);
			}
			else
			{
				solution = { find->second,i };
				return solution;
			}
		}
	}
};
