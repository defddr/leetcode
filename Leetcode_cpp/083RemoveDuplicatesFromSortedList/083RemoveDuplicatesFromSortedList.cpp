// 083RemoveDuplicatesFromSortedList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <set>

using namespace std;

//直接遍历  或者转化set

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* p = head;
		if (p == NULL)
			return NULL;
		set<int> s;
		while (p != NULL) {
			s.insert(p->val);
			p = p->next;
		}
		p = head;
		set<int>::iterator it = s.begin();
		while (it != s.end()) {
			p->val = *it;
			if (++it == s.end()) {
				p->next = NULL;
				break;
			}
			else {
				p = p->next;
			}
		}


		return head;
	}
};


int main()
{
    std::cout << "Hello World!\n"; 
}
