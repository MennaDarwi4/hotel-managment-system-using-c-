#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>

using namespace std;




class hotel
{

int room_no;
char name[30];
char address[50];
char phone[10];

public:

void main_menu();
void add();
void display();
void rooms();
void edit();
int check(int);
void modify(int);
void delete_rec(int);
void bill(int);
     };







void hotel::main_menu()
{

int choice;
while(choice!=5)
{

  system("cls");
cout<<"\n\t\t\t\t*************************";
cout<<"\n\t\t\t\t *** HOTEL MANAGEMENT ***";
cout<<"\n\t\t\t\t      * MAIN MENU *";
cout<<"\n\t\t\t\t*************************";
cout<<"\n\n\n\t\t\t1.Book A Room";
cout<<"\n\t\t\t2.Customer Records";
cout<<"\n\t\t\t3.Rooms Allotted";
cout<<"\n\t\t\t4.Edit Record";
cout<<"\n\t\t\t5.Exit";
cout<<"\n\n\t\t\tEnter Your Choice: ";
cin>>choice;

switch(choice)
{

case 1:	add();
break;

case 2: display();
break;

case 3: rooms();
break;

case 4:	edit();
break;

case 5: break;

default:
{

cout<<"\n\n\t\t\tWrong choice.....!!!";
cout<<"\n\t\t\tPress any key to   continue....!!";
getch();

}

}

}

}



void hotel::add()
{

  system("cls");
int r,flag;
ofstream fout("Record.dat",ios::app);

cout<<"\n Enter Customer Detalis";
cout<<"\n ----------------------";
cout<<"\n\n Room no: ";
cout<<"\n Total no. of Rooms - 60";
cout<<"\n single without ac Rooms from 1 - 30";
cout<<"\n single with ac Rooms from 31 - 45";
cout<<"\n double without ac Rooms from 46 - 50";
cout<<"\n double with ac Rooms from 51 - 60";
cout <<"\n Enter The Room no. you want to stay in :- "<<endl;
cin>>r;

flag=check(r);

if(flag)
cout<<"\n Sorry..!!!Room is already booked";

else
{

room_no=r;
cout<<" Name: ";
cin>>name;
cout<<" Address: ";
cin>>address;
cout<<" Phone No: ";
cin>>phone;

fout.write((char*)this,sizeof(hotel));
cout<<"\n Room is booked...!!!";

}

cout<<"\n Press any key to continue.....!!";

getch();
fout.close();

}




void hotel::display()
{

  system("cls");

ifstream fin("Record.dat",ios::in);
int r,flag;

cout<<"\n Enter room no. for a particular customer`s details :- "<<endl;
cin>>r;

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{

  system("cls");
cout<<"\n Cusromer Details";
cout<<"\n ----------------";
cout<<"\n\n Room no: "<<room_no;
cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Phone no: "<<phone;
flag=1;
break;

}

}

if(flag==0)
cout<<"\n Sorry Room no. not found or vacant....!!";
cout<<"\n\n Press any key to continue....!!";

getch();
fin.close();
}




void hotel::rooms()
{

  system("cls");

ifstream fin("Record.dat",ios::in);
cout<<"\n\t\t\t    List Of Rooms Allotted";
cout<<"\n\t\t\t    ----------------------";
cout<<"\n\n Room No.\tName\t\tAddress\t\tPhone No.\n";

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
cout<<"\n\n "<<room_no<<"\t\t"<<name;
cout<<"\t\t"<<address<<"\t\t"<<phone;

}

cout<<"\n\n\n\t\t\tPress any key to continue.....!!";
getch();
fin.close();

}



void hotel::edit()
{

  system("cls");

int choice,r;
cout<<"\n EDIT MENU";
cout<<"\n ---------";
cout<<"\n\n 1.Modify Customer Record";
cout<<"\n 2.Delete Customer Record";
cout<<"\n 3. Bill Of Customer";
cout<<"\n Enter your choice: ";

cin>>choice;
  system("cls");

cout<<"\n Enter room no: " ;
cin>>r;

switch(choice)
{

case 1:	modify(r);
break;

case 2:	delete_rec(r);
break;

case 3: bill(r);
break;

default: cout<<"\n Wrong Choice.....!!";

}
cout<<"\n Press any key to continue....!!!";

getch();
}


