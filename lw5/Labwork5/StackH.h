#pragma once
#include <iostream>
#include <string>

using namespace std;
template <typename T> class Stack
{
private:
    static const int MAX = 500;
    T arr[MAX];
    int top;

public:
    Stack();
    bool isEmpty() const;
    bool isFull() const;
    void push(const T& val);
    T pop();
    T getTop();
};
