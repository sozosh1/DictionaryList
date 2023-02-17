#include <iostream>
#include "dictionary.h"

DictionaryList::Node* DictionaryList::head() const
{
	return head_;
}
DictionaryList::Node* DictionaryList::head() const
{
	return tail_;
}

DictionaryList::DictionaryList() : head_(nullptr), tail_(nullptr) {}


void DictionaryList::insert(DictionaryList::Node* x)
{
	if (head() == nullptr)
	{
		head_ = x;
		return;
	}

	int value = headItem();
	if (x->item_ < value)
	{
		x->next_ = head();
		head_ = x;
	}
	else
	{
		Node* prevNode = head();
		Node* nextNode = head()->next_;
		while (x->item_ > value && nextNode)
		{
			value = nextNode->item_;
			nextNode = nextNode->next_;
			prevNode = prevNode->next_;
		}
		x->next_ = nextNode;
		prevNode->next_ = x;
	}
}

DictionaryList::Node* DictionaryList::search(int item)
{
	Node* Node = head();
	while (Node && item != Node->item_)
	{
		Node = Node->next_;
	}
	if (Node && item == Node->item_)
	{
		return Node;
	}
	return nullptr;
}

int DictionaryList::headItem() const
{
	return head()->item_;
}

bool DictionaryList::insert(int item)
{
	if (head() != nullptr)
	{
		if (search(item) != nullptr)
		{
			return false;
		}
	}
	Node* newNode = new Node(item);
	insert(newNode);
	return true;
}


//bool DictionaryList::deleteNode(int key)
//{
//	Node* deleteNode = new Node(key);
//
//}

bool DictionaryList::searchNode(int item)
{
	if (search(item) != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void DictionaryList::display()
{
	if (head == NULL)
	{
		std::cout << "empty\n";
	}
	struct Node* temp = head_;
	std::cout << "List:\n";
	while (temp != NULL)
	{
		std::cout << temp->item_ << "    ";
		temp = temp->next_;
	}


}