int hotel::check(int r)
{

int flag=0;

ifstream fin("Record.dat",ios::in);

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{

flag=1;
break;

}

}

fin.close();
return(flag);

}




void hotel::modify(int r)
{

long pos,flag=0;

fstream file("Record.dat",ios::in|ios::out|ios::binary);

while(!file.eof())
{

pos=file.tellg();
file.read((char*)this,sizeof(hotel));

if(room_no==r)
{

cout<<"\n Enter New Details";
cout<<"\n -----------------";
cout<<"\n Name: ";
cin>>name;
cout<<" Address: ";
cin>>address;
cout<<" Phone no: ";
cin>>phone;
file.seekg(pos);
file.write((char*)this,sizeof(hotel));
cout<<"\n Record is modified....!!";
flag=1;
break;

}

}

if(flag==0)
cout<<"\n Sorry Room no. not found or vacant...!!";
file.close();

}




void hotel::delete_rec(int r)
{

int flag=0;
char ch;
ifstream fin("Record.dat",ios::in);
ofstream fout("temp.dat",ios::out);

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
if(room_no==r)

{

cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Pone No: "<<phone;
cout<<"\n\n Do you want to delete this record(y/n): ";
cin>>ch;

if(ch=='n')
fout.write((char*)this,sizeof(hotel));
flag=1;

}

else
fout.write((char*)this,sizeof(hotel));

}

fin.close();
fout.close();

if(flag==0)
cout<<"\n Sorry room no. not found or vacant...!!";

else
{

remove("Record.dat");
rename("temp.dat","Record.dat");

}

}



void hotel::bill(int r)
{
int duration , rent =1;
hotel h1;
ifstream f1;
 f1.open("record.dat",ios::in|ios::binary);
cout<<"Enter your duration in days :\n";
cin>>duration;
if(!f1)
 cout<<"cannot open";

 else
 {

  f1.read((char*)&h1,sizeof (hotel));
  while(f1)

  {

  f1.read((char*)&h1,sizeof(hotel));

  }

  if (h1.room_no == r)
  {

  if(h1.room_no>=1&&h1.room_no<=30)
  {

    rent=2000*duration;
  cout<<"your bill ="<<rent;
  }
  else if (h1.room_no>=35&&h1.room_no<=45)
  {

    rent=5000*duration;
  cout<<"your bill ="<<rent;
  }
  else if (h1.room_no>=46&&h1.room_no<=50)
  {

    rent=7000*duration;
  cout<<"your bill ="<<rent;
  }
  else
  {

    rent=10000*duration;
  cout<<"your bill ="<<rent;
}
 }

  else
  { cout<<"room no. not found";}

  }

  f1.close();
  getch();

}


int main()
{
hotel h;

  system("cls");

cout<<"\n\t\t\t****************************";
cout<<"\n\t\t\t* HOTEL MANAGEMENT PROJECT *";
cout<<"\n\t\t\t****************************";
   int x , opt , f=0;
   cout<<"\n\t\t\t1.Sign up\n";
   cout<<"\n\t\t\t2.Sign in\n";
   cin>>x;
   switch(x)
   {
   case 1:
    {
        string p , n;
        do{
        cout<<"Enter your password\n";
        cin>>p;
        cout<<"Confirm Password\n";
        cin>>n;
        if(n!=p)
            cout<<"Try Again\n";
        }while (n!=p);
        cout<<"You signed up successfully\1\n";
        f=1;
      fstream myfile ;
      myfile.open("pass.txt" , ios::app);
      if(myfile.is_open())
      {
          myfile<<p<<endl;
          myfile.close();
      }
        break;
    }
   case 2:
       {
        string y;
        loop:{cout<<"Please , Enter your password\n";
        cin>>y;}
        fstream myfile ;
      myfile.open("pass.txt" , ios::in);
        int flag=0;
        string line;
        while (getline(myfile, line))
        {
            if (line==y)
            {
                flag=1;
                break;
            }

        }
        myfile.close();
        if(flag==1)
        {
            cout<<"CORRECT PASSWORD\n";
            f=1;
        }
        else
        {
            cout<<"WRONG PASSWORD , TRY AGIN\n";
            goto loop;
        }
        break;
       }
   }
if(f==1)
{
cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";

getch();

h.main_menu();
}
return 0;
}
