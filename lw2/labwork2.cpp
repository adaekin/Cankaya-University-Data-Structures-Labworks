#include <iostream>


using namespace std;


void menu();
void create(int value);
void read();
void update(int index, int newValue);
void deleteElement(int index);
void resizeArray();

int* arrptr;
int arrsize = 0, howmanyitem = 0;
    void initializeArray() {
    arrptr = new int[2];
    arrsize = 2;
    howmanyitem = 0;
    for (int i = 0; i < arrsize; i++) {
        arrptr[i] = -1;
    }
    
}
void menu() {
    while (true) {
        cout << "--MENU--" << endl
            << "1.Create(Add Element)" << endl
            << "2.Read(List Elements)" << endl
            << "3.Update Element" << endl
            << "4.Delete Element" << endl
            << "5.Exit" << endl << endl
            << "Enter Your Choice:";
        int selection = 0;
        cin >> selection;
        int val = 0, id = 0;
        switch (selection) {

        case 1:
            cout << "Enter your value to add:";
            cin >> val;
            create(val);

            break;
        case 2:
            cout << "Array Elements:";
            read();
            break;
        case 3:
            
            cout << "Enter your index to update:";
            cin >> id;
            cout << "Enter your value:";
            cin >> val;
            update(id, val);//DEĞİŞTİR
            break;
        case 4:
            cout << "Enter the index to delete (0-" << howmanyitem << "):";
            cin >> id;
            deleteElement(id);//DEĞİŞTİR
            break;
        case 5:
            cout << "Exitting program";
            delete[](arrptr);
            cout << "Memory freed.";

            exit(1);
            break;
        }
    }
    
    
}
void create(int value) {
    if (arrsize > howmanyitem) {
        arrptr[howmanyitem] = value;
        howmanyitem++;
        cout << endl<< "Element added successfully!";
        return;
    }
    else {
        resizeArray();
        create(value);
        return;
    }
}
void read() {
    for (int i = 0; i < howmanyitem; i++) {
        
        if (arrptr[i] == -1) {
            cout << "[DELETED], ";
        }
        else
        {
            cout << arrptr[i] << ", ";
        }
    }
}
void update(int index, int newValue) {
    if (index < arrsize && index >= 0) {
        arrptr[index] = newValue;
    }
    else {
        cout << "Invalid index, returning to menu..."<< endl;
        menu();
    }
}
void deleteElement(int index) {
    if (index < arrsize && index >= 0) {
        arrptr[index] = -1;
        cout << "Element deleted!";
    }
    else {
        cout << "Invalid index, returning to menu..." << endl;
        menu();
    }
}
void resizeArray() {
    int newsize = arrsize * 2;
    int* temp = new int[newsize];
    for (int i = 0; i < arrsize; i++) {
        temp[i] = arrptr[i];
    }
    delete[](arrptr);
    arrptr = temp;
    arrsize = newsize;
    return;
    
}
int main()
{
    initializeArray();
    menu();
}
