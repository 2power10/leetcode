# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param {ListNode} node
    # @return {void} Do not return anything, modify node in-place instead.
    def deleteNode(self, node):
        if node.next == None:
            node = None
            return
        nextNode = node.next

        node.val = nextNode.val
        node.next = nextNode.next
        nextNode.next = None

#Test case

def printList(node):
    print "print list"
    while(node != None):
        print node.val
        node = node.next

def testNormal():
    node1 = ListNode(1)
    node2 = ListNode(2)
    node3 = ListNode(3)
    node4 = ListNode(4)
    node1.next = node2
    node2.next = node3
    node3.next = node4
    s = Solution()
    printList(node1)
    s.deleteNode(node3)
    printList(node1)

def testDeleteLast():
    node1 = ListNode(1)
    node2 = ListNode(2)
    node3 = ListNode(3)
    node1.next = node2
    node2.next = node3
    s = Solution()

    printList(node1)
    s.deleteNode(node3)
    printList(node1)

def testDeleteFirst():
    node1 = ListNode(1)
    node2 = ListNode(2)
    node3 = ListNode(3)
    node1.next = node2
    node2.next = node3
    s = Solution()
    printList(node1)
    s.deleteNode(node1)
    printList(node1)