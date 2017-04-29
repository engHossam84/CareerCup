#include <string>
#include <iostream>

using namespace std;

bool allUnique1(string str)
{
	if(str.length() <= 1)
		return true;
	for(int i = 0 ; i < str.length() - 1 ; i ++)
		for(int j = i+1 ; j < str.length() ; j ++)
		{
			if(str.at(i) == str.at(j))
				return false;
		}
		return true;
}

bool allUnique2(string str)
{
	bool charSet[256] = {0};
	for(int i = 0 ; i < str.length(); i ++)
	{
		if(charSet[str.at(i)])
			return false;
		else
			charSet[str.at(i)] = 1;
	}
	return true;
}


void main()
{
	cout << allUnique1("") <<endl;
	cout << allUnique1("a") <<endl;
	cout << allUnique1("abc") <<endl;
	cout << allUnique1("aa") <<endl;
	cout << allUnique1("abcc") <<endl;
	cout << allUnique1("abdkjfkcc") <<endl;

	cout << endl << endl;

	cout << allUnique2("") <<endl;
	cout << allUnique2("a") <<endl;
	cout << allUnique2("abc") <<endl;
	cout << allUnique2("aa") <<endl;
	cout << allUnique2("abcc") <<endl;
	cout << allUnique2("abdkjfkcc") <<endl;

}