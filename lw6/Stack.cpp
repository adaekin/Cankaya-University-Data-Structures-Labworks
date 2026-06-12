#include "Stack.h"

bool Stack::isEmpty()
{
	if (top == nullptr) return true;
	return false;
}

void Stack::push(int i)
{
	if (isEmpty()) {
		top = new Node(i);
		return;
	}
	else
	{
		Node* newNode = new Node(i);
		newNode->prev = top;
		top->next = newNode;
		top = newNode;
		
	}
}

void Stack::pop()
{
	Node* temp = top;
	cout << temp->data << " popped from stack." << endl;
	top = top->prev;
	delete temp;

}

int Stack::peek()
{
	if (this->isEmpty())
	{
		return NULL;
	}
	return top->data;
}

void Stack::display() {
	if (isEmpty())
	{
		return;
	}
	Node* w = top;
	cout << "Stack Elements(top to bottom):";
	while (w != nullptr) {
		cout << w->data << "->";
		w = w->prev;
	}
	cout << endl;
	return;

}

Stack::Stack()
{
	top = nullptr;
}
