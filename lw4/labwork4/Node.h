#pragma once
#include <string>
#include <iostream>
#include <ostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;

	Node() :next(nullptr) {}
	Node(const int& na) :next(nullptr), data(na) {}

	void print()const {
		cout << data << "->";
	}
	friend ostream& operator<< (ostream& out, const Node& obj);
};

inline ostream& operator<<(ostream& out, const Node& obj)
{
	out << obj.data << string("->");
	return out;
}