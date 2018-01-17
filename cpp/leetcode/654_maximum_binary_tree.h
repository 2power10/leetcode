#ifndef maximum_binary_tree_h
#define maximum_binary_tree_h

#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        if (nums.empty())   return nullptr;
        TreeNode *root = new TreeNode(nums[0]);
        for (int i = 1; i < nums.size(); i ++)
        {
            InsertToTree(root, nums[i]);
        }
        return root;
    }

    void InsertToTree(TreeNode *&root, int value)
    {
        if (root->val < value)
        {
            TreeNode *newRoot = new TreeNode(value);
            newRoot->left = root;
            root = newRoot;
        }
        else
        {
            InsertToRightNode(root, value);
        }
    }

    void InsertToRightNode(TreeNode *&parentNode, int value)
    {
        if (!parentNode->right)
        {
            parentNode->right = new TreeNode(value);
        }
        else if (parentNode->right->val > value)
        {
            InsertToRightNode(parentNode->right, value);
        }
        else
        {
            TreeNode *newNode = new TreeNode(value);
            newNode->left = parentNode->right;
            parentNode->right = newNode;
        }
    }
};


void Test()
{
    Solution s;
//    vector<int> tc1{5,4,3,50,8,9};
    vector<int> tc1{3,2,1,6,0,5};
    auto root = s.constructMaximumBinaryTree(tc1);
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        auto f = q.front();
        q.pop();
        if (!f) continue;
        cout << "val " << f->val << " ; left = "
             << (f->left == nullptr ? -1 : f->left->val) << " ; right = "
             << (f->right == nullptr ? -1 : f->right->val) << '\n';
        q.push(f->left);
        q.push(f->right);
    }
}

#endif
