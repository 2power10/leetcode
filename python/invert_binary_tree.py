# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {TreeNode}
    def invertTree(self, root):
        if root is None:
            return
        root.left = self.invertTree(root.left)
        root.right = self.invertTree(root.right)
        temp = root.left
        root.left = root.right
        root.right = temp
        return root

# def testNoChildren():
#     root = TreeNode(1)
#     sol = Solution()
#     root = sol.invertTree(root)
#     assertEqual(root.left, None)
#     assertEqual(root.right, None)
#     assertEqual(root.val, 1)
#
# def testNormalCase():
#     root = TreeNode(1)
#     n1 = TreeNode(2)
#     n1_1 = TreeNode(3)
#     n1_2 = TreeNode(4)
#     n2 = TreeNode(5)
#     n2_1 = TreeNode(6)
#     n2_2 = TreeNode(7)
#     root.left = n1
#     root.right = n2
#     n1.left = n1_1
#     n1.right = n1_2
#     n2.left = n2_1
#     n2.right = n2_2
#
#     sol = Solution()
#     root = sol.invertTree(root)
#
#     assertEqual(root.left.val, 5)
#     assertEqual(root.right.val, 2)
#     assertEqual(root.left.left.val, 7)
#     assertEqual(root.left.right.val, 6)
#     assertEqual(root.right.left.val, 4)
#     assertEqual(root.right.right.val, 3)
#
# def testHalfNone():
#     root = TreeNode(1)
#     root.left = TreeNode(2)
#     root.left.left = TreeNode(3)
#
#     sol = Solution()
#     root = sol.invertTree(root)
#     assertEqual(root.left, None)
#     assertEqual(root.right.val, 2)
#     assertEqual(root.right.right.val, 3)
#
# def testNone():
#     root = None
#     sol = Solution()
#     root = sol.invertTree(root)
#     assertEqual(root, None)