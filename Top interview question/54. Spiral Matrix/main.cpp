#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty()) return {};
		int RowStart = 0;
		int RowEnd = matrix.size() - 1;
		int ColStart = 0;
		int ColEnd = matrix[0].size() - 1;

		vector<int> SpiralOrderMatrix;
		while (RowStart <= RowEnd && ColStart <= ColEnd)
		{
			for (int j = ColStart; j <= ColEnd; ++j)
				SpiralOrderMatrix.push_back(matrix[RowStart][j]);
			if (++RowStart > RowEnd) break;
			for (int i = RowStart; i <= RowEnd; ++i)
				SpiralOrderMatrix.push_back(matrix[i][ColEnd]);
			if (ColStart > --ColEnd) break;
			for (int j = ColEnd; j >= ColStart; --j)
				SpiralOrderMatrix.push_back(matrix[RowEnd][j]);
			if (RowStart > --RowEnd) break;
			for (int i = RowEnd; i >= RowStart; --i)
				SpiralOrderMatrix.push_back(matrix[i][ColStart]);
			if (++ColStart > ColEnd) break;
		}
		return SpiralOrderMatrix;
	}
};

int main()
{
	vector<vector<int>> Input = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
	
	Solution solution;
	vector<int> Output = solution.spiralOrder(Input);

	for_each(Output.begin(), Output.end(), [](int Elem) {cout << Elem << ","; });
}