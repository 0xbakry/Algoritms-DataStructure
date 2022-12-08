"""
The problem:
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

"""

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        
        for i in range(len(nums)):
           nums[i] = pow(nums[i],2) 
        
        nums.sort()
        return nums
