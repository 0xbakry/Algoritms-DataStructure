"""
The Problem:
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.
"""

class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        i, last = 0, len(s)-1

        while (i<last):
            s[i], s[last] = s[last], s[i]
            i+=1
            last-=1
