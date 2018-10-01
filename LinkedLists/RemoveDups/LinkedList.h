
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
		if (front == rear)
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

	bool deleteNodeFromFront(NodeList *myList)
	{
		if (myList->rear == myList->front)
			myList->rear = myList->front = nullptr;
		else
		{
			Node * tmp = myList->rear;
			while (tmp->getNext() != front)
			{
				tmp = tmp->getNext();
			}
			front = tmp;
			tmp->setNext(nullptr);
		}

	}

	void deleteNodeFromRear(NodeList *myList)
	{
		Node * tmp = myList->rear;
		rear = tmp->getNext();
		delete tmp;
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

