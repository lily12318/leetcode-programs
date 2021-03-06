#include <iostream>
#include <vector>
#include <string>
using namespace std;

//dynamic planning
int longestCommonSubstring_n2_2n(const string& str1, const string& str2)
{
	size_t size1 = str1.size();
	size_t size2 = str2.size();
	if (size1 == 0 || size2 == 0) return 0;

	vector<vector<int> > table(2, vector<int>(size2, 0));

	// the start position of substring in original string
	int start1 = -1;
	int start2 = -1;
	// the longest length of common substring 
	int longest = 0;

	// record how many comparisons the solution did;
	// it can be used to know which algorithm is better
	int comparisons = 0;
	for (int j = 0; j < size2; ++j)
	{
		++comparisons;
		if (str1[0] == str2[j])
		{
			table[0][j] = 1;
			if (longest == 0)
			{
				longest = 1;
				start1 = 0;
				start2 = j;
			}
		}
	}

	for (int i = 1; i < size1; ++i)
	{
		++comparisons;
		// with odd/even to swith working row
		int cur = ((i & 1) == 1); //index for current working row
		int pre = ((i & 1) == 0); //index for previous working row
		table[cur][0] = 0;
		if (str1[i] == str2[0])
		{
			table[cur][0] = 1;
			if (longest == 0)
			{
				longest = 1;
				start1 = i;
				start2 = 0;
			}
		}

		for (int j = 1; j < size2; ++j)
		{
			++comparisons;
			if (str1[i] == str2[j])
			{
				table[cur][j] = table[pre][j - 1] + 1;
				if (longest < table[cur][j])
				{
					longest = table[cur][j];
					start1 = i - longest + 1;
					start2 = j - longest + 1;
				}
			}
			else
			{
				table[cur][j] = 0;
			}
		}
	}

#ifdef IDER_DEBUG
	cout << "(first, second, comparisions) = ("
		<< start1 << ", " << start2 << ", " << comparisons
		<< ")" << endl;
#endif

	return longest;
}

int main(void)
{
	string line1, line2;
	getline(cin, line1);
	getline(cin, line2);

	int ret = longestCommonSubstring_n2_2n(line1, line2);

	string out = to_string(ret);
	cout << out << endl;
}