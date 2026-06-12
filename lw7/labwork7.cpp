#include <iostream>

using namespace std;

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int servedCount;
    string name;
public:
    Queue(int size, string station) {
        arr = new int[size];
        name = station;
        capacity = size;
        servedCount = 0;
        front = 0;
        rear = 0;

    }

    bool isFull();
    bool isEmpty();
    void enqueue(int);
    void dequeue();
    void display();
    int getServedCount();
    string getName();
};

int main()
{
    Queue q1(5, "Elysium");
    Queue q2(6, "K-7");
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(4);
    q1.enqueue(4);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(5);
    q1.display();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();

    cout << q1.getName() << " Station served for " << q1.getServedCount() << " times." << endl;

    q2.enqueue(3);
    q2.enqueue(4);
    q2.enqueue(4);
    q2.enqueue(4);
    q2.enqueue(4);
    q2.enqueue(5);
    q2.enqueue(5);
    q2.display();
    q2.dequeue();
    q2.dequeue();
    q2.dequeue();
    q2.dequeue();
    q2.dequeue();
    q2.dequeue();
    q2.dequeue();

    cout << q2.getName() << " Station served for " << q2.getServedCount() << " times." << endl;
}

bool Queue::isFull()
{
    if (rear == capacity) return true;
    return false;
}

bool Queue::isEmpty()
{
    return rear == 0;
}

void Queue::enqueue(int i)
{
    if (!isFull()) {
        arr[rear++] = i;

    }
    else
    {
        dequeue();
        arr[rear++] = i;

    }
    cout << "Spacecraft " << i << " added to Station " << name << endl;
}

void Queue::dequeue()
{
    if (isEmpty()) {
        cout << "Station " << name << " queue is empty." << endl;
        return;
    }
    cout << "Station " << name << " docking spacecraft:" << arr[front] << endl;
    for (int i = front; i < rear - 1; i++) {
        arr[i] = arr[i + 1];
    }
    servedCount++;
    rear--;
    
    
}

void Queue::display()
{
    cout << "Station " << name << " Queue: ";
    for (int i = 0; i < rear; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int Queue::getServedCount()
{
    return servedCount;
}

string Queue::getName()
{
    return name;
}
