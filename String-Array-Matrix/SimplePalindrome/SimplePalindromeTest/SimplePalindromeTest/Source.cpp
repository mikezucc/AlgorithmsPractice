/*
	Write a function using a stack to tell whether a string is a palindrome or not.

	Write test function to test the strings, MOM, MADAM, RACECAR, DEED.

	bool isPalindrome(const string& origstr);

*/

#include <string>
#include <iostream>

using namespace std;

template<class ItemType>
class Node
{
private:
	ItemType        item; // A data item
	Node<ItemType>* next; // Pointer to next node

public:
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
	void setItem(const ItemType& anItem);
	void setNext(Node<ItemType>* nextNodePtr);
	ItemType getItem() const;
	Node<ItemType>* getNext() const;
}; // end Node

bool isPalindrome(const string& origstr)
{
	

	return true;
}