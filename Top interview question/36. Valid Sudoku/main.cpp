#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		for (int row = 0; row < board.size(); ++row)
		{
			set<char> RowSet;
			for (int col = 0; col < board[0].size(); ++col)
			{
				char Temp = board[row][col];
				if (Temp == '.')break;
				if (RowSet.find(Temp) == RowSet.end()) RowSet.insert(Temp);
				else return false;
			}
		}


		for (int col = 0; col < board[0].size(); ++col)
		{
			set<char> ColSet;
			for (int row = 0; row < board.size(); ++row)
			{
				char Temp = board[row][col];
				if (Temp == '.')break;
				if (ColSet.find(Temp) == ColSet.end()) ColSet.insert(Temp);
				else return false;
			}
		}

		for (int row = 0; row < board.size(); ++row)
		{
			set<char> SubBoardSet;
			for (int col = 0; col < board[0].size(); ++col)
			{
				int RowCount = 0;
				while (++RowCount <= 3)
				{
					int ColCount = 0;
					while (++ColCount <= 3)
					{
						char Temp = board[row][col];
						if (Temp == '.')break;
						if (SubBoardSet.find(Temp) == SubBoardSet.end()) SubBoardSet.insert(Temp);
						else return false;
						++col;
					}
					++row;
				}
			}
		}
		return true;
	}
};

void main()
{
	vector<vector<char>> Input1 = {
		{ '5', '3', '.', '.', '7', '.', '.', '.', '.' },
		{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
		{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
		{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
		{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
		{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
		{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
		{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
		{ '.', '.', '.', '.', '8', '.', '.', '7', '9' }
	};

	vector<vector<char>> Input2 = {
		{ '8', '3', '.', '.', '7', '.', '.', '.', '.' },
		{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
		{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
		{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
		{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
		{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
		{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
		{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
		{ '.', '.', '.', '.', '8', '.', '.', '7', '9' }
	};

	Solution solution;
	bool isTrue1 = solution.isValidSudoku(Input1);
	bool isTrue2 = solution.isValidSudoku(Input2);
	cout << "Input1 isTrue? " << isTrue1 << endl << "Input2 isTrue? " << isTrue2 << endl;
}

