#pragma once
#include <string>
#include "IntSet.h"
#include "Node.h"
using namespace std;
class LinkedBasedSet : public IntSet {
private:
    Node* head;

public:
    int size() const override;
    bool isEmpty() const override;
    bool isFull() const override;
    bool add(int newEntry) override;
    bool remove(int anEntry) override;
    void clear() override;
    bool contains(int anEntry) override;
    string toString() override;
};