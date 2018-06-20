/*
	852. Peak Index in a Mountain Array
	
	Description:
	
	Let's call an array "A" a mountain if the following properties hold:
	1. A.length >= 3;
	2. There exits some " 0 < i < A.length - 1 " such that A[0] < A[1] < ... < A[i-1] < A[i]
		> A[i+1] > ... > A[A.length-1].
	
	Given an array that is definitely a mountain,return any "i" such that A[0] < A[1] < ... < A[i-1] < A[i] > A[i+1] > ... > A[A.length-1].
	
	Example 1:
		Input: [0,1,0]
		Output: 1
	
	Example 2:
		Input: [0,2,1,0]
		Output: 1
	
	Note:
		1. 3 <= A.length <= 10000;
		2. 0 <= A[i] <= 10^6
		3. "A" is a mountain,as define above

*/

#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& A);

int main(void) {
	vector<int>	arr;
	int num, i;
	while(cin >> num) {
		arr.push_back(num);
	}
	i = peakIndexInMountainArray(arr);
	cout << i << endl;
	return 0;
}

int peakIndexInMountainArray(vector<int>& A) {
	int maxIndex, temp, size;
	int i = 0;
	maxIndex = i;
	temp = A[i];
	size = A.size();
	while(i < size-1){
		++i;
		if (A[i] > temp) { maxIndex = i; temp = A[i]; }
	}
	return maxIndex;
}