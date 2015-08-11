using namespace std;
#include<iostream>
#include<string.h>
#include<conio.h>
#include<iomanip>
class ID_card{
	char name[25],regNo[10],HorD[10],branch[10];
	public:
		char* getreg()
		{
			return regNo;
		}
		void input();
		void insert(int &);
		void update();
		void del(char (&re)[10],int &);
		void display();
}id[25];
void ID_card::input()
{
	cout<<"Enter the registration number:\n";
	cin>>regNo;
	cout<<"Enter the name:\n";
	cin>>name;
	cout<<"Hosteller or dayscholar:\n";
	cin>>HorD;
	cout<<"Branch:\n";
	cin>>branch;
}
void ID_card::display()
{
	if(strcmp(regNo,"DELETED")!=0)
   	{
	   cout<<"Registration number: "<<regNo<<endl;
	   cout<<"Name: "<<name<<endl;
	   cout<<"Student is: "<<HorD<<endl;
	   cout<<"Branch: "<<branch<<endl;
}
}
void ID_card::update()
{
	int x;
	char nam[25],bran[10],HD[10];
	cout<<endl;
	cout<<setw(15)<<"UPDATE MENU"<<endl;
	cout<<"1.Name\n";
	cout<<"2.Branch\n";
	cout<<"3.Hosteller or Daysholar\n";
	cin>>x;
    switch(x)
    {   
    	case 1:
    		cout<<"\nEnter the new name:\n";
    		cin>>nam;
    		strcpy(name,nam);
    		cout<<"\nUpdated information is:\n\n";
    		display();
    		break;
        case 2:
        	cout<<"\nEnter the new branch\n";
        	cin>>bran;
        	strcpy(branch,bran);
        	cout<<"\nUpdated information is\n\n";
    		display();
    		break;
    	case 3:
    		cout<<"\nHosteller or Dayscholar\n";
    		cin>>HD;
    		strcpy(HorD,HD);
    		cout<<"\nUpdated information is\n\n";
    		display();
    		break;
    	default : cout<<"Invalid input\n";
    }
}
void ID_card::insert(int &n)
{
	
	int a,i;
	cout<<"How many id cards you want to insert\n";
	cin>>a;
	for(i=n;i<a+n;i++)
	{
		cout<<"Enter details of "<<i+1<<" Student\n";
		id[i].input();
		cout<<"Inserted information is\n";
		id[i].display();
	}
}
void ID_card::del(char (&reg)[10],int &n)
{
	int i;
	for(i=0;i<n;i++)
    if(strcmp(id[i].getreg(),reg)==0)
    strcpy(id[i].regNo,"DELETED");
}
int main()
{
	ID_card card;
	char reg[10],ch;
	int i,a=0,n,choice;
	cout<<"How many students\n";
	cin>>n;
	for(i=0;i<n;i++)
	{
	cout<<"\n\nEnter the details of ID No. "<<i+1<<endl;
	id[i].input();
    }
    do{
    cout<<setw(20)<<"MENU"<<endl;
    cout<<"1.Update\n";
    cout<<"2.Delete\n";
    cout<<"3.Insert\n";
    cin>>choice;
    switch(choice)
    {
    	case 1:
    		cout<<"\nEnter the reg.no. to which you want to make change\n";
    		cin>>reg;
    	    for(i=0;i<n;i++)
            if(strcmp(id[i].getreg(),reg)==0)
            {
            id[i].update();
            a=i;
            }
            if(a==0)
            cout<<"Invalid input\n";
    		break;
    	case 2:
    		cout<<"Enter the reg.no. of which you want to delete information\n";
    		cin>>reg;
    		card.del(reg,n);
    		break;
    	case 3:card.insert(n);
    	    break;
    	default:cout<<"Invalid input\n";
    }
    cout<<endl<<endl;
    cout<<setw(10)<<"TOTAL INFORMATION"<<endl<<endl;
    for(i=0;i<n;i++)
    {
	cout<<"Details of ID CARD No.- "<<i+1<<endl;
	id[i].display();
	cout<<endl;
    }
    cout<<"Do want to make more changes Y for yes or N for no\n";
    cin>>ch;
    }while(ch=='Y'||ch!='N');
getch();
}
