/*
	804. Unique Morse Code Words
	
	Description:
	International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes,as follows:"a" maps to ".-","b" maps to "-...","c" maps to "-.-.",and so on.
	
	For convenience,the full table for the 26 letters of the English alphabet is given below:
	[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
	
	Now,given a list of words,each word can be written as a concatenation of the Morse code of each letter.For example,"cab" can be written as "-.-.-....-",(which is the concatenation "-.-."+"-..."+".-").We'll call such a concatenation,the transformation of a word.
	
	Return the number of different transformations among all words we have.
	
	Example:
	Input: words = ["gin","zen","gig","msg"]
	Output: 2
	Explanation:
		The transformation of each word is:
		"gin" -> "--...-."
		"zen" -> "--...-."
		"gig" -> "--...--."
		"msg" -> "--...--."
	
	There are 2 different transformations,"--...-." and "--...--.".

*/

class Solution {
	public:
		int uniqueMorseRepresentations(vector<string>& words) {
			string morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
			set<string> res;	// 设置一个string集合；
			for ( int i = 0; i < words.size(); ++i ) {
				string tmp = "";
				string cur = words[i];
				for( int j = 0; j < cur.length(); ++j ) {
					tmp += morse[cur[j] - 'a'];	// 将字母字符串转换为摩斯电码字符串
				}
				res.insert(tmp);	//调用set的insert方法实现无重的插入
			}
			return res.size();	
		}
};