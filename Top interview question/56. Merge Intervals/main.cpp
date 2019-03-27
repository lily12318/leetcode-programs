#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Definition for an interval
struct Interval
{
	int start;
	int end;
	Interval() :start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
public:
	Solution() {}
	~Solution() {}
	vector<Interval> merge(vector<Interval>& vIntervals)
	{
		if (vIntervals.size() <= 1) return vIntervals;
		sort(vIntervals.begin(), vIntervals.end(), [&](Interval First, Interval Next) {return First.start < Next.start;  });

		vector<Interval> Ret;
		Ret.push_back(vIntervals[0]);
		for (int i = 1; i < vIntervals.size(); ++i)
		{
			if (vIntervals[i].start > Ret.back().end)
				Ret.push_back(vIntervals[i]);
			else
				Ret.back().end = max(Ret.back().end, vIntervals[i].end);
		}
		return Ret;
	}
};

int main()
{
	vector<vector<Interval>> IntervalVec = { { Interval(1,3), Interval(2,6), Interval(8,10), Interval(15,18) },
										 { Interval(1,10), Interval(2,3), Interval(4,11) },
										 { Interval(1,4), Interval(0,0) },
										 {Interval(5,8), Interval(2,3), Interval(1,10)},
										 {} };

	Solution Solution1;
	for (int i = 0; i < IntervalVec.size(); ++i)
	{
		vector<Interval> OutputIntervalVec = Solution1.merge(IntervalVec[i]);
		for (int k = 0; k < OutputIntervalVec.size(); ++k)
		{
			cout << "[" << OutputIntervalVec[k].start << ", " << OutputIntervalVec[k].end << "], ";
		}
		cout << endl;
	}
}