/*
 * @Date: 2021-08-09 15:10:21
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-09 17:44:22
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int v): val(v), next(nullptr) {}
};
/* 2->1->3->4->5->null */
/* 1->2       1->4, 3->2
   head->3    head->3
*/
/*  */
ListNode* inverseLinkListRecur(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    auto node = inverseLinkListRecur(head->next);
    head->next->next = head;
    head->next = nullptr;
    return node;
}

ListNode* inverseLinkList(ListNode* head) {
    for (auto ptr = head; ptr->next != nullptr; swap(head->next, ptr->next))
        swap(ptr->next, head);
    return head;
}


int main(int argc, char const *argv[])
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    auto res = inverseLinkListRecur(head);
    while (res) {
        printf("%d ", res->val);
        res = res->next;
    }
    printf("\n");
    return 0;
}

