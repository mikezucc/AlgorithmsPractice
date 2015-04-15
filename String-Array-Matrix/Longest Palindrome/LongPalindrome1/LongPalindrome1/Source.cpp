#include <string>
#include <vector>
#include <iostream>

using namespace std;

string findLongestPalindrome(string sampleString)
{
	string longestPalin;
	int lengthPalin = 0;
	for (int i = 0; i < sampleString.length(); i++)
	{
		char sampleChar = sampleString.at(i);
		cout << "sample char: " << sampleChar << endl;
		for (int k = 1; k < (sampleString.length() - i); k++)
		{
			char testChar = sampleString.at(i + k);
			cout << "test char: " << testChar << endl;
			if (testChar == sampleChar)
			{
				string subSample = sampleString.substr(i, k+1);
				cout << "subsample: " << subSample << endl;
				bool broken = false;
				for (int j = 0; j < subSample.length()/2; j++)
				{
					char forwardChar = subSample.at(j);
					char backwardChar = subSample.at(subSample.length() - j - 1);
					if (forwardChar != backwardChar)
					{
						broken = true;
					}
				}
				if (!broken)
				{
					if (subSample.length() > lengthPalin)
					{
						longestPalin = subSample;
						lengthPalin = subSample.length();
					}
				}
			}
		}
	}
	return longestPalin;
}

int main() {

	string palinDome = "abccbtbccby";

	string longestPalin = findLongestPalindrome(palinDome);
	cout << "longestPalin: " << longestPalin;

	return 0;
}