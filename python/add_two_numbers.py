# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
import math

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        n1 = self.getNumber(l1)
        n2 = self.getNumber(l2)

        sum = n1 + n2
        last_dig = sum % 10
        sum = sum / 10
        curr = ListNode(last_dig)
        head = curr
        while sum != 0:
            dig = sum % 10
            sum /= 10
            curr.next = ListNode(dig)
            curr = curr.next
        return head

    def getNumber(self, l):
        i = 1
        curr = l
        num2 = curr.val
        curr = curr.next
        while curr is not None:
            num2 += int(math.pow(10, i)) * curr.val
            i += 1
            curr = curr.next
        return num2

if __name__ == "__main__":
    l = ListNode(2)
    h1 = l
    l.next = ListNode(4)
    l = l.next
    l.next = ListNode(3)


    l2 = ListNode(5)
    h2 = l2
    l2.next = ListNode(6)
    l2 = l2.next
    l2.next = ListNode(4)
    s = Solution()
    sum = s.addTwoNumbers(h1, h2)
    print sum