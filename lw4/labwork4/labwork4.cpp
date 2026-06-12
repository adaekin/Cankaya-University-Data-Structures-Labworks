#include <iostream>
#include "ArrayBasedSet.h"
#include "LinkedBasedSet.h"

using namespace std;


int main()
{
    IntSet* set1 = new ArrayBasedSet();
    set1->add(33);
    set1->add(23);
    set1->add(14);
    set1->add(1);
    set1->add(2);
    set1->add(23);
    set1->add(18);
    set1->add(33);
    set1->add(33);
    set1->add(33);
    cout << set1->toString();
    if (set1->contains(44)) {
        cout << "Set1 contains 44" << endl;
    }
    else
    {
        cout << "Set1 doesn't contains 44" << endl;
    }
    set1->remove(23);
    cout << endl << "SET2:" << endl;
    IntSet* set2 = new LinkedBasedSet();
    set2->add(33);
    set2->add(23);
    set2->add(14);
    set2->add(1);
    set2->add(2);
    set2->add(23);
    set2->add(18);
    set2->add(33);
    set2->add(33);
    set2->add(33);
    cout << set2->toString();
    if (set2->contains(44)) {
        cout << "Set2 contains 44" <<endl;
    }
    else
    {
        cout << "Set1 doesn't contain 44" << endl;
    }
    set2->remove(23);
    cout << set2->toString();
}

