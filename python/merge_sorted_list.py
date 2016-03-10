# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param {ListNode[]} lists
    # @return {ListNode}
    def mergeKLists(self, lists):
        if len(lists) == 0:
            return None

        mergedList = lists.pop()
        while len(lists) > 0:
            secondList = lists.pop()
            self.merge(mergedList, secondList)

        return mergedList

    def merge(self, targetList, fromList):
        # if fromList == None or len(fromList) == 0:
        #     return
        # if targetList == None or len(targetList) == 0:
        #     targetList = fromList

        currentNode = targetList
        while fromList != None:
            firstNodeInFrom = fromList
            fromList = fromList.next
            while currentNode.next != None and currentNode.next.val <= firstNodeInFrom:
                currentNode = currentNode.next

            firstNodeInFrom.next = currentNode.next
            currentNode.next = firstNodeInFrom