#pragma once
#ifndef __DICTIONARY_LIST
#define __DICTIONARY_LIST

class DictionaryList
{
private:

	struct Node
	{
		int item_;
		Node* next_;

		Node(int item, Node* next = nullptr)
		{
			item_ = item;
			next_ = next;
		}
	};

	Node* head_;
	Node* tail_;

	Node* head() const;
	void insert(Node* x);
	//void deleteNode(Node* x);
	Node* search(int key);

public:

	DictionaryList();
	int headItem() const;
	bool insert(int item);
	//bool deleteNode(int key);
	bool searchNode(int item);
	void display();

};

#endif