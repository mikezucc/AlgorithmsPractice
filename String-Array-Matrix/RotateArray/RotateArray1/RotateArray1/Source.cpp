/*

Description: Rotate an array, for n distance, or n phase (radians)

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const double PI = 3.141592653589793238463;

vector<int> rotateUsingDistance(int distance, const vector<int>& arr)
{
	distance = distance % arr.size();

	vector<int> newArr;

	for (int i = 0; i < arr.size(); i++)
	{
		newArr.push_back(arr.at((distance + i) % arr.size()));
	}
	return newArr;
}

// in radians
vector<int> rotateUsingPhase(double phase, const vector<int>& arr)
{
	int realDistance = (fmod(phase, (2 * PI)) / (2 * PI)) * arr.size();

	vector<int> newArr;

	for (int i = 0; i < arr.size(); i++)
	{
		newArr.push_back(arr.at((realDistance + i) % arr.size()));
	}
	return newArr;
}


int main() {

	vector<int> testArr;
	for (int i = 0; i < 5; i++)
	{
		int val = rand() % 15;
		testArr.push_back(val);
	}

	cout << "original: " << endl;
	for (int i = 0; i < testArr.size(); i++)
	{
		cout << testArr.at(i) << ", ";
	}

	vector<int> distanceArr = rotateUsingDistance(2, testArr);
	cout << endl << "rotated With Distance: " << endl;
	for (int i = 0; i < distanceArr.size(); i++)
	{
		cout << distanceArr.at(i) << ", ";
	}

	vector<int> phaseArr = rotateUsingDistance((double)3.14, testArr);
	cout << endl << "rotated With Phase: " << endl;
	for (int i = 0; i < phaseArr.size(); i++)
	{
		cout << phaseArr.at(i) << ", ";
	}
	return 0;
}