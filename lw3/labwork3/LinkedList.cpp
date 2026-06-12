#include "LinkedList.h"

static string emptyString = "";
static Node* emptyNode = new Node("");
LinkedList::LinkedList() :head(nullptr)
{
}

LinkedList::LinkedList(const LinkedList& other)
{
	Node* Temp;
	if (other.head != nullptr)
	{
		this->head = new Node(other.head->data); // YENİ HEAD OLUŞTURDU
		Node* wc = this->head; // WALK1 HEADİMİZ OLDU
		Node* w = other.head->next; // WALK2 OTHER HEADİNDEN DEVAM ETTİ
		while (w != nullptr) {
			wc->next = new Node(w->data); // WALK1İN NEXTİ YENİ WALK2NİN DATASI OLDU
			w = w->next; // WALK2 NEXTE GEÇİLDİ
			wc = wc->next; //WALK1, WALK1İN NEXTİNE GEÇİLDİ
		}
	}
}

LinkedList::~LinkedList()
{
	this->clear();
}

string& LinkedList::at(int index) { //TAMAM
	//1. İndex sayısını kontrol et 2.başlangıç null mu kontrol et 3. Gidene kadar null mu kontrol et
	Node* walk;
	if (index < 0) return emptyString;

	if (this->head == nullptr) return emptyString;
	walk = this->head;
	int count = 0;
	while (walk != nullptr) {
		if (index == count)return walk->data;
		count++;
		walk = walk->next;
	}
	return emptyString;

}

string& LinkedList::front() { //TAMAM
	if (this->head != nullptr)
	{
		return head->data;
	}
	return emptyString;
}

string& LinkedList::back() { //TAMAM
	if (this->head == nullptr) return emptyString;
	if (this->head->next == nullptr) return this->head->data;
	Node* walk = this->head;

	while (walk->next != nullptr) {
		walk = walk->next;
	}
	return walk->data;
}

void LinkedList::push_back(const string& value) { //TAMAM
	Node* newNode = new Node(value);
	if (this->head == nullptr)
	{
		this->head = newNode;
		return;
	}

	Node* walk = this->head;
	if (walk->next == nullptr) {
		walk->next = newNode;
		return;
	}
	while (walk->next != nullptr) {
		walk = walk->next;
	}
	walk->next = newNode;
}

void LinkedList::pop_back() { // ÇALIŞMIYOR
	if (this->head == nullptr) return;
	if (this->head->next == nullptr) { this->head == nullptr; return; }
	Node* walk = this->head;

	Node* walk1 = this->head->next;
	while (walk1->next != nullptr) {
		walk = walk->next;
		walk1 = walk1->next;
	}
	walk->next == nullptr;
}

void LinkedList::push_front(const string& value) //TAMAM
{
	Node* newNode = new Node(value);
	if (this->head != nullptr){
		newNode->next = this->head;
		this->head = newNode;
	}
	else this->head = newNode;
	return;
}

void LinkedList::pop_front() //TAMAM
{
	if (this->head != nullptr) this->head = this->head->next;
	return;
}

void LinkedList::insert_at(int index, const string& value) { //SON İNDEXTE YERİNE KOYMUYOR. ONA BAK
	if (this->size() < index) return;
	Node* newNode = new Node(value);
	Node* walk = this->head;
	if (index == 0) {
		newNode->next = this->head;
		this->head = newNode;
		return;
	}
	if (walk->next == nullptr && index == 1) {
		walk->next = newNode;
		return;
	}
	int count = 2; //INDEX 0 ŞARTI KOY
	while (walk != nullptr) {
		if (count > index) {
			newNode->next = walk->next;
			walk->next = newNode;
			return;
		}
		walk = walk->next;
		count++; //BUNA DA BAK
	}
	return;
	
	
}

void LinkedList::insert_after(int index, const string& val) // INDEX 1 DE HATA, DAHA SONRA BAK
{
	if (index < 0 || head == nullptr) return;
	Node* newNode = new Node(val);
	Node* walk = this->head;
	int count = 0;
	while (walk != nullptr && count < index) {
		walk = walk->next;
		count++;
	}
	if (walk != nullptr)
	{
		newNode->next = walk->next;
		walk->next = newNode;
	}
	return;
}

