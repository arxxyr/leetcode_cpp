#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <iostream>
#include<unordered_map>

/*
Sets whether the standard C++ streams are synchronized to the standard C streams after each input/output operation.
*/
int x = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);
	return 0;
}();

class LRUCache {
public:
	LRUCache(int capacity) :capacity_(capacity) {}

	int get(int key) {
		auto it = pos_.find(key);
		// if not exists
		if (it == pos_.end())
		{
			return -1;
		}
		// if exists 
		// move it
		else
		{
			cache_.erase(it->second);
			cache_.push_front({ it->second->first,it->second->second });
			pos_[key] = cache_.begin();
			return it->second->second;
		}
	}

	void put(int key, int value) {
		auto it = pos_.find(key);
		if (it != pos_.end())
		{
			cache_.erase(it->second);
		}

		else if (cache_.size() >= capacity_)
		{
			pos_.erase(cache_.back().first);
			cache_.pop_back();
		}
		cache_.push_front({ key,value });
		pos_[key] = cache_.begin();
	}

private:
	int capacity_;
	std::list<std::pair<int, int>> cache_;
	std::unordered_map<int, std::list<std::pair<int, int>>::iterator> pos_;
};

/* fast in leetcode

int x = []() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	return 0;
}();
class LRUCache {
using MYLIST = list<pair<int,int>>;
using MYIT = MYLIST::iterator;
using MYLOOKUP = unordered_map<int,MYIT>;
private:
	MYLIST _list;
	MYLOOKUP _lookup;
	int _count;
	int _capacity;
public:
	LRUCache(int capacity) {
		_capacity = capacity;
	}

	int get(int key) {
	   if(_lookup.count(key)){
			MYIT it = _lookup[key];
			//cout<<key<<" "<<it->first<<" "<<it->second;
			_list.erase(it);
			_list.push_front({it->first,it->second});
			_lookup[key] = _list.begin();

			return it->second;
		}else return -1;
	}

	void put(int key, int value) {
		// Exist
		if(_lookup.count(key)){
			MYIT it = _lookup[key];
			_list.erase(it);
		// Full
		}else if(_list.size()==_capacity){
			_lookup.erase(_list.back().first);
			_list.pop_back();
		}
		// Update
		_list.push_front({key,value});
		_lookup[key] = _list.begin();
	}

};

*/


#endif // !LRUCACHE_H
