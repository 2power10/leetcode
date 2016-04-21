# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        curr = head
        newHead = None

        while curr != None:
            head = head.next

            curr.next = newHead
            newHead = curr
            curr = head

        return newHead

