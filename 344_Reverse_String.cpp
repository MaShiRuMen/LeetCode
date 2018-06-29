/*
	344. Reverse String
	Description:
	Write a function that takes a string as input and returns the string reversed.
	
	Example:
	Given s = "hello",return "olleh".
	
*/

class Solution {
public:
    string reverseString(string s) {
        int len = s.length();
		string str = {'\0'};
		int count = 0;
		for (int i = len-1; i >= 0; --i) {
			str[count++] = s[i];
		}
		return str;
    }
};