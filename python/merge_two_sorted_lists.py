__author__ = 'yzheng'

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        self.first = None
        curr1 = l1
        curr2 = l2
        curr = None
        while curr1 is not None or curr2 is not None:
            if curr1 is None:
                curr = self.addNext(curr, curr2)
                curr2 = curr2.next
            elif curr2 is None:
                curr = self.addNext(curr, curr1)
                curr1 = curr1.next
            else:
                if curr1.val < curr2.val:
                    curr = self.addNext(curr, curr1)
                    curr1 = curr1.next
                else:
                    curr = self.addNext(curr, curr2)
                    curr2 = curr2.next
        return self.first

    def addNext(self, node, nextNode):
        if node is None:
            self.first = nextNode
            return nextNode
        else:
            node.next = nextNode
            return node.next


