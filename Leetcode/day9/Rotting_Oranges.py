"""
The Problem:
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

"""

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n, m, res= len(grid), len(grid[0]), 0
        #get_in = False

        queue = collections.deque([])
        count = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1: count += 1
                if grid[i][j] == 2: queue.append((i,j))
    
        while queue:
            for _ in range(len(queue)):
                i,j = queue.popleft()
                for x, y in [(i+1,j), (i-1,j), (i,j+1), (i,j-1)]:
                    if 0<=x<n and 0<=y<m and grid[x][y] == 1:
                        grid[x][y] = 2
                        count -= 1
                        queue.append((x,y))
            res += 1
        return max(0, res-1) if count == 0 else -1


      ##### NEED TO HANDLE SOME CASES ####
        """
        for  i in range (m):
            for j in range (n):
                empty = 0

                if grid [i][j] == 1:
                    if i > 0:
                        if grid[i-1][j] == 0: empty +=1
                    else: empty +=1

                    if i < m-1:
                        if grid[i+1][j] == 0: empty +=1
                    else: empty +=1

                    if j > 0:
                        if grid[i][j-1] == 0: empty +=1
                    else: empty +=1

                    if j < n-1:
                        if grid[i][j+1] == 0: empty +=1
                    else: empty +=1
                if empty == 4:
                    return -1

                else: 
                    if grid[i][j] == 2:
                        if i < m-1:
                            if grid[i+1][j] == 1: 
                                grid[i+1][j] =2
                                get_in = True
                        if j < n-1:
                            if grid[i][j+1] == 1: 
                                grid[i][j+1] =2
                                get_in = True
                    if get_in: 
                        mini +=1 
                        get_in = False
                                   
        return mini   
        """
