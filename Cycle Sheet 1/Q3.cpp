using namespace std;
#include<iostream>
#include<iomanip>
#include<conio.h>
#include<stdio.h>
#include<string.h>
class mob{
      char brand[10],mes[10][20];
      static char mess[10][20];
      long int imei,phoneNo1,phoneNo2;
      int noSim,x;
      public:
             mob(){
                   noSim=0;
                   x=0;
                   }
             void input();
             void login(mob *,long ,int );
             void sendmessage(long ,long );
             void history(mob *,int );
      };
      char mob::mess[10][20];
void mob::input(){
                  cout<<"Enter the brand\n";
                  cin>>brand;
                  cout<<"Enter the imei number\n";
                  cin>>imei;
                  cout<<"How many sim\n";
                  cin>>noSim;
                  cout<<"Enter the one mobile number\n";
                  cin>>phoneNo1; 
                  if(noSim==2)
                  {
                              cout<<"Enter the second mobile number\n";
                              cin>>phoneNo2;
                  }
                  }
void mob::login(mob *m,long p1,int n){
     int i,flag=0;
     long p2;
     for(i=0;i<n;i++)
     if(m[i].phoneNo1==p1||m[i].phoneNo2==p1)
     {cout<<"\n\nLogin successful\n";
     cout<<"Enter the phone to which you want to send the message\n";
     cin>>p2;
     sendmessage(p1,p2);
     return;
     }
     cout<<"Wrong phone number\n";
     }
void mob::sendmessage(long p1,long p2)
{
     int i,j,n;
     cout<<"How many messages do you want to send\n";
     cin>>n;
     cout<<"Enter the message you want send\n";
     for(i=0;i<n;i++)
     {
     cin.getline(mes[i],50);
     strcpy(mess[x],mes[i]);
     x++;
     cin.ignore();
     }
     cout<<"Your message is sent\n ";
 }        
void mob::history(mob *m,int n)
{
     int j,i;
     long m1;
     cout<<"Enter mobile number of which you want to see the history\n";
     cin>>m1;
     cout<<setw(15)<<"HISTORY"<<endl;
     for(i=0;i<n;i++)
     if(m[i].phoneNo1==m1||m[i].phoneNo2==m1)
     {
      for(j=0;j<m[i].x;j++)
      cout<<mess[j]<<endl;
      }
      }
int main()
{
    cout<<"hello\n";
    mob mobile[10],mo1;
    cout<<"hi\n";
    int i,n;
    char ch;
    long p1;
    cout<<"How many mobiles\n";
    cin>>n;
    for(i=0;i<n;i++)
    { 
    cout<<"Enter the details of: "<<i+1<<" mobile\n";
    mobile[i].input();
    }
    do{
    cout<<"\n\nEnter the mobile number with which you want to send message\n";
    cin>>p1;
    mo1.login(mobile,p1,n);
    cout<<"\nYou want to Send more messages from different mobile number Y for yes or N for no\n";
    cin>>ch;
}while(ch=='Y'||ch!='N');
mo1.history(mobile,n);   
    getch();
}
