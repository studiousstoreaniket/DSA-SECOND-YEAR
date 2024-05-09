#include<iostream>
using namespace std;

class Stack{
public:
    const static int size = 100;
    int top = -1;
    char array[size];

    void push(char x){
        if(top == size-1){
            cout << "Stack Overflow!!";
            return;
        }

        array[++top] = x;
    }

    char pop(){
        if(top == -1){
            cout << "Stack Underflow!!";
            return -1;
        }

        return array[top--];
    }

    void display(){
        if(top == -1){
            cout << "Stack is Empty";
        }

        cout << "Stack contains: ";
        for(int i = 0; i <= top; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main(){

    Stack s;
    
    string user_input;

    cout << "Enter a string: ";
    getline(cin,user_input);

    string org_str = "";

    for(int i = 0; i < user_input.size(); i++){

        char ch = user_input[i];

        if(ch >= 'a' and ch <= 'z'){
            ch = (char)(ch - 'a' + 'A');
        }
        if(ch >= 'A' and ch <= 'Z'){
            s.push(ch);
            org_str.push_back(ch);
        }
        

    }

    // s.display();


    cout << "Original string: " << org_str << endl;

    
    string rev_str = "";
    while(s.top != -1){
        rev_str.push_back(s.pop());
    }
    cout << "Reversed string: " << rev_str << endl;


    bool is_palindrome = true;
    for(int i = 0; i < org_str.size(); i++){
        if(org_str[i] != rev_str[i]){
            is_palindrome = false;
            break;
        }
    }

    cout << user_input << " is " << (is_palindrome ? "" : "not ") << "a palindrome.";

}