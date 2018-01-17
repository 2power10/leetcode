
#ifndef merge_two_binary_trees_h
#define merge_two_binary_trees_h

#include <functional>
#include <map>
#include <string>
#include <queue>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        if (t1 == nullptr)  return t2;
        else if (t2 == nullptr) return t1;
        
        map<string, TreeNode*> treeMap;
        TraverseTree(t1, [&treeMap](string tag, TreeNode* node){
            if (node) treeMap[tag] = node;
            return true;
        });
        TraverseTree(t2, [&treeMap](string tag, TreeNode* node)->bool{
            if (!node) return false;
            
            auto result = treeMap.find(tag);
            if (result != treeMap.end())
            {
                (*result).second->val += node->val;
                return true;
            }
            else
            {
                auto parentTag = tag.substr(0, tag.size() - 1);
                auto parent = treeMap[parentTag];
                if (tag[tag.size() - 1] == 'L') parent->left = node;
                else    parent->right = node;
                        
                return false;
            }
        });
        return treeMap["O"];
    }

    void TraverseTree(TreeNode* node, std::function<bool(string, TreeNode*)> func, string tag = "O")
    {
        bool needContinue = func(tag, node);
        if (!needContinue) return;

        if (node)
        {
            TraverseTree(node->left, func, tag+"L");
            TraverseTree(node->right, func, tag+"R");
        }
    }
};

void Test()
{
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(3);
    t1->left->left = new TreeNode(5);
    t1->right = new TreeNode(2);
    
    TreeNode* t2 = new TreeNode(2);
    t2->left = new TreeNode(1);
    t2->left->right = new TreeNode(4);
    t2->right = new TreeNode(3);
    t2->right->right = new TreeNode(7);
    
    Solution s;
    auto newTree = s.mergeTrees(t1, t2);
    
    queue<TreeNode*> q;
    q.push(newTree);
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
