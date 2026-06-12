#include "StackH.h"
template<typename T>
inline Stack<T>::Stack() : top(-1)
{}

template<typename T>
bool Stack<T>::isEmpty() const
{
	if (top == -1) return 1;
	return false;
}

template<typename T>
bool Stack<T>::isFull() const
{
	if (top >= MAX - 1) return 1;
	return false;
}

template<typename T>
void Stack<T>::push(const T& val)
{
	if (isFull()) {
		cout << "Stack is full.....";
		exit(0);
	}
	top++;
	arr[top] = val;
}

template<typename T>
T Stack<T>::pop()
{
	if (isEmpty()) {
		cout << "Stack is empty....";
		exit(0);
	}
	T e = arr[top];
	top--;
	return e;
}

template<typename T>
T Stack<T>::getTop()
{
	if (isEmpty()) {
		cout << "Stack is empty....";
		exit(0);
	}
	T e = arr[top];
	return e;
}
