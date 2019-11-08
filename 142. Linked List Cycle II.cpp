#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
		ListNode *n1 = head, *n2 = head;
		while (n1) {
			n1 = n1->next;
			n2 = n2->next;
			if (!n2 || !n2->next) return NULL;
			n2 = n2->next;
			if (n1 == n2) {
				n1 = head;
				while (n1 != n2) {
					n1 = n1->next;
					n2 = n2->next;
				}
				return n2;
			}
		}
		return NULL;
    }
};
