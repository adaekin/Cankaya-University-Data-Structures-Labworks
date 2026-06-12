#include <iostream>
#include <cstdlib>
#include "Node.h"
#include <conio.h>
#include <ctime>
#include <vector>
#include "PriorityQueueWLinkedList.h"
#include "PriorityQueueWUnsortedList.h"

#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

using namespace std;


void minheap1();
void pqSorted();
void pqUnsorted();

double get_CPU_time_usage(clock_t clock1, clock_t clock2)
{
    double diffticks = clock1 - clock2;
    double diffms = (diffticks * 1000) / (CLOCKS_PER_SEC * 1000);
    return diffms;
}
vector<double> times;
vector<double> times2;

int main()
{


    // TEST1 ENQUEUE
    cout <<YELLOW << "Calculating pq sorted list..."<< RESET<< endl;
    pqSorted();
    cout << YELLOW <<"Calculating pq unsorted list..."<<RESET << endl;
    pqUnsorted();
    cout << YELLOW <<"Calculating minheap..."<< RESET << endl;
    minheap1();
}
void pqSorted() {
    srand(time(0));

PriorityQueueWLinkedList wl;
clock_t startTime, endTime;


    int randomNum;
    startTime = clock();
    for (int i = 0; i < 100000; i++) {
        //srand(time(0));
        randomNum = rand() % 100000;
        if (i == 10000)
        {
            endTime = clock();
            times.push_back((get_CPU_time_usage(endTime, startTime)));
        }
        if (i == 20000)
        {
            endTime = clock();
            times.push_back((get_CPU_time_usage(endTime, startTime)));
        }if (i == 30000)
        {
            endTime = clock();
            times.push_back((get_CPU_time_usage(endTime, startTime)));
        }if (i == 40000)
        {
            endTime = clock();
            times.push_back((get_CPU_time_usage(endTime, startTime)));
        }if (i == 50000)
        {
            endTime = clock();
            times.push_back((get_CPU_time_usage(endTime, startTime)));
        }if (i == 60000)
        {
            endTime = clock();
            times.push_back((get_CPU_time_usage(endTime, startTime)));
        }if (i == 70000)
        {
            endTime = clock();
            times.push_back((get_CPU_time_usage(endTime, startTime)));
        }if (i == 80000)
        {
            endTime = clock();
            times.push_back((get_CPU_time_usage(endTime, startTime)));
        }
        wl.insert(randomNum);
}
endTime = clock();
double elapseTime = get_CPU_time_usage(endTime, startTime);
cout << "Complated in:" <<GREEN<< elapseTime << RESET<< "s" << endl;
cout << endl;
int i = 1;
for (double sec : times)
{

    cout << i << "0000 Took : " <<GREEN << sec << " second" << endl <<RESET;
    i++;
}

cout << "--- DELETEMIN TIMES ---" << endl;
for (int targetSize = 10000; targetSize <= 80000; targetSize += 10000) {

    PriorityQueueWLinkedList testL;
    for (int i = 0; i < targetSize; i++) {
        testL.insert(rand() % 100000);
    }

    startTime = clock();
    while (!testL.isPQueueEmpty()) {
        testL.removeMin();
    }
    endTime = clock();
    double elapseTime = get_CPU_time_usage(endTime, startTime);
    cout << targetSize << " (deleteMin operations) Took: "
        << GREEN <<elapseTime <<RESET<< " seconds" << endl;
}

}
void pqUnsorted() {

    //// UNSORTED
    clock_t startTime, endTime;
    int randomNum;
    PriorityQueueWUnsortedList wul;
    startTime = clock();
    // TEST1 ENQUEUE
    for (int i = 0; i < 100000; i++) {
        //srand(time(0));
        randomNum = rand() % 100000;
        if (i == 10000)
        {
            endTime = clock();
            times2.push_back((get_CPU_time_usage(endTime, startTime)));
        }
        if (i == 20000)
        {
            endTime = clock();
            times2.push_back((get_CPU_time_usage(endTime, startTime)));
        }if (i == 30000)
        {
            endTime = clock();
            times2.push_back((get_CPU_time_usage(endTime, startTime)));
        }if (i == 40000)
        {
            endTime = clock();
            times2.push_back((get_CPU_time_usage(endTime, startTime)));
        }if (i == 50000)
        {
            endTime = clock();
            times2.push_back((get_CPU_time_usage(endTime, startTime)));
        }if (i == 60000)
        {
            endTime = clock();
            times2.push_back((get_CPU_time_usage(endTime, startTime)));
        }if (i == 70000)
        {
            endTime = clock();
            times2.push_back((get_CPU_time_usage(endTime, startTime)));
        }if (i == 80000)
        {
            endTime = clock();
            times2.push_back((get_CPU_time_usage(endTime, startTime)));
        }
        wul.insert(randomNum);
        //cout << i << "/100000" << endl;
    }
    endTime = clock();
    double elapseTime = get_CPU_time_usage(endTime, startTime);

    cout << "Complated in:" << GREEN <<elapseTime <<RESET<< "s" << endl;
    cout << endl;
    int i = 1;
    for (double sec : times)
    {

        cout << i << "0000 Took : " << GREEN << sec << " second" << endl << RESET;
        i++;
    }

    cout << "--- DELETEMIN TIMES ---" << endl;
    for (int targetSize = 10000; targetSize <= 80000; targetSize += 10000) {

        PriorityQueueWUnsortedList testL;
        for (int i = 0; i < targetSize; i++) {
            testL.insert(rand() % 100000);
        }

        startTime = clock();
        while (!testL.isPQueueEmpty()) {
            testL.removeMin();
        }
        endTime = clock();
        double elapseTime = get_CPU_time_usage(endTime, startTime);
        cout << targetSize << " (deleteMin operations) Took: " << GREEN
            << elapseTime << RESET<<" seconds" << endl;
    }
}




