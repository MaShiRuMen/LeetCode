/*
	461. Hamming Distance
	
	Description:
	
	The Hamming Distance between two integers is the number of positions at which the corresponding bits are different.
	Given two integers "x" and "y",calculate the Hamming distance.
	
	Note:
	0 <= x,y < 2^31
	
	Example:
		Input: x = 1, y = 4;
		Output: 2
		
		Explanation
		1	(0 0 0 1)
		4	(0 1 0 0)
			   ↑   ↑
	
	The above arrows point to positions where the corresponding bits are different.
	
*/

#include <iostream>
using namespace std;

#define MAXLEN 101

int hammingDistance(int x,int y);

int main(void) {
	int x, y;
	cin >> x >> y;
	int dis;
	dis = hammingDistance(x,y);
	cout << dis << endl;
	return 0;
}

int hammingDistance(int x,int y) {
	int dis = 0;
	while(x || y) {
		if ( (x&1) != (y&1) ) dis++;	// 从x和y的最低位开始比较；
		x = x >> 1;	//每次比较完后，x右移一位
		y = y >> 1;
	}
	return dis;
}