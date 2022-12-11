"""
The Problem:
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import math
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        first = head
        second = head
        while second and second.next:
            first = first.next
            second = second.next.next
        return first
