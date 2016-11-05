__author__ = 'yzheng'
from remove_linked_list_elements import *
import sys


def assertEqual(actual, expected):
    print "actual {0} expected {1}".format(actual, expected)
    if actual == expected:
        print "success"
    else:
        print "failed"

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

def test():
    s = Solution()
    list = [3,3,3,1,2,3,4,3,3,3,3,33,5]

    prev = None
    for i in list:
        if prev == None:
            head = ListNode(i)
            prev = head
        else:
            prev.next = ListNode(i)
            prev = prev.next

    head = s.removeElements(head,3)

    curr = head
    while curr != None:
        print(str(curr.val) + " - ")
        curr = curr.next


def genList(list):
    list.reverse()
    first = ListNode(list.pop())
    curr = first
    while len(list) > 0:
        curr.next = ListNode(list.pop())
        curr = curr.next
    return first

if __name__ == "__main__":
    test()
