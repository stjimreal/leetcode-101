/*
 * @Date: 2021-08-25 20:09:47
 * @LastEditors: LIULIJING
 * @LastEditTime: 2021-08-25 20:45:15
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

TreeNode* BSTRebuildRecur(const vector<int> &preorder, const vector<int> &inorder, 
                        int i_pre, int i_in, int len) 
{
    if (len == 1) {
        return new TreeNode(preorder[i_pre]); 
    } else if (len == 0) {
        return nullptr;
    }
    int root_val = preorder[i_pre];
    int j = i_in;
    while (j < len + i_in) {
        if (inorder[j] == root_val)
            break;
        else
            ++j;
    }
    auto head = new TreeNode(root_val);
    head->left = BSTRebuildRecur(preorder, inorder, i_pre + 1, i_in, j - i_in);
    head->right= BSTRebuildRecur(preorder, inorder, 
                            i_pre + 1 + j - i_in, j + 1, len - j + i_in - 1);
    return head;
}

TreeNode* BSTRebuild(const vector<int> &preorder, const vector<int> &inorder) {
    return BSTRebuildRecur(preorder, inorder, 0, 0, preorder.size());
}

void postorderTraverse(TreeNode *node) {
    if (node == nullptr) {
        return;
    }
    postorderTraverse(node->left);
    postorderTraverse(node->right);
    cout<<node->val;
}

int main() {
    // vector preorder = {1,2,4,5,3,6,8};
    // vector inorder =  {4,2,1,6,3,5,8};
    vector preorder = {1,2,3};
    vector inorder = {1,2,3};
    auto head = BSTRebuild(preorder, inorder);
    postorderTraverse(head);
}

/* 
    1
   2  5
  4  3 8
    6
 */