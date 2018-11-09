/*
	LCS - longest common subsequence
*/

#include <iostream>
#include <algorithm>
#include <ctime>
#include <time.h>

using namespace std;

char vowels[8] = {'A','B','C','D','E','F'};

int length_lcs(string& s1, string& s2) {
	clock_t begin = clock();

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

	cout << "\033[1;31m\nLCS Matrix\n\033[0m\n";
	
	for(int i = 0; i <= length_s1; i++) {
		for(int j = 0; j <= length_s2; j++)
			cout << matrix[i][j] << " ";
		cout << "\n";
	}

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << endl << "Time spent: " << elapsed_secs << endl;
	cout << "S1: " << s1 << endl;
	cout << "S2: " << s2 << endl;
	return matrix[length_s1][length_s2];
}

int main(int argc, char **argv) {

	string s1("GAC");
	string s2("AGCAT");
	
	int lcs = length_lcs(s1, s2);
	cout << "Length: " << lcs << endl << endl << endl;

	return 0;
}