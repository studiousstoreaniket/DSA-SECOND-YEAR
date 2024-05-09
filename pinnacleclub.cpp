#include<iostream>
using namespace std;

class Node{
public:
	string name = "";
	string prn = "";
	Node* next = NULL;

	Node(string sname, string sprn){
		name = sname;
		prn = sprn;
	}
};

Node* head = NULL;

void add_president(string name="President",string prn="111"){
	Node* temp = new Node(name,prn);
	if(head == NULL){
		head = temp;
	}
}

void add_secretary(string name="Secretary",string prn="999"){
	Node* temp = new Node(name,prn);
	
	Node* cur = head;
	while(cur->next != NULL){
		cur = cur->next;
	}

	cur->next = temp;
}

void add_member(string name="Member",string prn="555"){
	Node* temp = new Node(name,prn);
	
	temp->next = head->next;
	head->next = temp;
}


void display_list(Node* head){
	cout << "#########################" << endl;
	Node* cur = head;
	while(cur->next != NULL){
		cout << cur->name << " " << cur->prn << " " << cur->next << endl;
		cur = cur->next;
	}

	cout << cur->name << " " << cur->prn << " " << cur->next << endl;	
	cout << "#########################" << endl;
}


int main(){
	add_president();
	add_secretary();
	add_member("1");
	add_member("2");
	add_member("3");
	display_list(head);
	
}