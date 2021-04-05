// 5~10分钟想思路
// 第一遍
// 多些思路
// 1. 直接接?

// Definition for singly-linked list.

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr) {
      return l2;
    }
    if (l2 == nullptr) {
      return l1;
    }
    ListNode *c1 = l1;
    int v1 = c1->val;
    ListNode *c2 = l2;
    int v2 = c2->val;
    ListNode *result = l1;
    if (v1 > v2) {
      result = l2;
      c2 = c2->next;
      if (c2 != nullptr) {
        v2 = c2->val;
      }
    } else {
      c1 = c1->next;
      if (c1 != nullptr) {
        v1 = c1->val;
      }
    }
    ListNode *c = result;
    while (c1 != nullptr && c2 != nullptr) {
      v2 = c2->val;
      v1 = c1->val;
      if (v1 > v2) {
        c->next = c2;
        c = c2;
        c2 = c2->next;
      } else {
        c->next = c1;
        c = c1;
        c1 = c1->next;
      }
    }
    if (c1 != nullptr) {
      c->next = c1;
    }
    if (c2 != nullptr) {
      c->next = c2;
    }
    return result;
  }
};