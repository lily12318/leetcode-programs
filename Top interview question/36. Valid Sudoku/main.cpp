#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
	//My answer
	/*bool isValidSudoku(vector<vector<char>>& board) {
		for (int row = 0; row < board.size(); ++row)
		{
			set<char> RowSet;
			for (int col = 0; col < board[0].size(); ++col)
			{
				char Temp = board[row][col];
				if (Temp == '.')continue;;
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
				if (Temp == '.')continue;;
				if (ColSet.find(Temp) == ColSet.end()) ColSet.insert(Temp);
				else return false;
			}
		}

		for (int row = 0; row < board.size(); row=row+3)
		{
			for (int col = 0; col < board[0].size(); col=col+3)
			{
				set<char> SubBoardSet;
				int TempRow = row;
				for (int RowCount = 0; RowCount++ < 3; ++TempRow)
				{
					int TempCol = col;
					for (int ColCount = 0; ColCount++ < 3; ++TempCol)
					{
						char Temp = board[TempRow][TempCol];
						if (Temp == '.')continue;;
						if (SubBoardSet.find(Temp) == SubBoardSet.end()) SubBoardSet.insert(Temp);
						else return false;
					}
				}
			}
		}
		return true;
	}*/
	//other better answer
	bool isValidSudoku(vector<vector<char>>& board)
	{
		//9*9 board
		bool RowNums[9][9] = { false };
		bool ColNums[9][9] = { false };
		bool BoxNums[9][9] = { false };

		for (int row = 0; row < 9; ++row)
		{
			for (int col = 0; col < 9; ++col)
			{
				if (board[row][col] == '.')continue;
				int TempNum = board[row][col] - '1';
				int BoxIdx = row / 3 * 3 + col / 3;
				if (RowNums[row][TempNum] || ColNums[col][TempNum] || BoxNums[BoxIdx][TempNum]) return false;
				RowNums[row][TempNum] = ColNums[col][TempNum] = BoxNums[BoxIdx][TempNum] = true;
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

