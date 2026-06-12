#define _CRT_SECURE_NO_WARNINGS // SAAT HATASI VERİYOR KALDIRMAYIN
#include <iostream>
#include <fstream>
#include <filesystem>
#include "Node.h"
#include <vector>
#include <ctime>
#include <chrono>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"


using namespace std;
namespace fs = filesystem;
vector<string> scanForWord(const string& text);

void createIndex(const string& directory);

void addWordtoIndex(const string& word, const string& document, int lineNum); // bitti

void searchKeyword(const string& keyWord); // bitti
void listDocumentsContainingKeyword(const string& keyword); // bitti

void displayTopNMostFrequentWords(int N);
void displayTopNLeastFrequentWords(int N);

void displayWordFrequencyWithLineNumbers(const string& word); //bitti

void displayWordFrequencyInDocument(const string& word, const string& document); // bitti: gözükmesini ayarla

void displayOperationHistory(); // bitti

void logOperation(const string& action, const string& details); // bitti
struct logOp {
    string action;
    string details;
};
struct wordData
{
    string filename;
    vector<int> linenums;
    int freq;
    
};
class WNode : public Node<string> { // BU VECTORE ATILACAK
public:
    WNode(){}
    WNode(string n) :Node(n)/*datayı node'ye storageladım*/ {};
    vector<wordData> wd;
    int totfreq() {
        int i = 0;
        for (wordData& w : wd) {
            i += w.freq;
        }
        return i;
    }
};

vector<WNode*> WORDS;
vector<logOp*> operations;
void menu();
string getTime();
int main()
{
    string tmp;
    string path = "./dosyalar"; // CPP'NİN ÇALIŞTIĞI YERE DOSYALARI ATIN
    auto start = std::chrono::high_resolution_clock::now();
    
    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_regular_file()) {
            cout << "Reading: " << entry.path() << endl;
            string line = entry.path().string();
            createIndex(line);
        }
    }
    system("cls");
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "Indexing complated in: " << elapsed.count()/1000 << " s" << std::endl;
    menu();
}
void m_displaywordfreq();
void m_displayleastfreq();
void m_displaymostfreq();
void m_listwordfiles();
string getTime() {
    time_t now = time(0);
    tm* localtm = localtime(&now);

    string time = to_string(localtm->tm_hour) + ':' + to_string(localtm->tm_min);
    return time;
}
void menu() {
    cout <<endl <<  YELLOW <<"Menu Options" << RESET <<endl
        << "----------------------------------------------------------" << endl
        << "Simple Document Retrieval System" << endl
        << "1. Enter a Single Keyword to List The Document(s) (File Names)" << endl
        << "2. Display the Top N Words that Appeared Most Frequently" << endl
        << "3. Display the Top N Words that Appeared Least Frequently" << endl
        << "4. Display Word Frequency With Line Numbers" << endl
        << "5. Display Operation History" << endl
        << "6. Exit" << endl
        << "----------------------------------------------------------" << endl
        << YELLOW<< "Selection:" << RESET;
    
    int selection = 0;
    cin >> selection;
    switch (selection) {
    case 1:
        system("cls");
        m_listwordfiles();
        
        break;
    case 2:
        system("cls");
        m_displaymostfreq();
        break;
    case 3:
        system("cls");
        m_displayleastfreq();
        break;
    case 4:
        system("cls");
        m_displaywordfreq(); // bitti
        break;
    case 5:
        system("cls");
        displayOperationHistory();
        break;
    case 6:

        exit(0);
        break;
    default:
        system("cls");
        cout << "Invalid selection...";
        break;
    }
    menu();
}
void m_listwordfiles() {
    string word;
    cout << endl << "Enter word that you want to search:";
    cin >> word;

    searchKeyword(word);
    string details = "Searched " + word + ", at " + getTime() + ".";

    logOperation("m_listwordfiles", details);

    return;
}
void m_displaywordfreq() {
    string word;
    cout << endl << "Enter word that you want to display frequeny with line numbers :";
    cin >> word;

    displayWordFrequencyWithLineNumbers(word);

    string details = "Displayed " + word + " frequency with line numbers at " + getTime() + ".";
    logOperation("m_displaywordfreq", details);
    return;
}
void m_displaymostfreq() {
    int c;
    cout << endl << "Enter count that you want to display word frequency:"; // Açıklamaları düzelt
    cin >> c;
    if (c < 0 || c >65000) {
        cout << RED<< "Invalid number!" << RESET;
        return;
    }
    displayTopNMostFrequentWords(c);

    string details = "Displayed " + to_string(c) + " word frequency" + getTime() + "."; // Açıklamaları düzelt
    logOperation("m_displaymostfreq", details);
    return;
}

