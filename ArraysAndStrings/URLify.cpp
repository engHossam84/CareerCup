/*
Write a method to replace all spaces in a string with '%20: You may assume that the string has sufficient space at the end to hold 
the additional characters, and that you are given the "true" length of the string. 
(Note: If implementing in Java, please use a character array so that you can perform this operation in place.)
EXAMPLE
Input: "Mr John Smith "J 13
Output: "Mr%20J ohn%20Smith"
*/


#include <string>
#include <iostream>
using namespace std;


string URLify(string str, int length)
{
	string URLstr;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
		{
			URLstr.push_back(str.at(i));
		}
		else
		{
			URLstr.append("%20");
		}
	}
	return URLstr;
}


int main()
{
	cout << URLify("Mr John Smith  ", 13)<< endl;

}

