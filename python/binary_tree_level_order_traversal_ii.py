# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        currQueue = [root]
        nextQueue = []
        result = []
        while len(currQueue) > 0:
            lvlNode = []
            for node in currQueue:
                if node != None:
                    lvlNode.append(node.val)
                    nextQueue.append(node)
            if len(lvlNode) > 0:
                result.insert(0, lvlNode)
            currQueue = nextQueue
            nextQueue = []
        return result