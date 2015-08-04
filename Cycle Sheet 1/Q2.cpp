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
			int transaction[5];
		}myTransactions;
		void deposit();
		void withdraw();
		void display();
		void displayAllTransactions();
};
void account::displayAllTransactions()
{
	for(int i=0;i<3;i++)
	{	
		cout<<"Account "<<i+1<<"'s details: \n";
		for(int j=0;j<5;j++)
		{
		
		cout<<myTransactions.transaction[j];
	
		}
	}

}

void account::deposit()
{
	float amount;
	cout<<"Enter amount to be deposited: ";
	cin>>amount;
	balance=balance+amount;
	cout<<"Final balance :"<<balance;
	int flag=0;
	for(int j=0;j<5;j++)
		{
			if(myTransactions.transaction[j]==0&&flag!=1)
			{
			
				myTransactions.transaction[j]=amount;		
				flag=1;
				break;
			}
		}

}
void account::withdraw()
{
	float amount;
	cout<<"Enter amount to be withdrawed: ";
	cin>>amount;
	balance=balance-amount;
	cout<<"Final balance :"<<balance;
	int flag=0;
	int amountNew=-amount;
	for(int j=0;j<5;j++)
		{
			if(myTransactions.transaction[j]==0&&flag!=1)
			{
			
				myTransactions.transaction[j]=amountNew;		
				flag=1;
				break;
			}
		}
}
void account::display()
{
	cout<<"Name :"<<name<<endl;
	cout<<"Account Number: "<<accno;
	cout<<"\nBalance: "<<balance;
}

int main()
{
	

	account acct[3];
// Initialize all the elements to 0 of structure
for(int i=0;i<3;i++)
	{
		for(int j=0;j<5;j++)
		{
		
		acct[i].myTransactions.transaction[j]=0;
	
		}
	}

	
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
	// To display the details of an account
	cout<<"\nEnter Account number to display details: ";
	cin>>accountNo;
	for(int i=0;i<3;i++)
	{
		if(acct[i].accno==accountNo)
		{
			acct[i].display();
		}
	}
	// To display all details
	cout<<"\n Display all transactions :\n";
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<5;j++)
		{
		if(acct[i].myTransactions.transaction[j]!=0)
		cout<<"Transaction "<<j+1<<" "<<acct[i].myTransactions.transaction[j]<<endl;
	
		}
	}
	
}
