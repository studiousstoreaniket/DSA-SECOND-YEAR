#include<iostream>
using namespace std;

class Node{
public:
	Node* next = NULL;
	string prn = "";
	string name = "";

	Node(string gprn, string gname){
		prn = gprn;
		name = gname;
	}
};

class LL{
public:
	Node* head = NULL;

	void insert(string prn, string name, int priority){
		// priority 0 - p, 1-s, 2-m

		Node temp(prn,name);
		// Node* temp = new Node(prn,name);

		if(head == NULL){
			head = &temp;
			return;
		}

		switch(priority){
			case 0:
				temp.next = head;
				head = &temp;
				break;
			case 1:
				temp.next = head->next;
				head->next = &temp;
				break;
			case 2:
				{
					Node* c = head;
					while(c->next != NULL){
						c = c->next;
					}
					c->next = &temp;
				}
				break;
			default:
				break;
		}
	}

	void display(){
		if(head == NULL){
			cout << "LL is empty." << endl;
		}else if(head->next == NULL){
			cout << head << endl;
		}

		cout << "Printing LL..." << endl;

		Node* cur = head;

		while(cur->next != NULL){
			cout << "printing head" << endl;
			cout << cur->prn << " " << cur->name << endl;
			cur = cur->next;
		}
		cout << cur->prn << " " << cur->name << endl;

	}
};




int main(){
	LL l;
	l.insert("p1","n1",1);
	l.insert("p1","n1",1);
	l.display();


}
