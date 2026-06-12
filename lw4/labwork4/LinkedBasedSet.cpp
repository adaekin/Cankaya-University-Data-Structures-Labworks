#include "LinkedBasedSet.h"

int LinkedBasedSet::size() const
{
	int count = 0;
	Node* walk = head;

	while (walk != nullptr) {
		count++;
		walk = walk->next;
	}
	return count;
}

bool LinkedBasedSet::isEmpty() const
{
	if (head == nullptr) return true;
	return false;
}

bool LinkedBasedSet::isFull() const
{
	return !this->isEmpty();
}

bool LinkedBasedSet::add(int newEntry)
{
	if (head == nullptr) {
		head = new Node(newEntry);
		return true;
	}
	Node* walk = head;
	while (walk->next != nullptr) {
		walk = walk->next;
	}
	walk->next = new Node(newEntry);

	return true;
}

bool LinkedBasedSet::remove(int anEntry)
{
	if (head->next != nullptr) {
		Node* walk = head->next;
		Node* pre = head;
		while (walk != nullptr) {
			if (walk->data == anEntry)
			{
				pre->next = walk->next;
				delete walk;
				return true;
			}
			pre = pre->next;
			walk = walk->next;
		}
		return false;
	}
	return false;
}

void LinkedBasedSet::clear()
{
	Node* temp = head;
	while (head->next != nullptr) {
		temp = head;
		head = head->next;
		delete temp;
	}
}

bool LinkedBasedSet::contains(int anEntry)
{
	if (head->next != nullptr) {
		Node* walk = head;
		while (walk != nullptr) {
			if (walk->data == anEntry) return true;
			walk = walk->next;
		}
		return false;
	}
	return false;
}

string LinkedBasedSet::toString()
{
	string temp;
	Node* walk = head;
	while (walk != nullptr) {
		temp = temp + to_string(walk->data) + ',';
		walk = walk->next;
	}
	if (!temp.empty()) temp.pop_back();
	return temp;
}
