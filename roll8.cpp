#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class student{
typedef struct stud
{
int roll;
char name[10];
char div;
char add[10];
}stud;
stud rec;
public:
void create();
void display();
int search();
void Delete();
};
void student::create()
{
char ans;
ofstream fout;
fout.open("stud.txt",ios::out|ios::binary);
do
{
cout<<"Enter Roll no of student :";
cin>>rec.roll;
cout<<"Enter name of the student :";
cin>>rec.name;
cout<<"Enter division of student :";
cin>>rec.div;
cout<<"Enter address of the student :";
cin>>rec.add;
fout.write((char*)&rec,sizeof(stud))<<flush;
cout<<"Do you want to continue ";
cin>>ans;
}
while(ans=='y'||ans=='Y');
fout.close();
}
void student::display()
{
ifstream fin;
fin.open("stud.txt",ios::in|ios::binary);
fin.seekg(0,ios::beg);
cout<<"Content of file are :";
cout<<"\n\tRoll\tName\tDiv\tAddress";
while(fin.read((char*)&rec,sizeof(stud)))
{
if(rec.roll!=-1)
cout<<"\n\t"<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add;
}
fin.close();
}
int student::search()
{
int r,i=0;
ifstream fin;
fin.open("stud.txt",ios::in|ios::binary);
fin.seekg(0,ios::beg);
cout<<"Enter the roll no to be search or to be deleted";
cin>>r;
while(fin.read((char*)&rec,sizeof(stud)))
{
if(rec.roll==r)
{
cout<<"Record found";
cout<<"\n\tRoll\tName\tDiv\tAddress";
cout<<"\n\t"<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add;
return i;
}
i++;

}

fin.close();
return -1;
}
void student::Delete()
{
int pos;
pos=search();
fstream f;
f.open("stud.txt",ios::in|ios::binary);
f.seekg(0,ios::beg);
if(pos==-1)
{
cout<<"record are no found";
return;
}
int offset=pos*sizeof(stud);
f.seekp(offset);
rec.roll=-1;
strcpy(rec.name,"NULL");
rec.div='N';
strcpy(rec.add,"NULL");
f.write((char*)&rec,sizeof(stud));
f.seekg(0);
f.close();
cout<<"Record deleted ";
}
 int main()
 {
 student obj;
	int ch,key;
	char ans;
	do
	  {
		cout<<"\n\t***** Student Information *****";
		cout<<"\n\t1. Create\n\t2. Display\n\t3. Delete\n\t4. Search\n\t5. Exit";
		cout<<"\n\t..... Enter Your Choice: ";
		cin>>ch;
		switch(ch)
		  {
			case 1: obj.create();
				break;
			case 2:	obj.display();
				break;
			case 3: obj.Delete();
				break;
			case 4: key=obj.search();
				if(key==-1)
				  cout<<"\n\tRecord Not Found...\n";
				break;
			case 5:
				break;
		  }
		cout<<"\n\t..... Do You Want to Continue in Main Menu: ";
		cin>>ans;
	  }while(ans=='y'||ans=='Y');
return 1;
  }