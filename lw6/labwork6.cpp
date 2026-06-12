#include <iostream>
#include "Stack.h"

using namespace std;
int main() {
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.display();
	cout << "Top element: " << s.peek() << endl;
	s.pop();
	s.display();
	return 0;
}
