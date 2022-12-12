"""
The Problem:
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.
"""

import collections

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2): return False
        
        counter, size = collections.Counter(s1), len(s1)

        for i in range(len(s2)):
            if s2[i] in counter:
                counter[s2[i]]-=1
            
            if i >= size and s2[i-size] in counter:
                counter[s2[i-size]]+=1
            
            if all([counter[i] == 0 for i in counter]): return True
        
        return False
        
