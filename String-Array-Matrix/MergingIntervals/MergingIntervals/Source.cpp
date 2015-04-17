#include <vector>
#include <iostream>

using namespace std;

class Interval {
public:
		int start;
		int end;

		Interval() {
			start = 0;
			end = 0;
		}

		Interval(int s, int e) {
			start = s;
			end = e;
		}
};

int main() {

	vector<Interval> intervalList;
	
	Interval first(1, 4);
	Interval second(2, 8);
	Interval third(7, 9);
	Interval fourth(10, 15);
	Interval fifth(11, 14);

	intervalList.push_back(first);
	intervalList.push_back(second);
	intervalList.push_back(third);
	intervalList.push_back(fourth);
	intervalList.push_back(fifth);

	vector<Interval> sortedList;
	Interval curt = intervalList.at(0);
	for (int i = 1; i < intervalList.size(); i++)
	{
		Interval next = intervalList.at(i);
		if (curt.end >= next.start)
		{
			// interval starts in previous, combine
			Interval newInter(curt.start, (curt.end > next.end ? curt.end : next.end));
			curt = newInter;
		}
		else
		{
			// interval is important
			sortedList.push_back(curt);
			curt = next;
		}
	}
	sortedList.push_back(curt);
	for (int i = 0; i < sortedList.size(); i++)
	{
		cout << "[" << sortedList.at(i).start << "," << sortedList.at(i).end << "]" << endl;
	}

	return 0;
}