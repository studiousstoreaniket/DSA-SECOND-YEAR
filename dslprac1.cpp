#include<iostream>
#include<string.h>
using namespace std;

 struct node
{
 int value;                            //hashtable containing 10 elements
  	node* next;                        
}*HashTable[10];                       //singly linkedlist for separate chaining

class hashing                           //class ---hashing
{
public:
hashing()                                //constructor
{
for(int i=0 ; i<10 ; i++)                //0 to 9
{
   		HashTable[i]=NULL;               //initalize hashtable to NULL
 	}
 }

int HashFunction(int value)             //to calculate hashfunction of each data values
{
  return (value%10);                    //table size=10
 }
 node* create_node(int x)	            //to create new node of linkedlist after collision occurs
{
 	 node* temp=new node;
  	temp->next=NULL;
  	temp->value=x;
  	return temp;
 }

 void display()                         //to display hashtable
{
 	 for(int i=0 ; i< 10; i++)
{
  	 	node * temp=new node;
   		temp=HashTable[i];
   		cout<<"a["<<i<<"] : ";
   		while(temp !=NULL)
{
    			cout<<" ->"<<temp->value;
    			temp=temp->next;
  		 }
   		cout<<"\n";
}
 }

int searchElement(int value)               //to search elements in hashtable
{
  	 bool flag = false;
              int hash_val = HashFunction(value);    //call hashfunction to calculate index position of 
              node* entry = HashTable[hash_val];      //element we are searching
              cout<<"\nElement found at : ";
              while (entry != NULL)
      	 {
                  	if (entry->value==value)          //if matching done
          		 {
                      		cout<<hash_val<<" : "<<entry->value<<endl;
                     		flag = true;
                 	 }
                  	entry = entry->next;          //next node will point as ''entry" node
              }
              if (!flag)                   //entry==NULL
              return -1;
 }

 void deleteElement(int value)             //to delete elment of given data value
{
  	 int hash_val = HashFunction(value);
              node* entry = HashTable[hash_val];
              if (entry == NULL )
              {
              	 cout<<"No Element found ";
                	  return;
              }

              if(entry->value==value)        //if entry node matches with node value to be deleted
{
               	HashTable[hash_val]=entry->next;   //then current will point to next
               	return;
              }
              while ((entry->next)->value != value)
       	{
                  entry = entry->next;
              }
              entry->next=(entry->next)->next;
 }

 void insertElement(int value)               //to insert element
{
  	 int hash_val = HashFunction(value);     //calculates index of element to be insert
                                               
              node* temp=new node;
              node* head=new node;
              head = create_node(value);
              temp=HashTable[hash_val];
              if (temp == NULL)
                           	   {
                              HashTable[hash_val] =head;
                               }
              else
{
              	 while (temp->next != NULL)
              	{
                	  temp = temp->next;
           		   }	
             		 temp->next =head;
              }
 }
};
int main()
{
 	int ch;
 int data,search,del;
 	hashing h;
 	do
{
cout<<"\nTelephone : \n1.Insert \n2.Display \n3.Search \n4.Delete \n5.Exit";
  		cin>>ch;
  		switch(ch)
{
  			case 1:cout<<"\nEnter phone no. to be inserted : ";
    				cin>>data;
h.insertElement(data);
   				 break;
  			case 2:h.display();
    				break;
  			case 3:cout<<"\nEnter the no to be searched : ";
    				cin>>search;

   				 if (h.searchElement(search) == -1)
                			{
             					cout<<"No element found at key ";
            					 continue;
                			}
    				break;
  			case 4:cout<<"\nEnter the phno. to be deleted : ";
   				 cin>>del;
   				 h.deleteElement(del);
   				  cout<<"Phno. Deleted"<<endl;
    				break;
  				}

 		}while(ch!=5);
 		return 0;
}        