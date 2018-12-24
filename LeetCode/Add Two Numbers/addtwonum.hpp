#include<functional>
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

using std::cin;
auto __ = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		auto func_add = std::bind([&]()->ListNode* {
			ListNode* first_node = new ListNode(0);
			auto it = first_node;
			int sum(0), carry(0);
			while (l1 || l2)
			{
				sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
				if (sum > 9)
				{
					carry = 1;
				}
				else
				{
					carry = 0;
				}
				sum %= 10;
				it->val = sum;
				l1 = l1 ? l1->next : nullptr;
				l2 = l2 ? l2->next : nullptr;

				if (l1 || l2) {
					it->next = new ListNode(0);
					it = it->next;
				}
				else if (carry) {
					it->next = new ListNode(carry);
					it = it->next;
				}

			}
			return first_node;
		});
		return func_add();
	}
};