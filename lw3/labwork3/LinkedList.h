#pragma once
#include "Node.h"
#include <string>
#include <iostream>
using namespace std;
class LinkedList {
public:
	// Constructors
	LinkedList();
	LinkedList(const LinkedList& other);
	~LinkedList();
	// Element Access
	string& at(int index);
	string& front();
	string& back();
	// Modifiers
	void push_back(const string& value);//or append
	void pop_back();
	void push_front(const string& value);
	void pop_front();//remove first
	void insert_at(int index, const string& value);
	void insert_after(int index, const string& val);
	void erase_at(int index);
	void erase(const string& e);
	void clear();//delete all nodes to make list empty
	// Capacity
	int size() const;
	bool empty() const;

	//TASK 3.3 3.4 3.5
	Node* findMiddleNode();
	Node* getSmallestNode();
	void moveSmallestToFront();

	LinkedList& operator=(const LinkedList& lhs);
	bool operator==(const LinkedList& lhs)const;
	friend ostream& operator<<(ostream& out, const LinkedList& list);
private:
	Node* head;
};
