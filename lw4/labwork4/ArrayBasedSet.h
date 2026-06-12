#pragma once
#include <string>
#include "IntSet.h"
using namespace std;
class ArrayBasedSet : public IntSet {
private:
    static const int MAXSIZE = 12;
    int items[MAXSIZE];
    int count = 0;
    
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