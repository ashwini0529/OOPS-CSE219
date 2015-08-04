#include<iostream>
#include<string.h>
using namespace std;

// Class

class student
{
	reg name age id
	public:
		char regno[15];
		char name[50];
		char email[50];
		int age;
		int isDuplicate();
		
		
};

int student::isDuplicate()
{
	
}
int main()
{
	student s[3];
	int i;
	for(i=0;i<3;i++)
	{
		
		cout<<"Enter Name : ";
		cin>>s[i].name;
		cout<<"Enter Registration Number : ";
		cin>>s[i].regno;
		cout<<"Enter Email ID: ";
		cin>>s[i].email;
		cout<<"Enter age: ";
		cin>>s[i].age;
		
	}
	
	
}

