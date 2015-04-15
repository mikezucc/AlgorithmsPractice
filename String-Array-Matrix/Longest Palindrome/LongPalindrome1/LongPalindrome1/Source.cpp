#include <string>
#include <vector>
#include <iostream>
#include <time.h>

using namespace std;

string findLongestPalindrome(string sampleString)
{
	string longestPalin;
	int lengthPalin = 0;
	for (int i = 0; i < sampleString.length(); i++)
	{
		char sampleChar = sampleString.at(i);
		//cout << "sample char: " << sampleChar << endl;
		for (int k = 1; k < (sampleString.length() - i); k++)
		{
			char testChar = sampleString.at(i + k);
			//cout << "test char: " << testChar << endl;
			if (testChar == sampleChar)
			{
				string subSample = sampleString.substr(i, k+1);
				//cout << "subsample: " << subSample << endl;
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

string findLongestPalindromeOptimized(string sampleString)
{
	string longestPalin = "";
	int lengthPalin = 0;
	for (int i = 0; i < sampleString.length(); i++)
	{
		char sampleChar = sampleString.at(i);
		//cout << "sample char: " << sampleChar << endl;
		
		for (int k = (sampleString.length() - i); k > 0; k--)
		{
			char testChar = sampleString.at(k - 1);
			//cout << "test char: " << testChar << endl;
			bool broken = false;
			if (testChar == sampleChar)
			{
				string subSample = sampleString.substr(i, k - 1);
				//cout << "subsample: " << subSample << endl;
				for (int j = 0; j < subSample.length() / 2; j++)
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
					break;
				} 
			}
		}
		if (lengthPalin > (sampleString.length() - lengthPalin - i)) break;
	}
	return longestPalin;
}

string findLongestPalinJerkAlgo(string sampleString)
{
	string longestPalin;
	int palinLength;
	for (int i = 2; i < sampleString.size(); i++)
	{
		char PrevPrev = sampleString.at(i - 2);
		char Prev = sampleString.at(i - 1);

		bool evenPalin = Prev == sampleString.at(i);
		bool oddPalin = PrevPrev == sampleString.at(i);

		if (oddPalin && !evenPalin)
		{
			// a_a
			int k = 0;
			bool broken = false;
			while ((i - k - 2)>0 && (i + k) < (sampleString.length() - 1))
			{
				// ba_ab
				k++;
				PrevPrev = sampleString.at(i - k - 2);
				char Next = sampleString.at(i + k);
				if (Next != PrevPrev)
				{
					broken = true;
					break;
				}
			}
			if (!broken)
			{
				longestPalin = sampleString.substr(i - k - 2, i + k + 1);
				palinLength = longestPalin.size();
			}
		}
		if (evenPalin && !oddPalin)
		{
			// _aa
			int k = 0;
			bool broken = false;
			while ((i - k - 1)>0 && (i + k) < (sampleString.length()-1))
			{
				// _baab
				k++;
				PrevPrev = sampleString.at(i - k - 1);
				char Next = sampleString.at(i + k);
				if (Next != PrevPrev)
				{
					broken = true;
					break;
				}
			}
			if (!broken)
			{
				longestPalin = sampleString.substr(i - k - 1, i + k + 1);
				palinLength = longestPalin.size();
			}
		}
	}
	return longestPalin;
}

int main() {

	string palinDomeEnd = "2345ljkhlj234h5l234jk5hlkjhljk3h45234lkjlongassstringforthatpalinstomeemotsnilaptahtrofgnirtsssagnol";
	string palinDomeStart = "longassstringforthatpalinstomeemotsnilaptahtrofgnirtsssagnol2345ljkhlj234h5l234jk5hlkjhljk3h45234lkj";
	string palinDomeMiddle = "2345ljkhlj2345dfg34h5l2longassstringforthatpalinstomeemotsnilaptahtrofgnirtsssagnol34jk5hlkj345dfgdfghljk3h45234lkj";
	string longass1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaatyaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	string longass2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaatyaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	string longass3 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaatyaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	cout << "PALINSTART, with palindrome: " << "longassstringforthatpalinstomeemotsnilaptahtrofgnirtsssagnol" << endl;
	cout << endl;
	clock_t t1, t2, t3, t4;
	cout << "Palindrome at end" << endl;
	t3 = clock();
	string longestPalinOld;
	for (int p = 0; p < 100; p++)
	{
		longestPalinOld = findLongestPalindromeOptimized(palinDomeEnd);
		
	}
	t4 = clock();
	float diff2((float)t4 - (float)t3);
	cout << "opt:    " << diff2 << endl;

	t1 = clock();
	for (int p = 0; p < 100; p++)
	{
		string longestPalin = findLongestPalindrome(palinDomeEnd);
		//cout << "longestPalin: " << longestPalin << endl;
	}
	t2 = clock();
	float diff1((float)t2 - (float)t1);
	cout << "nonopt: " << diff1 << endl;

	t1 = clock();
	for (int p = 0; p < 100; p++)
	{
		string jerkpalin = findLongestPalinJerkAlgo(palinDomeEnd);
	}
	t2 = clock();
	float diff9((float)t2 - (float)t1);
	cout << "Jerk:   " << diff9 << endl;
	cout << endl;

	cout << "Palindrome at Beginning" << endl;
	t3 = clock();
	for (int p = 0; p < 100; p++)
	{
		longestPalinOld = findLongestPalindromeOptimized(palinDomeStart);

	}
	t4 = clock();
	float diff3((float)t4 - (float)t3);
	cout << "opt:    " << diff3 << endl;

	t1 = clock();
	for (int p = 0; p < 100; p++)
	{
		string longestPalin = findLongestPalindrome(palinDomeStart);
		//cout << "longestPalin: " << longestPalin << endl;
	}
	t2 = clock();
	float diff4((float)t2 - (float)t1);
	cout << "nonopt: " << diff4 << endl;

	t1 = clock();
	for (int p = 0; p < 100; p++)
	{
		string jerkpalin = findLongestPalinJerkAlgo(palinDomeStart);
	}
	t2 = clock();
	float diff12((float)t2 - (float)t1);
	cout << "Jerk:   " << diff12 << endl;
	cout << endl;

	cout << "Palindrome at Middle" << endl;
	t3 = clock();
	for (int p = 0; p < 100; p++)
	{
		longestPalinOld = findLongestPalindromeOptimized(palinDomeMiddle);

	}
	t4 = clock();
	float diff6((float)t4 - (float)t3);
	cout << "opt:    " << diff6 << endl;

	t1 = clock();
	for (int p = 0; p < 100; p++)
	{
		string longestPalin = findLongestPalindrome(palinDomeMiddle);
		//cout << "longestPalin: " << longestPalin << endl;
	}
	t2 = clock();
	float diff5((float)t2 - (float)t1);
	cout << "nonopt: " << diff5 << endl;

	t1 = clock();
	for (int p = 0; p < 100; p++)
	{
		string jerkpalin = findLongestPalinJerkAlgo(palinDomeMiddle);
	}
	t2 = clock();
	float diff8((float)t2 - (float)t1);
	cout << "Jerk:   " << diff8 << endl;

	return 0;
}