#pragma once
#include <iostream>
#include "Node.h"
class PriorityQueueWUnsortedList {
private:
    Node* head;
    int _size;
public:
    bool isPQueueEmpty();
    int size();
    bool empty();
    void insert(int e);
    int min();
    int removeMin();
    Node* getHead();
    PriorityQueueWUnsortedList() {
        head = nullptr;
        _size = 0;
    }
};

bool PriorityQueueWUnsortedList::isPQueueEmpty()
{
    return head == nullptr;
}
int PriorityQueueWUnsortedList::size()
{
    return _size;
}
bool PriorityQueueWUnsortedList::empty()
{
    return head == nullptr;
}
void PriorityQueueWUnsortedList::insert(int e)
{
    Node* newNode = new Node(e);
    newNode->next = head;
    head = newNode;
    _size++;
}
int PriorityQueueWUnsortedList::min()
{
    if (empty()) throw("Queue Empty");
    else
    {
        return head->data;
    }
}
int PriorityQueueWUnsortedList::removeMin()
{
    if (head == nullptr) throw("Queue Empty");

    Node* minNode = head;
    Node* minPrev = nullptr;

    Node* walk = head;
    Node* prev = nullptr;

    while (walk != nullptr) {
        if (walk->data < minNode->data) {
            minNode = walk;
            minPrev = prev;
        }
        prev = walk;
        walk = walk->next;
    }

    int minValue = minNode->data;

    if (minNode == head) {
        head = head->next;
    }
    else {
        minPrev->next = minNode->next;
    }

    delete minNode;
    _size--;

    return minValue;
}
Node* PriorityQueueWUnsortedList::getHead()
{
    return head;
}