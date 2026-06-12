#include <iostream>
#include <cmath>
#include "StackH.h"
#include "StackH.cpp"

using namespace std;

class expression {
public:
    void setInfix(string);
    void showInfix();
    void showPosfix();
    void convertToPostfix();
    Stack<char> exp;
    int precedence(char); // Bu ne boka yarıyor amk
private:
    string infix = "";
    string postfix = "";
};


void expression::setInfix(string den)
{
    infix = den;
    convertToPostfix();
}

void expression::showInfix()
{
    cout << "Infix:" << infix << endl;
}

void expression::showPosfix()
{
    cout << "Postfix:" << postfix << endl;
}

void expression::convertToPostfix()
{
    //string infix = "(A+B)*C"; // buradan çek
    // KURAL 1 PFX'İ TEMİZLİYORMUŞUZ AMK
    postfix = ""; // sym sembol mu amk
    for (int i = 0; i < infix.size(); i++) {
        char sym = infix[i];
        if ((sym >= 'a' && sym <= 'z') || (sym >= 'A' && sym <= 'Z') || (sym >= '0' && sym <= '9')) {
            postfix += sym;
        }
        else if (sym == '(') exp.push(sym);
        else if (sym == ')') {
            while (!exp.isEmpty() && exp.getTop() != '(') {
                postfix += exp.pop();
            }
            if (!exp.isEmpty()) {
                exp.pop();
            }
        }
        else {
            while (!exp.isEmpty() && exp.getTop() != '(' && precedence(exp.getTop() >= precedence(sym))) {
                postfix += exp.pop();
            }
            exp.push(sym);

        }

    }
    while (!exp.isEmpty()) {
        postfix += exp.pop();
    }
}

int expression::precedence(char islem)
{
    if (islem == '^') return 3;
    else if (islem == '/' || islem == '*') return 2;
    else if (islem == '+' || islem == '-') return 1;
    else return -1;
}

 
class BinToDec {
    Stack<int> Items;
    int digCount = 0;
public:
    void inputBin(string val) {
        int val2 = val.size();
        for (int i = 0; i < val.size(); i++) {
            
            Items.push(int(val[i]-'0'));
        }
        cout << val << ":" << convertBinToDec(val.size()) << endl;
    }
    //void inputval(int val) { // BUNU YANLIŞ ANLAYIP YAPMIŞIM, SADECE BİNARY GÖNDERECEKMİŞİZ :: BU EKSTRA
    //    int tempval = val;
    //    
    //    for (int i = 0; i < 8; i++) {
    //        Items.push(tempval % 2);
    //        digCount++;
    //        
    //        tempval = tempval / 2;
    //    }

    //}
    int convertBinToDec(int digcount) {
        int sum = 0;
        for (int i = 0; i < digcount; i++) {
            int dig = Items.pop();
            int p = pow(2, i);
            sum += (dig) * p;
            digCount--;
        }
        return sum;
    }
};



int main()
{
    //Stack s;

    //s.push(12);
    //s.push(3);
    //s.push(33);
    //while (!s.isEmpty())
    //    cout << s.pop() << endl;
    expression exp1,exp2,exp3,exp4, exp5;
    cout << "Postfix calculator:" << endl;
    exp1.setInfix("A+B-C");
    exp2.setInfix("(A+B)*C");
    exp3.setInfix("(A+B)*(C-D)");
    exp4.setInfix("A+((B+C)*(E-F)-G)/(H-I)");
    exp5.setInfix("A+B*(C+D)-E/F*G+H");
    
    //exp1.showInfix();
    exp1.showInfix();
    exp1.showPosfix();
    exp2.showInfix();
    exp2.showPosfix();
    exp3.showInfix();
    exp3.showPosfix();
    exp4.showInfix();
    exp4.showPosfix();
    exp5.showInfix();
    exp5.showPosfix();

    cout << endl << "Binary to Decimal " << endl;
    BinToDec a1;
    string bin;
    while (true) {
        cout << "Binary:";
        cin >> bin;
        for (int i = 0; i < bin.size(); i++) {
            if (bin[i] != '0' && bin[i] != '1') {
                cout << "Invalid key" << endl;
                return 0;
            }
            
        }
        a1.inputBin(bin);
    }
    //int input = 0;
    //while (true) { // DEC TO BINARY TO DEC
    //    cin >> input;

    //    if (input > 255 || input < 0) {
    //        cout << "Invalid value." << endl;
    //        continue;
    //    }
    //    a1.inputval(input);
    //    cout << endl << a1.convertBinToDec() << endl;
    //}
    
    return 0;
}