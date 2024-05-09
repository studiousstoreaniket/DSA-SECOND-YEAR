#include<iostream>
#include<cstring>
using namespace std;

class flight
{
public:
    int am[10][10];
    char city_index[10][10];
    flight();
    int create();
    void display(int city_count);
};

flight::flight()
{
    int i,j;
    for(i=0;i<10;i++)
    {
        strcpy(city_index[i],"xx");
    }
    for(j=0;j<10;j++)
    {
        am[i][j]=0;
    }
}

int flight::create()
{
    int city_count=0,j,si,di,wt;
    char s[10],d[10],c;
    do
    {
        cout<<"\n Enter Source city: ";
        cin>>s;
        cout<<"\n enter destination city:";
        cin>>d;
        for(j=0;j<10;j++)
        {
            if(strcmp(city_index[j],s)==0)
                break;
        }
        if(j==10)
        {
            strcpy(city_index[city_count],s);
            city_count++;
        }
        for(j=0;j<10;j++)
        {
            if(strcmp(city_index[j],d)==0)
                break;
        }
        if(j==10)
        {
            strcpy(city_index[city_count],d);
            city_count++;
        }
        cout<<"\n\tENTER distance from "<<s<<" to "<<d<<":";
        cin>>wt;
        for(j=0;j<10;j++)
        {
            if(strcmp(city_index[j],s)==0)
                si=j;
            if(strcmp(city_index[j],d)==0)
                di=j;
        }
        am[si][di]=wt;
        cout<<"\n\t do you want to enter more cities (y/n) :";
        cin>>c;
    }
    while(c=='y'||c=='Y');
    return(city_count);
}

void flight::display(int city_count)
{
    int i,j;
    cout<<"\n\t DISPLAYING distance matrix";
    for (i=0;i<city_count;i++)
    {
        cout<<"\t"<<city_index[i];
    }
    cout<<"\n";
    for (i=0;i<city_count;i++)
    {
        cout<<"\t"<<city_index[i];
        for(j=0;j<city_count;j++)
        {
            cout<<"\t"<<am[i][j];
        }
        cout<<"\n";
    }
}

int main()
{
    flight f;
    int n,city_count;
    char c;
    do
    {
        cout<<"\n\t****||||*******FLIGHT MENU********||||****";
        cout<<"\n\t 1.Create \n 2.DISPLAY \n 3.EXIT";
        cout<<"\n ENter your choice : ";
        cin>>n;
        switch(n)
        {
            case 1:
                city_count=f.create();
                break;
            case 2:
                f.display(city_count);
                break;
            case 3:
                exit(0);
                break;
        }
        cout <<"\n\t DO U WANT TO CONTINUE(y/n)";
        cin>>c;
    }
    while(c=='y'||c=='Y');
    return 0;
}
