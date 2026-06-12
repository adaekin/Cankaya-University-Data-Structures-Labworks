#pragma once

class Node {
public:
	int data;
	Node* prev;
	Node* next;
	Node(int i) : data(i), prev{ nullptr }, next{nullptr} {}
};