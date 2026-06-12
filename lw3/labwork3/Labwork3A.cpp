#include <iostream>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

int main()
{
    //string asd = "SAD";
    //string asd2 = "QWE";
    //string asd3 = "asd";
    //string asd4 = "TYZ";
    //Node* asdqwe = new Node(asd);
    ////asdqwe->print();
    //LinkedList l1,l2;
    //l1.push_back("asd");
    //l1.push_back("qwe");
    //l1.push_back("dwe");
    //l1.push_back("vec");

    //cout << "AT:" << l1.at(2) << endl;
    //cout << "FRONT:" << l1.front() << endl;
    //cout << "BACK:" << l1.back()<< endl ;
    //l1.push_back(asd);
    //cout << "PUSH BACK:" << l1 << endl;
    //l1.pop_back(); //ÇALIŞMIYOR
    //cout << "POP BACK:" << l1 << endl;
    //l1.push_front(asd2);
    //cout << "PUSH FRONT:" << l1 << endl;
    //l1.pop_front();
    //cout << "POP FRONT:" << l1 << endl;
    //l1.insert_at(0, asd2);
    //cout << "INSERT AT 2:" << l1 << endl;
    //l1.erase_at(2);
    //cout << "ERASE AT 2:" << l1 << endl;
    //cout << "SIZE:" << l1.size() << endl;
    //l1.insert_after(3, asd4);
    //cout << "INSERT AFTER:" << l1 << endl;
    //l2 = l1;
    //cout << "=" << l2 << endl;
    //cout << "L1:" << l1 << endl << "L2:" << l2 << endl;
    //cout << "==" << (l1 == l2) << endl;
    //
    //cout << "FONKSİYON TESTİ TAMAM." << endl << endl;
    string selectionString = "";
    LinkedList newlink;
    cout << "Welcome to the Linked List Program!" << endl;
    while (true) {
        cout << endl<<"Menu:" << endl
            << "1. Add an element" << endl
            << "2.Remove an element by value" << endl
            << "3.Access an element at index" << endl
            << "4.Insert an element at index" << endl
            << "5.Insert an element after index" << endl
            << "6.Remove an element at index" << endl
            << "7.Print the linked list" << endl
            << "8.Print the size of the linked list" << endl
            << "9.Check if the linked list is empty" << endl
            << "10.Clear the linked list" << endl
            << "11.[TASK]Find Middle Node"<<endl
            << "12.[TASK]Get Smallest Node" << endl
            << "13.[TASK]Move Smallest to Front" << endl
            << "x.Exit" << endl;
        cin >> selectionString;
        if (selectionString != "x") {
            if (selectionString == "1") { // Doğru çalışıyor
                cout << "Adding Element:";
                string newelement;
                cin >> newelement;
                newlink.push_back(newelement);
            }
            else if (selectionString == "2") { // Doğru çalışıyor : Düzeltildi
                cout << "Removing Element by Value:";
                string removeelement;
                cin >> removeelement;
                newlink.erase(removeelement);
            }
            else if (selectionString == "3") { // Doğru çalışıyor
                cout << "Access an element at index:";
                int eindex;
                cin >> eindex;
                cout << "The element is:" << newlink.at(eindex) << endl;
            }
            else if (selectionString == "4") { // Doğru çalışıyor
                cout << "Insert an element at index:";
                int eindex;
                cin >> eindex;
                cout << "Value:";
                string newelement;
                cin >> newelement;
                newlink.insert_at(eindex, newelement);
            }
            else if (selectionString == "5") { // HATA VAR ÜSTÜNE YAZIYOR : Düzeltildi
                cout << "Insert an element after index:";
                int eindex;
                cin >> eindex;
                cout << "Value:";
                string newelement;
                cin >> newelement;
                newlink.insert_after(eindex, newelement);
            }
            else if (selectionString == "6") { // 0. INDEXI SİLMİYOR + DÜZGÜN ÇALIŞMIYOR : Düzeltildi
                cout << "Remove an element at index:";
                int eindex;
                cin >> eindex;
                newlink.erase_at(eindex);
            }
            else if (selectionString == "7") { // Doğru çalışıyor
                cout << "Linked List:" << newlink;
            }
            else if (selectionString == "8") { // Doğru çalışıyor
                cout << "Size of linked list:" << newlink.size();
            }
            else if (selectionString == "9") { // Doğru çalışıyor
                cout << "Is linked list empty:" << newlink.empty();
            }
            else if (selectionString == "10") { // Biraz yanlız çalışıyor : Düzeltildi
                cout << "Clearing linked list...";
                newlink.clear();
            }
            //ANA FONK BİTTİ TASKLERİ YAP
            else if (selectionString == "11") { // FIND MIDDLE
                cout << "The middle node data:" << newlink.findMiddleNode()->data;
            }
            else if (selectionString == "12") {
                cout << "The middle node data:" << newlink.getSmallestNode()->data;
            }
            else if (selectionString == "13") {
                newlink.moveSmallestToFront();
                cout << "The middle node data:" << newlink;
            }
            else {
                cout << "Invalid Selection, try again..." << endl;
            }

        }
        else if (selectionString == "x") exit(0);
        

    }
    
}
