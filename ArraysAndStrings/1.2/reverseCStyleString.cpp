#include <string>
#include <stack>
#include <iostream>

using namespace std;

string reverseCStyleString1(char * cStr)
{
	stack<char> myStack;
	int count = 0;
	char * newStr ;
	
	while(*cStr != '\0')
	{
		count ++;
		myStack.push(*cStr);
		*cStr++;
	}

	newStr = (char*) malloc (count+1);
	int index = 0;
	while(!myStack.empty())
	{
		newStr[index++] = myStack.top();;
		myStack.pop();
	}

	newStr[index++] = '\0';
	return newStr;
}


char* reverseCStyleString2(char * cStr)
{
	char *end = cStr;
	char tmp;
	int length = strlen(cStr);
	char * buffer;
	buffer = (char*)malloc(length);
	if(cStr)
	{
		while(*end)
		{
			end++;
		}
		end--;

		for(int i = 0 ; i < length ; i ++)
		{
			buffer[i] = *end;
			end--;
		}
		buffer[length] =  '\0';
	}
	return buffer;

}




void main()
{
	cout << reverseCStyleString1("C-Style String");
	cout <<endl;
	cout << reverseCStyleString2("C-Style String");
	cout <<endl;
}