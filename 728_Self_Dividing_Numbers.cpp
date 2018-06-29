/*
	728. Self Dividing Numbers
	Description:
	A self-dividing number is a number that is divisible by every digit it contains.
	For example,128 is a self-dividing number because "128 % 1 == 0, 128 % 2 == 0, 128 % 8 == 0".
	Also,a self-dividing number is not allowed to contain the digit zero.
	Given a lower and upper number bound,output a list of every possible self dividing number,including the bounds if possible.
	
	Example 1:
	Input : left = 1,right = 22
	output : [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
	
	Note:
	The boundaries of each input argument are "1 <= left <= right <= 10000".
	
*/

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> dividing_nums;
		int num;
		num = left;
		while ( num <= right ) {
			if ( judgeDividingNumbers(num) ) dividing_nums.push_back(num);
			num++;
		}
		return dividing_nums;
    }
	int judgeDividingNumbers(int num) {
		char str[5] = {'\0'};
		sprintf(str,"%d",num);	// 将数字转换为字符串；
		int i = 0;
		int flag = 1;
		while ( str[i] != '\0' ) {
			int temp = int(str[i] - '0');	// 将每个字符转换成对应的数字
			if ( temp == 0 ) { flag = 0; break; }
			if ( num % temp != 0 ) { flag = 0; break; }
			i++;
		}
		return flag;
	}
};