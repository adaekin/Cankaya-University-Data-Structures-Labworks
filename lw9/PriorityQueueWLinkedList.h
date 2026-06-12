#pragma once
#include <iostream>
#include "Node.h"
class PriorityQueueWLinkedList {
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
    PriorityQueueWLinkedList() {
        head = nullptr;
        _size = 0;
    }
};

bool PriorityQueueWLinkedList::isPQueueEmpty()
{
    return head == nullptr;
}
int PriorityQueueWLinkedList::size()
{
    return _size;
}
bool PriorityQueueWLinkedList::empty()
{
    return head == nullptr;
}
void PriorityQueueWLinkedList::insert(int e)
{
    Node* newNode = new Node(e);

    if (head == nullptr || head->data > e) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* walk = head;

        while (walk->next != nullptr && walk->next->data < e) {
            walk = walk->next;
        }
        newNode->next = walk->next;
        walk->next = newNode;
    }
    _size++;
}
int PriorityQueueWLinkedList::min()
{
    if (head == nullptr) throw("Queue Empty");

    Node* walk = head;
    int minValue = head->data;

    while (walk != nullptr) {
        if (walk->data < minValue) {
            minValue = walk->data;
        }
        walk = walk->next;
    }
    return minValue;
}
int PriorityQueueWLinkedList::removeMin()// BUNLAR DEĞİŞECEK
{

    Node* temp = head;
    if (head == nullptr) throw("Queue Empty");
    head = head->next;
    int tempi = temp->data;
    delete temp;
    _size--;
    return tempi;
}
Node* PriorityQueueWLinkedList::getHead()
{
    return head;
}