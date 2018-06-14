/*
	338. Counting Bits

	Description:

	Given a non negative integer number "num".
	For every numbers "i" in the range "0<=i<=num" calculate the number of 1's in their binary representation and return them as an array.
	
	Example:
	For "num = 5" you shoule return [0,1,1,2,1,2].
	
	Follow up:
		1.It is very easy to come up with a solution with run time O(n*sizeof(integer)).But can you do it in linear time O(n)/possibly in a single pass?
		2. Space complexity should be O(n);
		3. Can you do it like a boss?Do it without using any builtin function like _builtin_popcount in C++ or any other language.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int num);

int main(void) {
	vector<int> res;
	int num;
	cin >> num;
	res = countBits(num);
	cout << res << endl;
	return 0;
}

// 从高位分析
vector<int> countBits(int num) {
	vector<int> res(1,0);
	int count = 0;
	while(count < num) {
		int len = res.size();
		for (int i = 0;i<len && count<num; ++i) {
			res.push_back(res[i]+1);
		}
	}
	return res;
}

/*

//从低位分析
vector<int> countBits(int num) {
	vector<int> res(num+1,0);
	for(int i = 1;i <= num; ++i)
		ret[i] = ret[i>>1] + i%2;
	return res;
}

*/