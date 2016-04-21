# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        curr = head
        lastDiffNode = head
        while curr is not None:
            if lastDiffNode.val != curr.val:
                lastDiffNode.next = curr
                lastDiffNode = curr

            curr = curr.next
        if lastDiffNode is not None:
            lastDiffNode.next = None
        return head