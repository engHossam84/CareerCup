#include "structures.h"


class QueueViaStack 
{
public:
	QueueViaStack()
	{
		stack1 = new stack();
		stack2 = new stack();
	}

	void enqueue(int val)
	{
		stack1->push(val);
	}

	void dequeue()
	{
		if (stack2->isEmptyStack())
		{
			while (!stack1->isEmptyStack())
			{
				stack2->push(stack1->peek());
				stack1->pop();
			}
		}
		else
		{
			stack2->pop();
		}
	}


	int queuePeek()
	{
		if (!stack2->isEmptyStack())
		{
			return stack2->peek();
		}
		else
		{
			while (!stack1->isEmptyStack())
			{
				stack2->push(stack1->peek());
				stack1->pop();
			}
			return stack2->peek();
		}
	}

	
private:
	stack * stack1;
	stack * stack2;
};

int main()
{
	QueueViaStack * myQueue = new QueueViaStack();
	myQueue->enqueue(2);
	myQueue->enqueue(5);
	myQueue->enqueue(1);
	myQueue->enqueue(3);
	myQueue->enqueue(8);

	cout << myQueue->queuePeek() << endl;
	myQueue->dequeue();
	cout << myQueue->queuePeek() << endl;
	myQueue->dequeue();
	myQueue->dequeue();
	cout << myQueue->queuePeek() << endl;

	return 0;
}