"""
The Problem:
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
"""
class Solution:
    def reverseWords(self, s: str) -> str:
        result = s.split()
       
        for i in range(len(result)):
           result[i] = result[i][::-1]

        final = " ".join(result)
        return final
