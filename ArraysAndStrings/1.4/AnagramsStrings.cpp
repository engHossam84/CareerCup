#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool anagramsStrings(string str1, string str2)
{
	bool charSet[256] = {0};
	if(str1.length() != str2.length() )
		return false;
	else
	{
		for(int i = 0 ; i < str1.length() ; i++)
		{
			charSet[str1.at(i)] = 1;
		}

		for(int i = 0 ; i < str2.length() ; i++)
		{
			if(charSet[str2.at(i)] != 1)
				return false;
		}
	}
	return true;
}


bool anagramsStrings2(string str1, string str2)
{
	sort(str1.begin(),str1.end());
	sort(str2.begin(),str2.end());
	return str1==str2;
}


void main()
{
	cout << anagramsStrings("afhgs" , "dgfhd")<< endl;
	cout << anagramsStrings("abcd" , "adcb") << endl;
	cout << anagramsStrings("acd" , "adcb") << endl;


	cout << anagramsStrings2("afhgs" , "dgfhd")<< endl;
	cout << anagramsStrings2("abcd" , "adcb") << endl;
	cout << anagramsStrings2("acd" , "adcb") << endl;

}