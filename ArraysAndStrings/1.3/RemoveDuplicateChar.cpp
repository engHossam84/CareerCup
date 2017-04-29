#include <string>
#include <iostream>

using namespace std;

string removeDublicateChar(string str)
{
	if(str.length() > 1)
	{
		for(int i = 0  ; i < str.length()-1 ; i++)
		{
				for(int j  = i+1 ; j < str.length() ; j ++)
				{
					if(str.at(i) == str.at(j))
					{
						str.erase(j,1);
						j--;
					}
				}
		}

	}
	return str;
}

void main()
{
	cout << removeDublicateChar("") <<endl;
	cout << removeDublicateChar("a") <<endl;
	cout << removeDublicateChar("ab") <<endl;
	cout << removeDublicateChar("abab") <<endl;
	cout << removeDublicateChar("aaab") <<endl;
	cout << removeDublicateChar("abca") <<endl;
	cout << removeDublicateChar("aaabbbasdwa") <<endl;
	cout << removeDublicateChar("abca") <<endl;
	cout << removeDublicateChar("aksjdgahs") <<endl;

}