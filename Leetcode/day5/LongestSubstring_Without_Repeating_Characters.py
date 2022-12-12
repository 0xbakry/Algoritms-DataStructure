"""
The Problem:
Longest Substring Without Repeating Characters
"""
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        _max = start = 0
        tmp = {}
        for i in range (0, len(s)):
            if s[i] in tmp and start <= tmp[s[i]]:
                start = tmp[s[i]] + 1
            else:
                _max = max (_max, i-start+1)

            tmp [s[i]] = i

        return _max

