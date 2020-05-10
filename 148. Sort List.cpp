#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        // merge sort
        ListNode* fast = head;
        ListNode* mid = head;
        while (true) {
            if (!fast->next) break;
            fast = fast->next;
            if (!fast->next) break;
            mid = mid->next;
            fast = fast->next;
        }
        // now mid is the first mid
        ListNode* tmp = mid->next;
        mid->next = NULL;
        head = sortList(head);
        mid = sortList(tmp);
        // merge
        if (!head) return mid;
        if (!mid) return head;
        ListNode* resHead, *restmp;
        if (head->val < mid->val) {
            resHead = head;
            restmp = resHead;
            head = head->next;
        }
        else {
            resHead = mid;
            restmp = resHead;
            mid = mid->next;
        }
        while (head && mid) {
            if (head->val < mid->val) {
                restmp->next = head;
                restmp = restmp->next;
                head = head->next;
            }
            else {
                restmp->next = mid;
                restmp = restmp->next;
                mid = mid->next;
            }
        }
        if (!head) restmp->next = mid;
        else if (!mid) restmp->next = head;
        return resHead;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line="[4,5,2,7,1]";
    ListNode* head = stringToListNode(line);
    ListNode* ret = Solution().sortList(head);
    string out = listNodeToString(ret);
    cout << out << endl;
    return 0;
}
