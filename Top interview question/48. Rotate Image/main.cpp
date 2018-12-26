#include <iostream>
#include <vector>

using namespace std;


//My answer
/*
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int Num = matrix.size();
		int Count = 0;
		while (Count <= Num/2)
		{
			vector<int> Temp = matrix[Count];
			for (size_t i = Count; i < Num - Count - 1; ++i)
			{
				matrix[Count][i] = matrix[Num - i - 1][Count];
				matrix[Num - i - 1][Count] = matrix[Num - Count - 1][Num - i - 1];
				matrix[Num - Count - 1][Num - i - 1] = matrix[i][Num - Count - 1];
				matrix[i][Num - Count - 1] = Temp[i];
			}
			++Count;
		}
	}
};*/
//better answer :先水平翻转，再沿主对角翻转  or 先沿副对角翻转，再水平翻转。实质：另matrix[i][j] = matrix[j][n-i-1]
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		reverse(matrix.begin(), matrix.end());
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int k = i + 1; k < matrix.size(); ++k)
			{
				swap(matrix[i][k], matrix[k][i]);
			}
		}
	}
};


void main()
{
	vector<vector<int>> Matrix = { {1, 2, 3, 4,}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
	Solution solution;
	solution.rotate(Matrix);
	for (size_t i = 0; i < Matrix.size(); ++i)
	{
		for (size_t k = 0; k < Matrix[0].size(); ++k)
		{
			cout << Matrix[i][k] << ",";
		}
		cout << endl;
	}
}