void m_displayleastfreq() {
    int c;
    cout << endl << "Enter count that you want to display word frequency:"; // Açıklamaları düzelt
    cin >> c;
    if (c < 0 || c >65000) {
        cout << RED << "Invalid number!" << RESET;
        return;
    }
    displayTopNLeastFrequentWords(c);

    string details = "Displayed " + to_string(c) + " word frequency" + getTime() + "."; // Açıklamaları düzelt
    logOperation("m_displayleastfreq", details);
    return;
}
vector<string> scanForWord(const string& text) {
    vector<string> words;
    string currentWord;

    for (char ch : text) {
        if (ch == ' ' || ch == ',') {
            if (!currentWord.empty()) {
                words.push_back(currentWord);
                currentWord.clear();
            }
        }
        else {
            currentWord += ch;
        }
    }
    if (!currentWord.empty()) {
        words.push_back(currentWord);
    }

    return words;
}
void createIndex(const string& directory)
{
    ifstream ReadFile(directory);
    string myText;
    int lineNum = 1;
    while (getline(ReadFile, myText)) {
        vector<string> sonuclar = scanForWord(myText);
        for (string& w : sonuclar) {
            addWordtoIndex(w, directory, lineNum);
        }
        lineNum++;
    }
}
void addWordtoIndex(const string& word, const string& pageNum, int lineNum) {
    string wrd = word;
    for (char& x : wrd) {
        x = tolower(x);
    }

    auto it = lower_bound(WORDS.begin(), WORDS.end(), wrd, [](const WNode* a, const string& b) { // Binary Search
        return a->data < b;
    });

    WNode* W = nullptr;
    
    if (it != WORDS.end() && (*it)->data == wrd) {
        W = *it;
    } 
    else {
        W = new WNode(wrd);
        WORDS.insert(it, W); 
    }
    if (!W->wd.empty() && W->wd.back().filename == pageNum) {
        W->wd.back().linenums.push_back(lineNum);
        W->wd.back().freq++;
    }
    else {
        wordData newData;
        newData.filename = pageNum;
        newData.linenums.push_back(lineNum);
        newData.freq = 1;

        W->wd.push_back(newData);
        
    }
}

