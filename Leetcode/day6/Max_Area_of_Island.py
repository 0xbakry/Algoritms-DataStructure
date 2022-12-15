"""
The Problem:
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.
"""

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
    
        m, n = len(grid), len(grid[0])

        def fill(i, j):
            if 0 <= i < m and 0 <= j < n and grid[i][j]:
                grid[i][j] = 0 
                return 1+ fill(i, j-1) + fill(i, j+1) + fill(i-1, j) + fill(i+1, j)
            return 0 

        areas = [fill(i, j) for i in range(m) for j in range(n) if grid[i][j]]
        
        if areas:
            return max(areas)
        return 0
        