#define Left(n) (2*(n) + 1)
#define Right(n) (2*(n) + 2)
#define Par(n) (((n) - 1) / 2)
#define MAX 100000
class priotryqueminheap {
private:
    int sz;
    int items[MAX];
    void heapUp(int idx) {
        while (idx > 0) {
            if (items[idx] < items[Par(idx)]) {
                int t = items[idx];
                items[idx] = items[Par(idx)];
                items[Par(idx)] = t;
                idx = Par(idx);
            }
            else break;
        }
    }
    void heapdown(int idx) {
        while (Left(idx) < sz) {
            int min = Left(idx);

            if (Right(idx) < sz && items[Right(idx)] < items[Left(idx)]) {
                min = Right(idx);
            }
            if (items[idx] > items[min]) {
                int t = items[idx];
                items[idx] = items[min];
                items[min] = t;

                idx = min;
            }
            else {
                break;
            }
        }
    }
public:
    priotryqueminheap() {
        sz = 0;
    }
    void insert(int key) {
        if (sz < MAX) {
            items[sz] = key;
            heapUp(sz);
            sz++;
        }
    }
    void print() {
        for (int i = 0; i < sz; i++) {
            cout << items[i] << "->";
        }
    }
    bool isPQueueEmpty()
    {
        return (sz < 1);
    }
    bool empty()
    {
        return (sz < 1);
    }
    int removeMin()
    {
        if (sz <= 0) throw("Queue Empty");
        else
        {
            int x = items[0];
            items[0] = items[sz - 1];
            sz--;
            heapdown(0);
            return x;
        }
    }
};
vector<double> times3;

void minheap1() {
    priotryqueminheap h1;
    clock_t startTime, endTime;
    startTime = clock();
    int randomNum;
    for (int i = 0; i < 100000; i++) {
        //srand(time(0));
        randomNum = rand() % 100000;
        if (i == 10000)
        {
            endTime = clock();
            times3.push_back((get_CPU_time_usage(endTime, startTime)));
        }
        if (i == 20000)
        {
            endTime = clock();
            times3.push_back((get_CPU_time_usage(endTime, startTime)));
        }if (i == 30000)
        {
            endTime = clock();
            times3.push_back((get_CPU_time_usage(endTime, startTime)));
        }if (i == 40000)
        {
            endTime = clock();
            times3.push_back((get_CPU_time_usage(endTime, startTime)));
        }if (i == 50000)
        {
            endTime = clock();
            times3.push_back((get_CPU_time_usage(endTime, startTime)));
        }if (i == 60000)
        {
            endTime = clock();
            times3.push_back((get_CPU_time_usage(endTime, startTime)));
        }if (i == 70000)
        {
            endTime = clock();
            times3.push_back((get_CPU_time_usage(endTime, startTime)));
        }if (i == 80000)
        {
            endTime = clock();
            times3.push_back((get_CPU_time_usage(endTime, startTime)));
        }
        h1.insert(randomNum);
        
    }
    endTime = clock();
    double elapseTime = get_CPU_time_usage(endTime, startTime);

    cout << "Complated in:" << elapseTime << "s" << endl;
    cout << endl;
    int i = 1;
    for (double sec : times)
    {

        cout << i << "0000 Took : " << GREEN << sec << RESET <<" second" << endl;
        i++;
    }
    cout << "--- DELETEMIN TIMES ---" << endl;
    for (int targetSize = 10000; targetSize <= 80000; targetSize += 10000) {

        priotryqueminheap testL;
        for (int i = 0; i < targetSize; i++) {
            testL.insert(rand() % 100000);
        }

        startTime = clock();
        while (!testL.isPQueueEmpty()) {
            testL.removeMin();
        }
        endTime = clock();
        double elapseTime = get_CPU_time_usage(endTime, startTime);
        cout << targetSize << " (deleteMin operations) Took: "
            <<GREEN<< elapseTime << RESET <<" seconds" << endl;
    }
}
