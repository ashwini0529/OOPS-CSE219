#include<iostream>
#include<string.h>
using namespace std;

struct user
{
	char name[50];
	int id;
	char password[50];
	char sec_que[50];
	int isPurchased[3];
};

struct product
{
	int id;
	int qty;
	float price;
	char productName[50];

};
//Function to display all products 

void displayProducts(struct product sptr[],int n)
{
  int i;
  for(i=0;i<n;i++)
  {
  	cout<<"Product ID: "<<sptr[i].id<<endl;
  	cout<<"Product Quantity: "<<sptr[i].qty<<endl;
  	cout<<"Product Price: "<<sptr[i].price<<endl;
  	cout<<"Product Name: "<<sptr[i].productName<<endl;
	
  }
}

int main()
{
	//initializing 3 dummy users..
	struct user u[3];
	struct product p[3];
	cout<<"Enter user details";
	for(int i=0;i<3;i++)
	{	
		cout<<"\nEnter User ID: ";
		cin>>u[i].id;
		cout<<"\nEnter User Name: ";
		cin>>u[i].name;
		cout<<"\nEnter User Password: ";
		cin>>u[i].password;
		cout<<"\nEnter secret question: ";
		cin>>u[i].sec_que;
	}
	cout<<"Enter Product Details";
	for(int i=0;i<3;i++)
	{	
		cout<<"Enter Product ID: ";
		cin>>p[i].id;
		cout<<"Enter Product Price: ";
		cin>>p[i].price;
		cout<<"Enter Product Name: ";
		cin>>p[i].productName;
		cout<<"Enter Product Quantity ";
		cin>>p[i].qty;
	}
	//login functionality
	int userId;
	int flag=0; // to check that the user logged in or not...
	char userPassword[50];
	char userName[50];
	cout<<"\n-------USER LOGIN--------";
	cout<<"\n Enter User ID :";
	cin>>userId;
	cout<<"Enter Password: ";
	cin>>userPassword;
	for(int i=0;i<3;i++)
	{
		if(userId==u[i].id)
		{
			if(strcmp(userPassword,u[i].password)==0)
			{
				cout<<"Password Matched!!! \n\n";
				flag=1; //User logged in...
				strcpy(userName,u[i].name);
			}
		}
	}		

//If user logged in , then display him the menu....
	if (flag==1)
	{
		int productId[10]={0},q[10]={0}; // An array to store id of the product purchased..
		int id,quantity;
		int counter=0;
		int ch;
		cout<<"\nKindly go through the product menu.: \n";
		displayProducts(p,3);
	
		while(ch!=1)
		{	
			cout<<"\nEnter the product id you want to purchase: ";
			cin>>id;
			cout<<"Enter Quantity";
			cin>>quantity;
			productId[counter]=id;
			q[counter]= quantity;
			for(int i=0;i<3;i++)
			{
				if(p[i].id==id)
				{
					p[i].qty=p[i].qty-quantity;
				}
			}
			cout<<"Do you want to purchase more? (Press any key to purchase, and 1 to stop..)";
			cin>>ch;
			counter++;
		}

	//Display purchased items..with total cost..
		float totalPrice=0;
		cout<<"\n-----------------------------------\n";
		cout<<userName<<" purchased following items \n---------------------------\n "<<endl;
		for(int i=0;i<10;i++)
		{
			if(productId[i]!=0)
			{
				for(int j=0;j<3;j++)
				{
					if(productId[i]==p[j].id)
					{
						
						cout<<"\nProduct Name: "<<p[j].productName;
						cout<<"\nProduct Price: "<<p[j].price;
						cout<<"\nQuantity purchased: "<<q[i];
						cout<<"\nQuantity Left :"<<p[j].qty;
						totalPrice=totalprice+p[j].price;
					}
				}
			}
		}
				//Display total price...
				cout<<"\n------------------------------------";
				cout<<"\nTotal Bill to be paid : INR "<<totalPrice;
	}
	

}

