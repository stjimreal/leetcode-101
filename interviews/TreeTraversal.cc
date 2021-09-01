/*
 * @Date: 2021-08-19 13:38:14
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-19 14:20:41
 */
#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
    TreeNode(int _v): val(_v), left(nullptr), right(nullptr) {}
};

vector<int> preorderTraverse(TreeNode *head) {
    vector<int> res;
    deque<TreeNode *> q;
    while (head != nullptr || !q.empty()) {
        while (head != nullptr) {
            res.push_back(head->val);
            q.push_back(head->right);
            head = head->left;
        }
        head = q.back();
        q.pop_back();
    }

    return res;
}

vector<int> inorderTreverse(TreeNode *head) {
    vector<int> res;
    
    deque<TreeNode *> q;
    while (head != nullptr || !q.empty()) {
        while (head != nullptr) {
            q.push_back(head);
            head = head->left;
        }
        head = q.back();
        res.push_back(head->val);
        q.pop_back();
        head = head->right;
    }

    return res;
}

vector<int> postorderTreverse(TreeNode *head) {
    vector<int> res;
    
    deque<TreeNode *> q;
    while (head != nullptr || !q.empty()) {
        while (head != nullptr) {
            res.push_back(head->val);
            q.push_back(head->left);
            head = head->right;
        }
        head = q.back();
        q.pop_back();
    }

    reverse(res.begin(), res.end());
    return res;
}


int main() {
    TreeNode* head = new TreeNode(6);
    head->left = new TreeNode(4);
    head->right = new TreeNode(8);
    head->left->left = new TreeNode(2);
    head->left->left->left = new TreeNode(1);
    head->left->left->right = new TreeNode(3);
    head->left->right = new TreeNode(5);
    head->right->left = new TreeNode(7);
    head->right->right = new TreeNode(9);
    auto res = postorderTreverse(head);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
}