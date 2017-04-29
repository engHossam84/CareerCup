#include <string>
#include <iostream>

using namespace std;

string replaceSpaces(string str)
{
	const string str2 = "%20";
	if(str.length() < 2)
		return str;
	for(int i = 0 ; i < str.length() ; i ++)
	{
		if(str.at(i) == ' ')
		{
			str.replace(i,1,str2);
		}
	}
	return str;
}

void main()
{
	cout << replaceSpaces("abcd") <<endl;
	cout << replaceSpaces("a cd") <<endl;
	cout << replaceSpaces("a  d") <<endl;
	cout << replaceSpaces(" abcd") <<endl;
	cout << replaceSpaces("abcd ") << endl;
	cout << replaceSpaces("a b c d") <<endl;
	cout << replaceSpaces("") << endl;

}