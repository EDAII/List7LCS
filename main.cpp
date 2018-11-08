/*
	LCS - longest common subsequence
*/

#include <iostream>
#include <algorithm>
using namespace std;

int length_lcs(string& s1, string& s2) {
	int length_s1 = s1.size(); 
	int length_s2 = s2.size();

	int matrix[length_s1 + 1][length_s2 + 1]; // Matrix

	for(int i = 1; i <= length_s1; i++)
		matrix[i][0] = 0;
	
	for(int i = 0; i <= length_s2; i++)
		matrix[0][i] = 0;

	for(int i = 1; i <= length_s1; i++)	{
		for(int j = 1; j <= length_s2; j++) {
			if(s1[i - 1] == s2[j - 1])
				matrix[i][j] = matrix[i - 1][j - 1] + 1;
			else
				matrix[i][j] = max(matrix[i][j - 1], matrix[i - 1][j]);
		}
	}

	cout << "\nMatrix:\n\n";
	for(int i = 0; i <= length_s1; i++) {
		for(int j = 0; j <= length_s2; j++)
			cout << matrix[i][j] << " ";
		cout << "\n";
	}

	return matrix[length_s1][length_s2];
}

int main(int argc, char **argv){

	string s1("ABCB"), s2("BDCAB");
	int lcs = length_lcs(s1, s2);

	cout << "\nLength: " << lcs << endl;

	return 0;
}