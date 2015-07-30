#include<iostream>
#include<string.h>
using namespace std;
struct movies
{
	char name[50];
	char actor[50];
	int year;
	float rating;
};

void palaindrome(struct movies sptr[], int n)
{
	int i;
	char temp[50];
	for (i=0;i<n;i++)
	{
		strcpy(temp,strrev(sptr[i].name));
		if(strcmp(temp,sptr[i].name)==0)
		{
			cout<<"\n"<<temp<<" is a palaindrome";
		}
	}
}

int main()
{
	struct movies m[5];
	for(int i=0;i<5;i++)
	{
		cout<<"Enter movie name : ";
		cin>>m[i].name;
		cout<<"Enter Actor: ";
		cin>>m[i].actor;
		cout<<"Enter Year : ";
		cin>>m[i].year;
		cout<<"Enter Rating :";
		cin>>m[i].rating;
	}

	palaindrome(m,5);
	
}
