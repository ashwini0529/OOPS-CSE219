#include<iostream>
using namespace std;

class account
{
	public:
		
		int accno;
		char name[50];
		float balance;
		struct transactions
		{
			int transaction[5]={0};
		};
		void deposit();
		void withdraw();
		void display();
};

void account::deposit()
{
	float amount;
	cout<<"Enter amount to be deposited: ";
	cin>>amount;
	balance=balance+amount;
	cout<<"Final balance :"<<balance;

}
void account::withdraw()
{
	float amount;
	cout<<"Enter amount to be withdrawed: ";
	cin>>amount;
	balance=balance-amount;
	cout<<"Final balance :"<<balance;
}

int main()
{
	account acct[3];
	for(int i=0;i<3;i++)
	{
		cout<<"Details of Person "<<i+1<<": \n";
		cout<<"Enter Name :";
		cin>>acct[i].name;
		cout<<"Enter Account Number: ";
		cin>>acct[i].accno;
		cout<<"Enter Balance: ";
		cin>>acct[i].balance;
		
	}
	int accountNo;
	//To deposit the money..
	cout<<"Enter Account number to deposit money: ";
	cin>>accountNo;
	for(int i=0;i<3;i++)
	{
		if(acct[i].accno==accountNo)
		{
			acct[i].deposit();
		}
	}
		//To Withdraw the money..
	cout<<"\nEnter Account number to withdraw money: ";
	cin>>accountNo;
	for(int i=0;i<3;i++)
	{
		if(acct[i].accno==accountNo)
		{
			acct[i].withdraw();
		}
	}
	
}
