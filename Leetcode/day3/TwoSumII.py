"""
The Problem:
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.
"""

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        size = len(numbers)
  
        for i in range((size-1)):
            new_target = target - numbers[i]
            start = i
            end = size

            while(start < end):
                index = (end+start)//2

                if(new_target == numbers[index]):
                     result = [(i+1), (index+1)]
                     return result

                else:
                    if(new_target > numbers[index]):
                        start = index+1
                    else:
                        end = index
                       
                            
            i+=1
    
