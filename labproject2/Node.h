#pragma once
#include <string>
#include <iostream>
#include <ostream>
using namespace std;

template<typename K>
class Node {
public:
    K data;
    Node<K>* next;

    Node() : data(K()), next(nullptr) {}

    Node(const K& value) : data(value), next(nullptr) {}

    void print() const {
        std::cout << data << "->";
    }
    friend std::ostream& operator<<(std::ostream& out, const Node<K>& obj) {
        out << obj.data << "->";
        return out;
    }
};