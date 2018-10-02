
#include <iostream>
using namespace std;
class Node
{
	friend class NodeList;
public:
	Node(int val)
	{
		setData(val);
		next = nullptr;
	}
	void setData(int value)
	{
		data = value;
	}
	int getData() {
		return data;
	}
	Node* getNext()
	{
		return next;
	}
	void setNext(Node* nxt)
	{
		next = nxt;
	}
private:
	int data;
	Node * next;
};

class NodeList
{
public:
	NodeList()
	{
		front = nullptr;
		rear = nullptr;
	}

	Node* getFront()
	{
		return front;
	}

	Node * getRear()
	{
		return rear;
	}

	bool isEmpty()
	{
		if (front == nullptr)
			return true;
		return false;
	}
	void insertNodeToFront(int val)
	{
		Node *newNode = new Node(val);
		if (rear == nullptr && front == nullptr)
		{
			rear = newNode;
			front = newNode;
		}
		else
		{
			front->setNext(newNode);
			front = newNode;
		}
	}

	void insertNodeToRear(int val)
	{
		Node *newNode = new Node(val);
		if (rear == nullptr && front == nullptr)
		{
			rear = newNode;
			front = newNode;
		}
		else
		{
			newNode->setNext(rear);
			rear = newNode;
		}
	}

	bool deleteNodeFromFront()
	{
		if (isEmpty())
			return false;
		else
		{
			if (rear == front)
				rear = front = nullptr;
			else
			{
				Node * tmp = rear;
				while (tmp->getNext() != front)
				{
					tmp = tmp->getNext();
				}
				delete front;
				front = tmp;
				tmp->setNext(nullptr);
			}
		}
		return true;
	}

	bool deleteNodeFromRear()
	{
		if (isEmpty())
			return false;
		else
		{
			Node * tmp = rear;
			if (rear == front)
				rear = front = nullptr;
			else
			{
				rear = tmp->getNext();
				delete tmp;
				return true;
			}
		}
	}

	void Display()
	{
		Node * tmp = rear;
		while (tmp && tmp->getNext() != nullptr)
		{
			cout << tmp->getData() << endl;
			tmp = tmp->getNext();
		}
		cout << tmp->getData() << endl;
	}
private:
	Node * front;
	Node * rear;
};

class stack : NodeList
{
public:

	void push(int val)
	{
		insertNodeToFront(val);
	}

	void pop()
	{
		deleteNodeFromFront();
	}

	int peek()
	{
		return this->getFront()->getData();
	}

	bool isEmptyStack()
	{
		return this->isEmpty();
	}

	void Displaystack()
	{
		this->Display();
	}


private:
	int top;
	NodeList * list;
};

class queue :NodeList
{
public:
	void Enqueue(int val)
	{
		insertNodeToFront(val);
	}

	bool Dequeue()
	{
		return deleteNodeFromRear();
	}

	int peek()
	{
		return this->getFront()->getData();
	}

	bool isQueueEmpty()
	{
		this->isEmpty();
	}

	void printQueue()
	{
		this->Display();
	}
};