void searchKeyword(const string& keyWord)
{
    auto start = std::chrono::high_resolution_clock::now();

    for (WNode* wd1 : WORDS) {
        if (wd1->data == keyWord) {
            cout <<BLUE << "Search Results" << RESET << ": " << endl
                <<BLUE<< "Keyword" << RESET << ": " << YELLOW << keyWord << RESET << endl
                << BLUE <<"Documents" << RESET << ":" << endl;
            for (wordData& wd2 : wd1->wd)
            {
                cout << "-" << RED << wd2.filename << RESET << endl;
            }
            break;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << GREEN<<"Complated in: " << elapsed.count() / 1000 << " s" <<  RESET<<std::endl;
}

void listDocumentsContainingKeyword(const string& keyword)
{
    auto start = std::chrono::high_resolution_clock::now();

    for (WNode* wd1 : WORDS)
    {
        if (wd1->data == keyword) {
            for (wordData wd2 : wd1->wd) {
                cout << "-" << wd2.filename;
            }
            cout << endl;
            break;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << GREEN << "Complated in: " << elapsed.count() / 1000 << " s" << RESET << std::endl;
}
int min(int left, int right) {
    if (left < right) return left;
    if (right < left) return right;
    return left;
}
void displayTopNMostFrequentWords(int N)
{
    auto start = std::chrono::high_resolution_clock::now();

    if (WORDS.empty()) {
        cout << RED << "Index is empty." << RESET << endl;
        return;
    }

    vector<pair<int, string>> freqlist;
    for (WNode* w : WORDS) {
        freqlist.push_back({ w->totfreq(), w->data });
    }

    sort(freqlist.begin(), freqlist.end(), greater<pair<int, string>>());

    cout << endl << GREEN << "Top " << N << " most frequent words:" << RESET << endl;

    int limit = min(N, freqlist.size());

    int maxFreq = freqlist.at(0).first;

    int bar_w = 20;

    for (int i = 0; i < limit; i++) {
        int currentFreq = freqlist.at(i).first;
        string currentWord = freqlist.at(i).second;

        int filledLength = 0;
        if (maxFreq > 0) {
            filledLength = (currentFreq * bar_w) / maxFreq;
        }

        string bar = "";
        for (int j = 0; j < bar_w; j++) {
            if (j < filledLength) {
                bar += "#";
            }
            else {
                bar += " ";
            }
        }

        cout << i + 1 << ". " << currentWord << " [" << bar << "] (" << RED <<currentFreq << "/" << maxFreq <<RESET << ")\n";
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << GREEN << "Complated in: " << elapsed.count() / 1000 << " s" << RESET << std::endl;
}

void displayTopNLeastFrequentWords(int N)
{
    auto start = std::chrono::high_resolution_clock::now();

    if (WORDS.empty()) {
        cout << RED << "Index is empty.";
    }

    vector <pair <int, string>> freqlist;
    for (WNode* w : WORDS) {
        freqlist.push_back({ w->totfreq(), w->data });
    }

    sort(freqlist.begin(), freqlist.end(), greater<pair<int, string>>());
    cout << endl << GREEN << "Top least frequent 5 words" << endl<< RESET;

    int bar_w = 20;
    int maxFreq = freqlist.at(0).first;
    int limit = min(N, freqlist.size());
    for (int i = 0; i < limit; i++) {
        int targetIndex = (freqlist.size() - 1) - i;

        int currentFreq = freqlist.at(targetIndex).first;
        string currentWord = freqlist.at(targetIndex).second;

        int filledLength = 0;
        if (maxFreq > 0) {
            filledLength = (currentFreq * bar_w) / maxFreq;
        }
        if (currentFreq > 0 && filledLength == 0) {
            filledLength = 1;
        }

        string bar = "";
        for (int j = 0; j < bar_w; j++) {
            if (j < filledLength) {
                bar += "#";
            }
            else {
                bar += " ";
            }
        }

        cout << i + 1 << ". " << currentWord << " [" << bar << "] (" << RED <<currentFreq << "/" << maxFreq << RESET <<")\n";
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << GREEN << "Complated in: " << elapsed.count() / 1000 << " s" << RESET << std::endl;
}

void displayWordFrequencyWithLineNumbers(const string& word)
{
    auto start = std::chrono::high_resolution_clock::now();

    for (WNode* wd1 : WORDS) {
        if (wd1->data == word) {
            cout << BLUE << "Frequency of " << YELLOW << word << ":"<< endl;
            for (wordData wd2 : wd1->wd)
            {
                cout << "-" << RED << wd2.freq << RESET << endl
                    << "Lines: " << endl;
                
                for (int i : wd2.linenums) {
                    cout << i << ",";
                }
                cout << endl;
            }
            break;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << GREEN << "Complated in: " << elapsed.count() / 1000 << " s" << RESET << std::endl;
    return;
}

void displayWordFrequencyInDocument(const string& word, const string& document)
{
    auto start = std::chrono::high_resolution_clock::now();

    for (WNode* wd1 : WORDS) {
        if (wd1->data == word) {
            for (wordData wd2 : wd1->wd)
            {
                if (wd2.filename == document) {
                    cout << wd2.freq;
                }
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << GREEN << "Complated in: " << elapsed.count() / 1000 << " s" << RESET << std::endl;
}

void displayOperationHistory()
{
    int i = 1;
    cout << endl;
    for (logOp* st : operations) {
        cout << i << ".Action:" << YELLOW << st->action << endl << RESET;
        cout << "-Details: "  << GREEN << st->details << endl << endl << RESET;
        i++;
    }
    return;
}

void logOperation(const string& action, const string& details)
{
    logOp* st = new logOp;
    st->action = action;
    st->details = details;
    operations.push_back(st);
    return;
}
