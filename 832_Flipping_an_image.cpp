/*
	832. Flipping an image
	
	Description:
	
	Given a binary matrix "A",we want to flip the image horizontally,then invert it,and return the resulting image.
	To flip an image horizontally means that each row of the image is reversed.For example,flipping [-1,1,0] horizontally results in [0,1,-1].
	To invert an image means that each "0" is replaced by "1",adn each "1" is replaced by "0".For example,inverting [0,1,1] results in [1,0,0].
	
	Example 1:
		Input: [[1,1,0],[1,0,1],[0,0,0]]
		Output: [[1,0,0],[0,1,0],[1,1,1]]
		Explanation: First reverse each row:[[0,1,1],[1,0,1],[0,0,0]].
		Then,invert the image: [[1,0,0],[0,1,0],[1,1,1]]
		
	Example 2:
		Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
		Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
		Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
		Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
	
	Notes:
		1. 1 <= A.length = A[0].length <= 20
		2. 0 <= A[i][j] <= 1

*/

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
	vector<vector<int>> flip;
	vector<int> temp;
	for (int i=0; i < A.size(); ++i ) {
		for ( int j=A[i].size()-1; j >= 0; --j ) {
			temp.push_back(A[i][j] ^ 1);	//利用逆序进行水平翻转，利用异或进行图像翻转；
		}
		flip.push_back(temp);
		temp.clear();
	}
	return flip;
}