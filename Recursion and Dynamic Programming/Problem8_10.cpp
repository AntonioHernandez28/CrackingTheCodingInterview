#include <iostream>
#include <vector>
using namespace std; 
#define M 8
#define N 8
 

void floodFillUtil(int screen[][N], int x, int y, int prevC, int newC)
{
    if (x < 0 || x >= M || y < 0 || y >= N)
        return;
    if (screen[x][y] != prevC)
        return;
    if (screen[x][y] == newC) 
        return; 
 

    screen[x][y] = newC;
 
    floodFillUtil(screen, x+1, y, prevC, newC);
    floodFillUtil(screen, x-1, y, prevC, newC);
    floodFillUtil(screen, x, y+1, prevC, newC);
    floodFillUtil(screen, x, y-1, prevC, newC);
}

void floodFill(int screen[][N], int x, int y, int newC)
{
    int prevC = screen[x][y];
    floodFillUtil(screen, x, y, prevC, newC);
}
 

int main(){
    /*  Paint Fill: Implement the "paint fill" function that one might see on many image editing programs. That is, given a screen (represented by a two-dimensional array of colors), 
    a point, and a new color, fill in the surrounding area until the color changes from the original color.
    */
}