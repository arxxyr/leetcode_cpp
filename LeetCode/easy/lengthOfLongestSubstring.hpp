#include<iostream>
#include<unordered_map>

using std::cin;
using std::unordered_map;
using std::list;
using std::string;

auto __ = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<int, string> max_map;
		int max(0),index(0);
		unordered_map<char, int> exist_map;
		list<char> cache;

		for (auto var : s)
		{
			if (exist_map.count(var))
			{
				cache.clear();
				exist_map.clear();
				index = 0;
			}
			else
			{
				cache.push_back(var);
				exist_map.emplace(var, 1);
				max_map.emplace(index++, var);
			}
		}
		return index;
	}
};