"""
The Problem:
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.
"""

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
       
        if image[sr][sc] == color: return image
         
        m, n= len(image), len(image[0]) 
        old_color = image[sr][sc]
       
        def fill(r, c):
           if 0 <= r < m and 0 <= c < n and image[r][c] == old_color:
               image[r][c] = color
               fill(r+1, c)
               fill(r-1, c)
               fill(r, c+1)
               fill(r, c-1)
        
        fill(sr, sc)
        return image

