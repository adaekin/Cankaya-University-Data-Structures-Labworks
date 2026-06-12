#include "ArrayBasedSet.h"

int ArrayBasedSet::size() const{
	return count;
}

bool ArrayBasedSet::isEmpty() const
{
	if (count <= 0) return true;
	else return false;
}

bool ArrayBasedSet::isFull() const
{
	return !this->isEmpty();
}

bool ArrayBasedSet::add(int newEntry)
{
	if (MAXSIZE > count) {
		items[count] = newEntry;
		count++;
		return true;
	}
	return false;
}

bool ArrayBasedSet::remove(int anEntry)
{
	for (int i = 0; i < count; i++) {
		if (items[i] == anEntry) {
			for (int j = i; j < count - 1; j++) {
				items[j] = items[j + 1];
			}
			count--;
			return true;
		}
	}
	return false;
}

void ArrayBasedSet::clear()
{
	for (int i = 0; i < count; i++) {
		items[i] = 0;
	}
	count = 0;
	return;
}

bool ArrayBasedSet::contains(int anEntry)
{
	for (int i = 0; i < count; i++) {
		if (items[i] == anEntry) return true;
	}
	return false;
}

string ArrayBasedSet::toString()
{
	string temp;
	
	for (int i = 0; i < count; i++) {
		
		temp = temp + to_string(items[i]) + ',';
	}
	if (!temp.empty()) temp.pop_back();
	return temp;
}
