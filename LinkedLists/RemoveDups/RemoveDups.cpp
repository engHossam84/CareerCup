#include <list>
#include <unordered_set>
#include <iostream>
#include "LinkedList.h"
using namespace std;
/*
{ 2, 8, 7, 5, 3,5,2, 1, 2, 4 }
*/

NodeList * removeDups3(NodeList * list)
{
	if (!list->isEmpty())
	{
		Node * current = list->getRear();
		Node * Runner = current;
		while (Runner->getNext() != nullptr)
		{
			if (Runner->getNext()->getData() == current->getData())
			{
				Runner->setNext(Runner->getNext()->getNext());
			}
			else
			{
				Runner = Runner->getNext();
			}
		}
		current = current->getNext();
	}
	return list;
}

NodeList * removeDups2(NodeList * list)
{
	unordered_set<int> table;
	if (!list->isEmpty())
	{
		Node * current = list->getRear();
		Node * previous;
		table.insert(current->getData());
		while (current->getNext() != nullptr)
		{	
			previous = current;
			current = current->getNext();
			if(table.find(current->getData()) == table.end())
			{
				table.insert(current->getData());
			}
			else {
				previous->setNext(current->getNext());
				Node * tmp =  current;
				tmp->setNext(nullptr);
				current = previous;
				delete tmp;
			}
			
		}
	}
	return list;
}

list<int> removeDups(list<int> unSortedList)
{
	list<int>::iterator first = unSortedList.begin();
	list<int>::iterator second;
	list<int>::iterator tmp;
	bool dupFound = false;
	while ( first != unSortedList.end())
	{
		for (second = std::next(first, 1); second != unSortedList.end(); second++)
		{
			if (*first == *second)
			{
				tmp = second;
				second--;
				unSortedList.erase(tmp);
				dupFound = true;
			}
		}
		if (dupFound)
		{
			tmp = first;
			first++;
			unSortedList.erase(tmp);
			dupFound = false;
		}
		else
			first++;
	}
	return unSortedList;
}

int main()
{
	NodeList *myList = new NodeList();

	myList->insertNodeToFront(2);
	myList->insertNodeToFront(8);
	myList->insertNodeToFront(7);
	myList->insertNodeToFront(5);
	myList->insertNodeToFront(3);
	myList->insertNodeToFront(5);
	myList->insertNodeToFront(2);
	myList->insertNodeToFront(1);
	myList->insertNodeToFront(4);

	NodeList *outputList2 = removeDups3(myList);

	outputList2->Display();



	/*list<int> listOfInts({ 2, 8, 7, 5, 3,5,2, 1, 2, 4 });
	list<int> outputList = removeDups(listOfInts);
	for (list<int>::iterator it = outputList.begin(); it != outputList.end(); it++)
	{
		cout << *it << endl;
	}*/
}