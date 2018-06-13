/*
771. Jewels and Stones

Description:

You're given strings "J" representing the types of stones that are jewels,
and "S" representing the stones you have.
Each character in "S" is type of stone you have.
You want to know how many of the stones you have are also jewels.

The letter in "J" are guaranteed distinct,
and all characters in "J" and "S" are letters.
Letters are case sensitive.
So "a" is considered a different type of stone from "A".


Example 1:
	Input : J = "aA", S = "aAAbbbb"
	Output : 3
	
Example 2:
	Input : J = "z", S = "ZZ"
	Output : 0
	
*/

#include <iostream>
#include <cstring>
using namespace std;

int numJewelsInStones(string J, string S) {	// This function is to judge how many stones you have is jewels
	int count, p1, p2; 
	char c;
	count = 0;
	p1 = 0;
	c = J[p1];
	while(c != '\0') {	//search J[p1] in S one by one;
		p2 = 0;
		while(S[p2] != '\0') {
			if(c == S[p2]) count++;
			p2++;
		}
		p1++;
		c = J[p1];
	}
	return count;
}

int main(void) {
	string J, S;
	cin >> J >> S;
	cout << numJewelsInStones(J,S) << endl;
	return 0;
}
