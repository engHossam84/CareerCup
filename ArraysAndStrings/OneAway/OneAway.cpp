
#include <string>
#include <iostream>
using namespace std;

bool checkSingleChange(string smallStr, string bigStr);
bool oneAway(string str1,string str2)
{
	if (str1.length() == str2.length())
	{
		int singleModify = 0;
		for (int i = 0; i < str1.length(); i++)
		{
			if ( (str1.at(i) != str2.at(i)))
			{
				singleModify++;
			}
		}
		if (singleModify > 1)
			return false;
		return true;
	}
	else if (str1.length() > str2.length() && str1.length() - str2.length() == 1)
	{
		return checkSingleChange(str2, str1);
	}
	else if (str1.length() < str2.length() && str2.length() - str1.length() == 1)
	{
		return checkSingleChange(str1, str2);
	}
}

bool checkSingleChange(string smallStr, string bigStr)
{
	int singleChange = 0;
	int charSet[128] = { 0 };
	for (int i = 0; i < smallStr.length(); i++)
	{
		charSet[smallStr.at(i)] ++;
	}
	for (int i = 0; i < bigStr.length(); i++)
	{
		if (charSet[bigStr.at(i)] > 0)
		{
			charSet[bigStr.at(i)]--;
		}
		else if (singleChange == 0)
		{
			singleChange++;
		}
		else if (singleChange > 1)
			return false;
	}
	return true;
}

void main()
{
	cout << oneAway("pale", "bake") << endl;
	cout << oneAway("pale", "ple") << endl;
	cout << oneAway("pales", "pale") << endl;
	cout << oneAway("pale", "bale") << endl;
	
}