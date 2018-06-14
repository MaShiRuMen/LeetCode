/*
	807. Max Increase to Keep City Skyline
	
	Description:
	
	In a 2 dimensional array "gird",each value "grid[i][j]" represents the height of building located there.
	We are allowed to increase the height of any number of buildings,
	by any amount(the amounts can be different for different buildings).
	Height 0 is considered to be a building as well.
	
	At the end,the "skyline" when viewed from all four directions of the grid,
	i.e. top,bottom,left,and right,
	must be the same as the skyline of the original grid.
	A city's skyline is the outer contour of the rectangles formed by all the buildings when viewed from a distance.
	See the following example.
	
	What is the maximum total sum that the height of the buildings can be increased?
	
	Example:
	Input : grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
	Output : 35
	Explanation:
	The grid is : [[3,0,8,4],
				   [2,4,5,7],
				   [9,2,6,3],
				   [0,3,1,0]]
	The skyline viewed from top or bottom is : [9,4,8,7]
	The skyline viewed from left or right is : [8,7,9,3]
	
	The grid after increasing the height of buildings without affecting skyline is:
	
	gridNew = [[8,4,8,7],
			   [7,4,7,7],
			   [9,4,8,7],
			   [3,3,3,3]]
			   
	Notes:
		1 < grid.length = grid[0].length <= 50
		All heights grid[i][j] are in the range [0,100]
		All buildings in grid[i][j] occupy the entire grid cell:that is,they are a 1*1*grid[i][j] rectangular prism.
*/

#include <iostream>
#include <vector>
using namespace std;

int maxIncreaseKeepingSkyline(vector<vector<int>>& grid);
void SetMax(int &n,int m);
int GetMin(int n,int m);

int main(void) {
	vector(vector<int>) grid = {{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};
	int sum = maxIncreaseKeepingSkyline(grid);
	cout << sum;
	return 0;
}

int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
	if (grid.size() == 0) {
		return 0;
	}
	int sum, i, j;
	sum	= 0;	i = j = 0;
	int len;
	len = grid.size();
	vector<int> row_max(len, 0);
	vector<int> col_max(len, 0);
	
	for (i = 0; i < len; ++i) {
		for (j = 0; j < len; ++j) {
			SetMax(row_max[i], grid[i][j]);
		}
	}
	for (i = 0; i < len; ++i) {
		for (j = 0; j < len; ++j) {
			SetMax(col_max[i], grid[j][i]);
		}
	 }
	for (i = 0;i < len; ++i) {
		for (j = 0;j < len; ++j) {
			sum += GetMin(row_max[i],col_max[j]) - grid[i][j];
		}
	}
	return sum;
}

void SetMax(int &n,int m) {
	if (n < m) n = m;
}

int GetMin(int n,int m) {
	if(n < m) return n;
	else return m;
}