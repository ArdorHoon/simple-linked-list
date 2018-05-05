#include <iostream>
#include <string>

using namespace std;

class Node //create node
{
public:

	Node* next;

	string Book_name;
	int year;
	int price;

};

class LinkedList //list class
{
public:
	int length;
	Node* head;
	Node* tail;

	LinkedList(); 
	~LinkedList();
	void add(string Book_name, int year, int price); 
	void ldelete(string Book_name); 
	void print(); 
};

LinkedList::LinkedList() {
	length = 0;
	head = tail = NULL;
}

LinkedList::~LinkedList() {
	std::cout << "LIST DELETED";
}
void LinkedList::ldelete(string Book_name)
{
	Node* remove = head;
	Node* temp1 = NULL;

	while (remove != NULL)
	{

		if (remove->Book_name == Book_name && temp1 != NULL) //else delete
		{
			temp1->next = remove->next;
			free(remove);
			break;
		}
		else if (remove->Book_name == Book_name && temp1 == NULL) //delete first node 
		{
			head = remove->next;
			free(remove);
			break;
		}
		else
		{
			temp1 = remove; //store before node
			remove = remove->next;
		}
	}

}

void LinkedList::add(string Book_name, int year, int price) {
	Node* node = new Node();
	node->Book_name = Book_name;
	node->year = year;
	node->price = price;

	if (head == NULL)
	{
		head = node;
		tail = node;
	}
	else
	{
		tail->next = node;
		tail = node;
	}
	length++;
}

void LinkedList::print() {

	Node* search = head;

	while (search != NULL) {

		std::cout << "book name :" << search->Book_name << " year:" << search->year << " price:" << search->price << endl;
		search = search->next;
	}
}




int main()
{
	LinkedList* list = new LinkedList();

	int exit = 0;
	int tell;
	string book_name; int year; int price;


	while (exit != 1)
	{
		cout << "1. add  2. delete  3. print 4. quit" << endl;
		cout << "input>>";
		cin >> tell;

		switch (tell)
		{
		case 1:
			cin >> book_name;
			cin >> year;
			cin >> price;
			list->add(book_name, year, price);
			break;
		case 2:
			cin >> book_name;
			list->ldelete(book_name);
			break;
		case 3:
			list->print();
			break;
		case 4:
			exit = 1;
			break;
		default:
			cout << "false input data!!" << endl;
			break;
		}
	}
	return 0;
}