void LinkedList::erase_at(int index) { //BOZUK DÜZELTİLDİ


	if (index < 0 || head == nullptr) return;
	Node* temp = head;

	if (index == 0) {
		head = head->next;
		delete temp;
		return;
	}
	Node* walk = nullptr;
	int count = 0;
	while (temp != nullptr && count < index) {
		walk = temp;
		temp = temp->next;
		count++;
	}
	if (temp == nullptr) return;
	
	walk->next = temp->next;
	delete temp;


}


void LinkedList::erase(const string& e) // DOĞRU ÇALIŞMIYOR
{
	
	if (head == nullptr) return;
	if (head->data == e) {
		Node* temp = head;
		head = head->next;
		delete temp;
		return;
	}
	Node* walk1 = head;
	Node* walk2 = head->next;
	while (walk2 != nullptr) {
		if (walk2->data == e) {
			walk1->next = walk2->next;
			delete walk2;
			return;
		}
		walk1 = walk2;
		walk2 = walk2->next;
	}
}

void LinkedList::clear() //TAMAM
{

	Node* walk = head;
	while (walk != nullptr) {
		Node* nextNode = walk->next;
		delete walk;
		walk = nextNode;
	}
	head = nullptr;
}

int LinkedList::size() const // TAMAM
{
	if (this->head == nullptr) return 0;
	Node* walk = this->head;
	int count = 1;
	while (walk->next != nullptr) {
		count++;
		walk = walk->next;
	}
	return count;
}
bool LinkedList::empty() const { //TAMAM

	return head == nullptr;
}

Node* LinkedList::findMiddleNode() // TAMAM
{
	int siz = this->size();
	if (siz == 0) return emptyNode;
	Node* walk = head;
	if (siz % 2) {
		for (int i = 0; i < siz/2 ; i++) {
			walk = walk->next;
		}
		return walk;
	}
	else
	{
		for (int i = 0; i < (siz / 2); i++) {
			walk = walk->next;
		}
		return walk;
	}
	return emptyNode;
}

Node* LinkedList::getSmallestNode() // SMALLI ÇEK
{
	if (head == nullptr) return nullptr;
	Node* smallest = head;
	Node* walk = head->next;
	while (walk != nullptr) {
		if (walk->data < smallest->data)smallest = walk;
		walk = walk->next;
	}
	return smallest;
}

void LinkedList::moveSmallestToFront()
{
	
	Node* smallestNode = getSmallestNode(); // SMALLESTİN DEVAMINDAN ÇEKİP ÇIKARTMAK LAZIM, LİNKİ DEVAM ETTİR
	if (this->head == nullptr) return; // HEAD ZATEN BOŞSA SG
	Node* beforesmallest = head;
	if (this->head->next != nullptr) {
		while (beforesmallest->next != nullptr) {
			if (beforesmallest->next == smallestNode) break;
			beforesmallest = beforesmallest->next;
		}
		beforesmallest->next = smallestNode->next;
		smallestNode->next = head;
		head = smallestNode;
	}
	return;
}

LinkedList& LinkedList::operator=(const LinkedList& lhs) //TAMAMIMSI
{
	Node* newHead = new Node(lhs.head->data);
	Node* lhsWalk = lhs.head;
	clear();
	this->head = newHead;
	while (lhsWalk != nullptr) {
		Node* newNode = new Node(lhsWalk->data);
		newHead->next = newNode;
		newHead = newHead->next;
		lhsWalk = lhsWalk->next;
	}
	this->pop_front(); //çok üşendim bunu kaldırmayı unutma
	return *this;
}


bool LinkedList::operator==(const LinkedList& lhs) const // TAMAM
{
	Node* walk1 = this->head;
	Node* walk2 = lhs.head;
	if (walk1 == nullptr || walk2 == nullptr) return false;
	while (walk1 != nullptr && walk2 != nullptr) {
		if (walk1->data != walk2->data) {
			return false;
		}
		walk1 = walk1->next;
		walk2 = walk2->next;
	}
	return true;
}

ostream& operator<<(ostream& out, const LinkedList& list) { // TAMAM
	Node* walk = list.head;
	if (walk == nullptr) {
		out << "";
		return out;
	}
	while (walk != nullptr) {
		out << "->" << walk->data;
		walk = walk->next;
	}
	return out;
}
