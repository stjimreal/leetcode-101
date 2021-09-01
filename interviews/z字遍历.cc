/*
 * @Date: 2021-08-09 14:43:49
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-09 15:08:16
 */

#include <iostream>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

/* 注意 z字遍历取的时候事实上可以一层一层取 */

vector<int> zTraverse(TreeNode *tree) {
    vector<int> res;
    bool flag = true;
    deque<TreeNode *> q;
    q.push_back(tree);
    while (!q.empty()) {
        auto len = q.size();
        while(len--) {
            TreeNode* node;
            if (flag) {
                node = q.front();
                q.pop_front();
            } else {
                node = q.back();
                q.pop_back();
            }
            res.push_back(node->val);
            if (node->left) q.push_back(node->left);
            if (node->right) q.push_back(node->right);
        }
        flag = !flag;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);
    head->left->left->left = new TreeNode(7);
    head->left->left->right = new TreeNode(8);
    head->left->right->left = new TreeNode(12);
    head->left->right->right = nullptr;
    auto res = zTraverse(head);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
    return 0;
}

