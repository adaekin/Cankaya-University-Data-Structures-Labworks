#pragma once
#include "Node.h"
#include <iostream>

using namespace std;
class Stack {
private:
	Node* top;
public:
	bool isEmpty();
	void push(int);
	void pop();
	int peek();
	void display();
	Stack();
};