#include "structures.h"
#include <limits.h>
#include <algorithm>
class stackMin : stack
{
public:
	
	stackMin()
	{
		minStack = new stack();
	}
	void minPush(int val)
	{
		if (isEmptyStack())
		{
			push(val);
			minStack->push(val);
		}
		else
		{
			push(val);
			minStack->push(std::min(val, minStack->peek()));
		}
		
	}

	void minPop()
	{
		if (!isEmptyStack())
		{
			pop();
			minStack->pop();
		}
	}

	int getStackMinumumVal()
	{
		return minStack->peek();
	}
	


private:
	stack * minStack;
	
};


int main()
{
	stackMin *myStack = new stackMin();
	myStack->minPush(7);
	myStack->minPush(4);
	myStack->minPush(2);
	myStack->minPush(5);

	cout << myStack->getStackMinumumVal() << endl;

	myStack->minPop();
	cout << myStack->getStackMinumumVal() << endl;

	myStack->minPop();
	cout << myStack->getStackMinumumVal() << endl;

	return 0;
}
