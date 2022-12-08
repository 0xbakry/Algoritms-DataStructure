"""
The problem:
Given an array, rotate the array to the right by k steps, where k is non-negative.

"""

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        """
        ### O (n) ==> Where n is the list size. ###
        """
        
        if k > len(nums): k -= len(nums)
        nums.reverse()
        nums[k:] = reversed(nums[k:])
        nums[:k] = reversed(nums[:k])
      
         """
         ### O(k*n) ==> Where n is the list size. ###
         
        while(i<k):
            tmp = nums[size-1]
            for i in range(len(nums)-1, -1, -1):
                nums[i] = nums[i-1]
            nums[0] = tmp
            i=i+1
         """
