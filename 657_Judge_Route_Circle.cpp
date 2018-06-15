/*
	657. Judge Route Circle
	
	Description:
	
	Initially,there is a Robot at position(0,0).Given a sequence of its moves,judge if this robot make a circle,which means it moves back to the original place.
	
	The move sequence is represented by a string.And each moves is represent bt a character.The valid robot moves are "R"(right),"L"(left),"U"(up) and "D"(down).The output should be true or false representing whether the robot makes a circle.
	
	Example 1:
		Input: "UD"
		Output: true
		
	Example 2:
		Input: "LL"
		Output: false
	
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool judgeCircle (string moves);

int main(void) {
	string moves;
	cin >> moves;
	if(judgeCircle) printf("true");
	else printf("false");
	return 0;
}

bool judgeCircle (string moves) {
	int r_l, u_d, i;	//设置两个变量，r_l用来记录左右移动的范围，u_d用来记录上下移动的范围
	r_l = u_d = 0;
	i = 0;
	while(moves[i] != '\0') {
		switch(moves[i]) {
			case 'U':u_d++;break;
			case 'D':u_d--;break;
			case 'R':r_l++;break;
			case 'L':r_l--;break;
			default:break;
		}
		i++;
	}
	if ( u_d==0 && r_l==0 ) return true;
	else return false;
}