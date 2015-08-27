using namespace std;
#include<iostream>
#include<string.h>
#include<conio.h>
class student
{
    char regno[10],name[10],id[25];
    int age;
public:
    void input()
    {
        cout<<"enter the regno\n";
        cin>>regno;
    }
    void forw()
    {
        cout<<"\nenter the name\n";
        cin>>name;
        cout<<"\nenter email id\n";
        cin>>id;
        cout<<"\nenter the age\n";
        cin>>age;
    }
    int check(student *stu,int n)
{
    int i,c=0;
    for(i=0;i<n;i++)
    {
        if(strcmp(stu[i].regno,stu[n].regno)==0)
        {
            cout<<"\nAlready registered\n\n";
            c=1;
        }
        return c;
    }
}
};
int main()
{
    student stu[20];
    int i,j;
    for(i=0;i<20;)
    {   stu[i].input();
        j=stu[i].check(stu,i);
        if(j!=1)
            {
                stu[i].forw();
                i++;
            }
    }
getch();
}
