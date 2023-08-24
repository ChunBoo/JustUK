/**
 * An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, “flood fill” the image.

To perform a “flood fill”, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:

1
2
3
4
5
6
7
8
9
Input:
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation:
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

 

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
*/


/*
class Solution {
private:
    void fillImage(vector<vector<int>>& image,int x,int y,int m,int n,int oriColor,int newColor)
    {
        if(x<0||y<0||x>=m||y>=n) return;
        if(oriColor!=newColor) return;
        image[x][y]=newColor;
        fillImage(image,x-1,y,m,n,oriColor,newColor);
        fillImage(image,x+1,y,m,n,oriColor,newColor);
        fillImage(image,x,y-1,m,n,oriColor,newColor);
        fillImage(image,x,y+1,m,n,oriColor,newColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        int R=image.size();
        int C=image[0].size();

        fillImage(image,sr,sc,R,C,image[sr][sc],color);
        return image;
    }
};
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, 
                                  int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        int m = image.size();        
        int n = image[0].size();        
        floodFill(image, sc, sr, n, m, image[sr][sc], newColor);
        return image;
    }
private:
    void floodFill(vector<vector<int>>& image, 
                   int x, int y, int n, int m, int orgColor, int newColor) {
        if (x < 0 || x >= n || y < 0 || y >= m) return;
        if (image[y][x] != orgColor) return;
        
        image[y][x] = newColor;
        floodFill(image, x + 1, y, n, m, orgColor, newColor);
        floodFill(image, x - 1, y, n, m, orgColor, newColor);
        floodFill(image, x, y + 1, n, m, orgColor, newColor);
        floodFill(image, x, y - 1, n, m, orgColor, newColor);
    }
};