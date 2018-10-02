/*Fixed sized stacks*/
#include <iostream>
using namespace std;
#define maxSize 999
class stack
{
public:
	stack()
	{
		for (int i = 0; i < maxSize; i++)
		{
			arr[i] = -1;
		}
		top1 = 0;
		top2 = (maxSize / 3) - 1;
		top3 = ((maxSize / 3) * 2) - 1;
	}

	int pop(int lvl)
	{
		switch (lvl)
		{
		case 1:	
			arr[top1] = -1;
			top1--;
			break;
		case 2:
			arr[top2] = -1;
			top2--;
			break;
		case 3:
			arr[top3] = -1;
			top3--;
			break;
		}
	}

	void push(int val, int lvl)
	{
		switch (lvl)
		{
		case 1:
			top1++;
			arr[top1] = val;
			break;
		case 2:
			top2++;
			arr[top2] = val;
			break;
		case 3: 
			top3++;
			arr[top3] = val;
			break;
		}
	}

	void display(int lvl)
	{
		switch (lvl)
		{
		case 1:
			for (int i = 0; i < top1; i++)
			{
				cout << arr[i] << endl;
			}
			break;
		case 2:
			print(2);
			break;
		case 3:
			print(3);
			break;
		}
	}

	void print(int lvl)
	{

	}


private:
	int top1;
	int top2;
	int top3;
	int arr[maxSize];

};