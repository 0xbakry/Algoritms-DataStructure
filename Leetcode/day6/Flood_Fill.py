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

    
###################################################################################################################################
###################################################################################################################################
###################################################################################################################################
"""

Another sol. with less time:

"""

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
       
        if image[sr][sc] == color: return image

        m, n= len(image), len(image[0])
        old_color = image[sr][sc]
        result = image.copy()

        queue = []
        queue.append([sr, sc])
        result[sr][sc] = color

        while queue:
            current = queue.pop()
            sr_pos = current [0]
            sc_pos = current [1]

            if (sr_pos+1) < m and image[sr_pos+1][sc_pos] == old_color:
                result[sr_pos+1][sc_pos] = color
                queue.append([sr_pos+1, sc_pos])   
                
                print ("old: ", old_color)
                print ("new: ", color)
                
            if (sr_pos-1) >= 0 and image[sr_pos-1][sc_pos] == old_color:

                result[sr_pos-1][sc_pos] = color
                queue.append([sr_pos-1, sc_pos])                

            if (sc_pos+1) < n and image[sr_pos][sc_pos+1] == old_color:

                result[sr_pos][sc_pos+1] = color
                queue.append([sr_pos, sc_pos+1])     
                   
            if (sc_pos-1) >= 0 and image[sr_pos][sc_pos-1] == old_color:

                result[sr_pos][sc_pos-1] = color
                queue.append([sr_pos, sc_pos-1])     
        
        return result

