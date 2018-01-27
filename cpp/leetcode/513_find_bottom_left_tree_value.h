
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root)
    {
        int result = INT_MIN;
        int deepestRow = -1;
        preOrderTraversal(root, 0, [&result, &deepestRow](TreeNode* node, int row){
            if (!node) return;
            if (row > deepestRow)
            {
                result = node->val;
                deepestRow = row;
            }
        });
        return result;
    }
    
    void preOrderTraversal(TreeNode* node, int row, function<void(TreeNode* node, int row)> func)
    {
        if (!node) return;
        preOrderTraversal(node->left, row + 1, func);
        func(node, row);
        preOrderTraversal(node->right, row + 1, func);
    }
};



void Test()
{
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->left->left = new TreeNode(4);
    t1->right = new TreeNode(3);
    t1->right->left = new TreeNode(5);
    t1->right->left->left = new TreeNode(7);
    t1->right->right = new TreeNode(6);
    
    TreeNode* t2 = new TreeNode(1);
    
    Solution s;
    auto actual = s.findBottomLeftValue(t1);
    actual = s.findBottomLeftValue(t2);
    
}
