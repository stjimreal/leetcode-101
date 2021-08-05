/*
 * @Date: 2021-07-14 03:12:31
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-07-14 03:46:13
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
private:

public:
  Solution();
  ~Solution();
  ListNode *detectCycle(ListNode *head) {
    auto ptr1 = head, ptr2 = head;
    bool flag = false;
    while (ptr1 && ptr2) {
      ptr2 = ptr2->next;
      if (NULL == ptr2) {
        break;
      }
      ptr2 = ptr2->next;
      ptr1 = ptr1->next;
      if (ptr2 == ptr1) {
        flag = true;
        break;
      }
    }
    if (flag) {
      ptr2 = head;
      while (ptr2 != ptr1) {
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;
      }
      return ptr1;
    } else {
      return NULL;
    }
  }
};

Solution::Solution()
{
}

Solution::~Solution()
{
}

int main()
{
  ListNode* head = new ListNode(3);
  head->next = new ListNode(2);
  head->next->next = new ListNode(0);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = head->next;
  Solution s;
  auto res = s.detectCycle(head);
  printf("%d\n", res->val);
}