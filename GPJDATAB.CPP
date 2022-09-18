#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include<conio.h>
using namespace std;
char un[20];
class Admin
 {
   char name[20];
   int ts;
   char subject[10][10];
   char mobile[15],mail[50],fname[20];
   char passwd[20],rpasswd[20];
   public:
   char roll_no[50];
   void getstdata()
   {
    cout<<"\nEnter the student name:\t";
    gets(name);
    cout<<"\nEnter the student roll number:\t";
    cin>>roll_no;
    cout<<"\nEnter the student father name:\t";
    gets(fname);
    cout<<"\nEnter the mobile no:\t";
    gets(mobile);
    cout<<"\nEnter email_id:\t";
    gets(mail);
    cout<<"\nEnter the total subjects:";
    cin>>ts;
    int i;

    for(i=0;i<ts;i++)
    { cout<<"\nEnter the subject "<<i+1<<" Name:";
      cin>>subject[i];
    }
    cout<<"\nCreate your login password:";
    cin>>passwd;
    cout<<"\nEnter the unique keyword to recover password:";
    cin>>rpasswd;
    cout<<"\n\nPlease note your username is roll no\n";
   }
   int login()
   {
    if((strcmp(::un,roll_no))==0)
    {
      cout<<"\nEnter the login password:";
      int len=0;
	  int i;
      len=strlen(passwd);
      char inputpasswd[20];
      for(i=0;i<len;i++)
      {
	inputpasswd[i]=getch();
	cout<<"\n #";
      }
      inputpasswd[i]=NULL;
      //cout<<"\nThe entered password is"<<inputpasswd;
      if((strcmp(::un,roll_no)==0)&&(strcmp(passwd,inputpasswd)==0))
      return 1;
      else
      return 0;
    }
    else
    return 0;
   }

   int recover()
   {
     //cout<<"\nThe input username is"<<::un;
     char key[20];
     if(strcmp(::un,roll_no)==0)
     {
       cout<<"\nEnter the unique keyword (Provided by Admin):";
       cin>>key;
       if(strcmp(key,rpasswd)==0)
       {
	 cout<<"\nYou are a valid user.";
	 cout<<"\nYour password is"<<passwd;
	 cout<<"\nPlease Exit to login again";
	 return 1;
	}
	else
	return 0;
       }
       else
       return 0;
   }

    int faprofile()
    {
      if(strcmp(::un,roll_no)==0)
      {
	cout<<"\nFaculty name         :"<<name;
	cout<<"\nFaculty father's name:"<<fname;
	cout<<"\nFaculty mobile no.   :"<<mobile;
	cout<<"\nFaculty Email ID     : "<<mail;
	return 1;
      }
     else
     return 0;
    }

    int knowfasub()
    {
      if(strcmp(::un,roll_no)==0)
      {
	cout<<"\nFaculty total subjects:-"<<ts;
	for(int i=0;i<ts;i++)
	{
	  cout<<"\n\tSubject "<<i+1<<":"<<subject[i];
	}
	return 1;
      }
      else
      return 0;
   }

   void addfasub()
   {
    if(strcmp(::un,roll_no)==0)
    {
     cout<<"\n Enter the new subject:";
     cin>>subject[ts];
     ts++;
     cout<<"\n\nNew subject added successfully...";
     }
   }

   void delfasub()
   {
     knowfasub();
     int de=0;
     if(strcmp(::un,roll_no)==0)
     {
       if(ts==0||ts<0)
       {
	  ts=0;
	  cout<<"\nNone subjects exist....";
	  getch();
	  exit(0);
	}
       cout<<"\nEnter the subject no. to be deleted:";
       cin>>de;
       if(de==ts)
       {
	 ts--;
	 strcpy(subject[ts]," ");
	}
	else
	{
	   if(ts==1)
	   {
	     ts=0;
	     strcpy(subject[ts]," ");
	   }
	   else
	   {
	     de--;
	     strcpy(subject[ts]," ");
	     for(int p=de;p<ts;p++)
	     {
	       strcpy(subject[p],subject[p+1]);
	     }
	     ts--;
	    }
	    cout<<"\nRecords update successfully....";
	 }
       }
     }

     void modfaprofile()
    {
      if((strcmp(::un,roll_no)==0))
      {
	cout<<"\nThe profile details are :";
	cout<<"\n 1.faculty email: "<<mail;
	cout<<"\n 2.faculty mobile:"<<mobile;
	int g=-1;
	cout<<"\n\nEnter the detail number to be modified:";
	cin>>g;
	if(g==1)
	{
	 char nmail[50];
	 cout<<"\n Enter the new mail address:";
	 strcpy(mail,nmail);
	 cout<<"\nRecords updated successfully...";
	}
	else if(g==2)
	{
	 char nmobile[15];
	 cout<<"\nEnter the new mobile number:";
	 gets(nmobile);
	 strcpy(mobile,nmobile);
	 cout<<"\n Records updated successfully...";
	}
	else
	cout<<"\n Invalid choice......";
      }
    }

    int stprofile()
    {
     if(strcmp(::un,roll_no)==0)
     {
      cout<<"\nStudent name:"<<name;
      cout<<"\nStudent father's name:"<<fname;
      cout<<"\nStudent mobile number:"<<mobile;
      cout<<"\nStudent Email-ID:"<<mail;
      return 1;
     }
     else
     return 0;
    }

   int knowstsub()
   {
    if(strcmp(::un,roll_no)==0)
    {
     cout<<"\nStudent total subjects:-"<<ts;
     for(int i=0;i<ts;i++)
     {
      cout<<"\n\tSubject "<<i+1<<":"<<subject[i];
     }
     return 1;
    }
    else
    return 0;
   }

   void addstsub()
   {
    if(strcmp(::un,roll_no)==0)
    {
     cout<<"\n Enter the new subject:";
     cin>>subject[ts];
     ts++;
     cout<<"\\n\n New subject added successfully...";
    }
   }

   void delstsub()
   {
    knowstsub();
    int de=0;
    if(strcmp(::un,roll_no)==0)
    {
     if(ts==0||ts<0)
     {
      ts=0;
      cout<<"\nNone subject exits....";
      getch();
      exit(0);
     }
     cout<<"\n Enter the subject number to be deleted:";
     cin>>de;
     if(de==ts)
     {
      ts--;
      strcpy(subject[ts]," ");
     }
     else if(ts==1)
     {
      ts=0;
      strcpy(subject[ts]," ");
     }
     else
     {
      de--;
      strcpy(subject[ts]," ");
      for(int p=de;p<ts;p++)
      {
       strcpy(subject[p],subject[p+1]);
      }
      ts--;
     }
     cout<<"\n Records updated successfully.....";
    }
   }

   void modstprofile()
   {
    if(strcmp(::un,roll_no)==0)
    {
     cout<<"\n The profile details are:";
     cout<<"\n 1.Student Email:"<<mail;
     cout<<"\n 2.Student Mobile:"<<mobile;
     int g=-1;
     cout<<"\nEnter the detail number to be modified:";
     cin>>g;
     if(g==1);
     {
      char nmail[50];
      cout<<"\n Enter the new mail address:";
      strcpy(mail,nmail);
      cout<<"\nRecords updated successfully....";
     }

     if(g==2)
      {
       char nmobile[15];
       cout<<"\nEnter the new mobile number";
       gets(mobile);
       strcpy(mobile,nmobile);
       cout<<"\n REcords updated successfully";
      }
     if(g!=1&&g!=2)
      cout<<"\nInvalid choice";
    }
   }

   void getfadata()
   {
    cout<<"\nEnter the faculty name:";
    gets(name);
    cout<<"\nEnter the faculty ID:";
    cin>>roll_no;
    cout<<"\nEnter faculty father name:";
    gets(fname);
    cout<<"\nEnter the mobile number:";
    gets(mobile);
    cout<<"\nEnter the Email-ID:";
    gets(mail);
    cout<<"\nEnter the total subject:";
    cin>>ts;
   // cout<<"\nThe total subject choosen are :"<<totsub;
   for(int i=0;i<ts;i++)
   {
    cout<<"\n Enter the subject "<<i+1<<" name:";
    cin>>subject[i];
   }
   cout<<"\nCreate your login password:";
   cin>>passwd;
   cout<<"\nEnter the unique keyword to recover password";
   cin>>rpasswd;
   cout<<"\n\nPlease note your user name is roll no.";
 }

 void stdisplay()
 {
  cout<<"\nStudent name :"<<name;
  cout<<"\nStudent roll no:"<<roll_no;
  cout<<"\nStudents fathers name:"<<fname;
  cout<<"\nStudent mobile no.:"<<mobile;
  cout<<"\nStudent Email ID:"<<mail;
  cout<<"\nStudents subject:"<<ts;
  for(int i=0;i<ts;i++)
  {
   cout<<"\nSubject "<<i+1<<":"<<subject[i];
  }
  if(ts=0)
  cout<<"\nNone subjects specified";
 }

  void fadisplay()
  {
    cout<<"\nFaculty name :"<<name;
    cout<<"\nFaculty ID:"<<roll_no;
    cout<<"\nFaculty fathers name:"<<fname;
    cout<<"\nFaculty mobile no.:"<<mobile;
    cout<<"\nFaculty Email ID:"<<mail;
    cout<<"\nFaculty subjects:"<<ts;
    for(int i=0;i<ts;i++)
    {
      cout<<"\nSubject "<<i+1<<":"<<subject[i];
    }
    if(ts=0)
    cout<<"\nNone subjects specified";
  }
}a;
Admin f;

  int main()
  {
   int ch;
   system ("CLS");
   cout<<"\n\n\n\t\tWELLCOME TO GPJ DATABASE PORTAL";
   cout<<"\n\n\n\t\tEnter to continue";
   getch();
   system ("CLS");
   cout<<"\n\n\t\tMENU";
   cout<<"\n\tPress 1 for admin portal";
   cout<<"\n\tPress 2 for faculty portal";
   cout<<"\n\tPress 3 for student portal";
   cout<<"\n Enter your choice:";
   cin>>ch;
   system ("CLS");
   if(ch==1)
   {
     char adminuser[20],adminpass[20];
	 int k;
     cout<<"\n\n\t\tWELCOME TO ADMIN LOGIN PORTAL";
     cout<<"\n\n\tEnter the username:";
     cin>>adminuser;
     cout<<"\nEnter the Password:";
     for(k=0;k<8;k++)
     {
	adminpass[k]=getch();
	cout<<"*";
     }
     getch();
     adminpass[k]=NULL;
     if((strcmp(adminuser,"admin")==0)&&(strcmp(adminpass,"password")==0))
     {
       system ("CLS");
     }
     else
     {
       cout<<"\n\n\t\tInvalid Access to portal";
       cout<<"\n\n\t\tThank You!!!";
       getch();
       exit(0);
     }
     char opera='y';
     do
     {
	int tmp;
	cout<<"\n\n\t\tWELCOME TO ADMIN PANEL";
	cout<<"\n\nPress 1 to add faculty record";
	cout<<"\nPress 2 to Add multiple records of faculty";
	cout<<"\nPress 3 to View all records of faculty";
	cout<<"\nPress 4 to Delete a faculty record ";
	cout<<"\nPress 5 to Add a student record ";
	cout<<"\nPress 6 to Add multiple records of students ";
	cout<<"\nPress 7 to View all records of students";
	cout<<"\nPress 8 to Delete a student record ";
	cout<<"\nPress 9 to Exit";
	cout<<"\n\n Enter your choice:";
	cin>>tmp;
	system ("CLS");
	if(tmp==1)
	{
	   cout<<"\nEnter the details:-";
	   fstream fs;
	   fs.open("fainfo.txt",ios::in|ios::out|ios::ate);
	   a.getfadata();
	   fs.write((char *)&a,sizeof(Admin));
	   fs.close();
	   cout<<"\nRecord entered successfully...";
	}
	if(tmp==2)
	{
	  int m=0;
	  fstream fs;
	  fs.open("fainfo.txt",ios::in|ios::out|ios::ate);
	  do
	  {
	     cout<<"\n Enter the details:-";
	     a.getfadata();
	     fs.write((char *)&a,sizeof(Admin));
	     cout<<"\n Press 0 if you want to enter more records:";
	     cin>>m;
	   } while(m==0);
	   fs.close();
	   cout<<"\nRecord entered successfully...";
	 }
	 if(tmp==3)
	 {
	    fstream fs;
	    fs.open("fainfo.txt",ios::in);
	    fs.seekg(0);
	    while(!fs.eof())
	    {
	      fs.read((char *)&a,sizeof(Admin));
	      a.fadisplay();
	    }
	    fs.close();
	  }
	  if(tmp==4)
	  {
	    char tmpfaid[15];
	    int de=0,result=-1;
	    cout<<"\nEnter the faculty ID. :-";
	    cin>>tmpfaid;
	    fstream fs;
	    fs.open("fainfo.txt",ios::in);
	    fstream fs1;
	    fs1.open("fanewinfo.txt",ios::out|ios::ate);
	    while(!fs.eof())
	    {
	       fs.read((char *)&a,sizeof(Admin));
	       result=strcmp(tmpfaid,a.roll_no);
	       if(result==0)
	       {
		 de=1;
	       }
	       else
	       fs1.write((char *)&a,sizeof(Admin));
	     }
	     if(de==1)
	     {
	       cout<<"\nRecord deleted successfully....";
	     }
	     else
	     {
	       cout<<"\nRecord not found...";
	     }
	     fs.close();
	     fs1.close();
	     remove("fainfo.txt");
	     rename("fanewinfo.txt","fainfo.txt");
	   }
	   if(tmp==5)
	   {
	      cout<<"\nEnter the details :-";
	      fstream fs;
	      fs.open("stinfo.txt",ios::in|ios::out|ios::ate);
	      a.getstdata();
	      fs.write((char *)&a,sizeof(Admin));
	      fs.close();
	      cout<<"\nRecord entered successfully....";
	    }
	    if(tmp==6)
	    {
	       int m=0;
	       fstream fs;
	       fs.open("stinfo.txt",ios::in|ios::out|ios::ate);
		do
	       {
		 cout<<"\n Enter the details:-";
		 a.getstdata();
		 fs.write((char *)&a,sizeof(Admin));
		 cout<<"\n Press 0 if you want to enter more records:";
		 cin>>m;
	       } while(m==0);
	   fs.close();
	   cout<<"\nRecord entered successfully...";
	 }
	 if(tmp==7)
	  {
	    fstream fs;
	    fs.open("stinfo.txt",ios::in);
	    fs.seekg(0);
	    while(!fs.eof())
	    {
	      fs.read((char *)&a,sizeof(Admin));
	      a.stdisplay();
	    }
	    fs.close();
	  }
	  if(tmp==8)
	  {
	    char tmpstid[15];
	    int de=0,result=-1;
	    cout<<"\nEnter the student roll no. :-";
	    cin>>tmpstid;
	    fstream fs;
	    fs.open("stinfo.txt",ios::in);
	    fstream fs1;
	    fs1.open("stnewinfo.txt",ios::out|ios::ate);
	    while(!fs.eof())
	    {
	       fs.read((char *)&a,sizeof(Admin));
	       result=strcmp(tmpstid,a.roll_no);
	       if(result==0)
	       {
		 de=1;
	       }
	       else
	       fs1.write((char *)&a,sizeof(Admin));
	     }
	     if(de==1)
	     {
	       cout<<"\nRecord deleted successfully....";
	     }
	     else
	     {
	       cout<<"\nRecord not found...";
	     }
	     fs.close();
	     fs1.close();
	     remove("stinfo.txt");
	     rename("stnewinfo.txt","stinfo.txt");
	   }
	   if(tmp==9)
	   {
	     cout<<"\n\n\n\t\tTHANK YOU !!!";
	     getch();
	     exit(0);
	    }
	    if(tmp<1||tmp>9)
	    {
	      system ("CLS");
	      cout<<"\n\n\n\t\tINVALID INPUT.......";
	    }
	    getch();
	    cout<<"\nPress y for more operations ; otherwise n :";
	    cin>>opera;
	    if(opera!='y')
	    {
	       getch();
	       system ("CLS");
	       cout<<"\n\n\n\t\tTHANK YOU !!!";
	       getch();
	     }
	   }while(opera=='y'||opera=='Y');
	 }
	if(ch==2)
	{
	 system ("CLS");
	 char un[20];
	 int val,s=20;
	 cout<<"\n\t\t\tWELCOME TO FACULTY LOGIN PAGE";
	 cout<<"\n\nEnter the user name";
	 cin>>::un;
	 fstream fs;
	 fs.open("fainfo.txt",ios::in|ios::binary);
	 fs.seekg(0);
	 while(!fs.eof())
	 {
	   val=-1;
	   fs.read((char *)&f,sizeof(Admin));
	   val=f.login();
	   if(val==1)
	   {
	     s=1;
	     break;
	   }
	 }
	 fs.close();
	 if(s==1)
	 {
	   system ("CLS");
	 }
	 if(s!=1)
	 {
	   system ("CLS");
	   int ho=0;
	   cout<<"\n\n\tYour login credentials are In-correct";
	   cout<<"\nThe username is your ID";
	   cout<<"\nThe password is case-sensitive.";
	   cout<<"\nPress 1 to recover password & 2 to re-attempt login";
	   cout<<"\nEnter your choice";
	   cin>>ho;
	   if(ho==1)
	   {
	     cout<<"\nEnter the username:-";
	     cin>>::un;
	     fstream fs;
	     fs.open
	     ("fainfo.txt",ios::in|ios::binary);
	     fs.seekg(0);
	     int re,su=-1;
	     while(!fs.eof())
	     {
	       re=-1;
	       fs.read((char *)&f,sizeof(Admin));
	       re=f.recover();
	       if(re==1)
	       {
		 su=1;
		 break;
	       }
	     }
	     fs.close();
	     if(su==1)
	     {
	       getch();
	       system ("CLS");
	       cout<<"\n\n\n\n\t\tTHANK YOU!!!";
	       getch();
	       exit(0);
	     }
	     else
	     {
	       cout<<"\nYou are a invalid user.";
	       getch();
	       exit(0);
	     }
	   }
	   if(ho==2)
	   {
	     cout<<"\n\nEnter the username :";
	     cin>>::un;
	     fstream fs;
	     fs.open
	     ("fainfo.txt",ios::in|ios::binary);
	     fs.seekg(0);
	     int suc=-1,valu;
	     while(!fs.eof())
	     {
	       valu=-1;
	       fs.read((char *)&f,sizeof(Admin));
	       valu=f.login();
	       if(valu==1)
	       {
		 suc=1;
		 break;
	       }
	     }
	     fs.close();
	     if(suc==1)
	     {
	       system ("CLS");
	     }
	     else
	     {
	       getch();
	       cout<<"\nYou are an invalid user...";
	       cout<<"\n\nTHANK YOU  !!!";
	       getch();
	       exit(0);
	       exit(0);
	     }
	   }
	   if(ho!=1&&ho!=2)
	   {
	     cout<<"\n\nInvalid choice";
	     cout<<"\n\n\t\tTHANK YOU  !!!";
	     getch();
	     exit(0);
	   }
	 }
	 char con='y';
	 do
	 {
	   system ("CLS");
	   cout<<"\n\n\t\tWelcome to faculty panel";
	   cout<<"\n\n\t\t\t\t  Your user ID is :"<<::un;
	   cout<<"\n\n Press 1 to view your profile";
	   cout<<"\n Press 2 to know your subjects";
	   cout<<"\n Press 3 to add a subject";
	   cout<<"\n Press 4 to delete a subject";
	   cout<<"\n Press 5 to modify your profile";
	   int choice;
	   cout<<"\n\n Enter your choice:";
	   cin>>choice;
	   if(choice==1)
	   {
	     fstream fs;
	     fs.open("fainfo.txt",ios::in);
	     fs.seekg(0);
	     while(!fs.eof())
	     {
	      int x=0;
	       fs.read((char *)&f,sizeof(Admin));
	       x=f.faprofile();
	       if(x==1)
	       {
		 break;
	       }
	     }
	     fs.close();
	   }
	     if(choice==2)
	     {
	      fstream fs;
	      fs.open("fainfo.txt",ios::in);
	      fs.seekg(0);
	      int y;
	      while(!fs.eof())
	      {

		fs.read((char *)&f,sizeof(Admin));
		int y=f.knowfasub();
		if(y==0)
		{
		  break;
		}
	      }
	      fs.close();
	     }
	    if(choice==3)
	    {
	    fstream fs;
	    fstream fs1;
	    fs.open("fainfo.txt",ios::in|ios::binary);
	    fs1.open("tmpfainfo.txt",ios::out|ios::ate);
	    fs.seekg(0);
	    while(!fs.eof())
	    {
	      fs.read((char *)&f,sizeof(Admin));
	      f.addfasub();
	      fs1.write((char *)&f,sizeof(Admin));
	    }
	    fs.close();
	    fs1.close();
	    remove("fainfo.txt");
	    rename("tmpfainfo.txt","fainfo.txt");
	   }
	   if(choice==4)
	   {
	     fstream fs;
	     fs.open("fainfo.txt",ios::in|ios::binary);
	     fstream fs1;
	     fs1.open("delfainfo.txt",ios::out|ios::ate);
	     fs.seekg(0);
	     while(!fs.eof())
	     {
	      fs.read((char *)&f,sizeof(Admin));
	      f.delfasub();
	      fs1.write((char *)&f,sizeof(Admin));
	     }
	     fs.close();
	     fs1.close();
	     remove("fainfo.txt");
	     rename("delfainfo,txt","fainfo.txt");
	   }
	   if(choice==5)
	   {
	    fstream fs;
	    fstream fs1;
	    fs.open("fainfo.txt",ios::in|ios::binary);
	    fs.seekg(0);
	    fs1.open("modfainfo.txt",ios::out|ios::ate);
	    while(!fs.eof())
	    {
	       fs.read((char *)&f,sizeof(Admin));
	       f.modfaprofile();
	       fs1.write((char *)&f,sizeof(Admin));
	   }
	   fs.close();
	  fs1.close();
	  remove("fainfo.txt");
	  rename("modfainfo.txt","fainfo.txt");
       }
       if(choice<1||choice>5)
       cout<<"\nInvalid input provided !!!";

       cout<<"\n\n\t\t\t\tEnter to continue";
       getch();
       cout<<"\n\nPress y to continue ; otherwise n:";
       cin>>con;
       if(con!='y' && con!='Y')
       {
	system ("CLS");
	cout<<"\n\n\n\n\n\t\t\tThank you !!!";
	getch();
	exit(0);
      }
    }while(con=='y'||con=='Y');
  }
    if(ch==3)
    {
      system ("CLS");
      int value,s1=0;
      cout<<"\n\t\t\t Welcome to student login page";
      cout<<"\n\nEnter the username :";
      cin>>::un;
      fstream fs;
      fs.open("stinfo.txt",ios::in|ios::binary);
      fs.seekg(0);
      while(!fs.eof())
      {
	value=-1;
	fs.read((char *)&f,sizeof(Admin));
	value=f.login();
	if(value==1)
	{
	   s1=1;
	   break;
	}
      }
      fs.close();
      if(s1==1)
      {
	system ("CLS");
       }
       if(s1!=1)
       {
	  system ("CLS");
	  int sho=0;
	  cout<<"\n\n\t\tYour login creadentials are incorrect";
	  cout<<"\n The user name is your roll no";
	  cout<<"\n Password is case sensitive";
	  cout<<"\nPress 1 to Recover password ";
	  cout<<"\nPress 2 to reattempt login";
	  cout<<"\nEnter your choice";
	  cin>>sho;
	  if(sho==1)
	  {
	   cout<<"\n Enter the username:-";
	   cin>>::un;
	   fstream fs;
	   fs.open("stinfo.txt",ios::in|ios::binary);
	   fs.seekg(0);
	   int re,su=-1;
	   while(!fs.eof())
	   {
	     re=-1;
	     fs.read((char *)&f,sizeof(Admin));
	     re=f.recover();
	     if(re==1)
	     {
	       su=1;
	       break;
	     }
	   }
	   fs.close();
	   if(su==1)
	   {
	     getch();
	     system ("CLS");
	     cout<<"\n\n\n\n\t\t\tThank You !!!";
	     getch();
	     exit(0);
	   }
	   else
	   {
	     cout<<"\n You are a Invalid user.";
	     cout<<"\n Thank you !!!";
	     getch();
	     exit(0);
	    }
	  }
	  if(sho==2)
	  {
	    cout<<"\n\nEnter the user name:-";
	    cin>>::un;
	    fstream fs;
	    fs.open("stinfo.txt",ios::in|ios::binary);
	    fs.seekg(0);
	    int suc=-1,valu;
	    while(!fs.eof())
	    {
	       valu=-1;
	       fs.read((char *)&f,sizeof(Admin));
	       valu=f.login();
	       if(valu==1)
	       {
		  suc=1;
		  break;
		}
	    }
	    fs.close();
	    if(suc==1)
	    system ("CLS");
	    else
	    {
	       getch();
	       cout<<"\nYou are an invalid user....";
	       cout<<"\n Thank you !!!";
	       getch();
	       exit(0);
	       exit(0);
	    }
	  }
	  if(sho!=1&&sho!=2)
	  {
	    cout<<"\n\nInvalid input provided...";
	    cout<<"\n\n\t\t\tThank you !!!";
	    getch();
	    exit(0);
	  }

      }
      char moreop='y';
      do
      {
	system ("CLS");
	cout<<"\n\n\t\t\t WELCOME TO STUDENT PANEL  ";
	cout<<"\n\n\t\t\t\t\t your user ID is  :"<<::un;
	cout<<"\n\n Press 1 to view your profile.";
	cout<<"\n\n Press 2 to know your subjects.";
	cout<<"\n\n Press 3 to add a subject.";
	cout<<"\n\n Press 4 to delete a subject.";
	cout<<"\n\n Press 5 to modify your profile.";
	int inchoice;
	cout<<"\n\nEnter your choice";
	cin>>inchoice;

	if(inchoice==1)
	{
	  fstream fs;
	  fs.open("stinfo.txt",ios::in);
	  fs.seekg(0);
	  int x;
	  while(!fs.eof())
	  {
	    x=0;
	    fs.read((char *)&f,sizeof(Admin));
	    x=f.stprofile();
	    if(x==1)
	    {
	      break;
	    }
	  }
	  fs.close();
	}
	if(inchoice==2)
	{
	 fstream fs;
	 fs.open("stinfo.txt",ios::in);
	 fs.seekg(0);
	 int y;
	 while(!fs.eof())
	 {
	   y=0;
	   fs.read((char *)&f,sizeof(Admin));
	   int y=f.knowstsub();
	   if(y==1)
	   {
	     break;
	   }
	 }
	 fs.close();
      }
      if(inchoice==3)
      {
	fstream fs;
	fstream fs1;
	fs.open("stinfo.txt",ios::in|ios::binary);
	fs.open("tmpstinfo.txt",ios::out|ios::ate);
	fs.seekg(0);
	while(!fs.eof())
	{
	  fs.read((char *)&f,sizeof(Admin));
	  f.addstsub();
	  fs1.write((char *)&f,sizeof(Admin));
	 }
	fs.close();
	fs1.close();
	remove("stinfo.txt");
	rename("tmpstinfo.txt","stinfo.txt");
      }
      if(inchoice==4)
      {
	 fstream fs;
	 fs.open("stinfo.txt",ios::in|ios::binary);
	 fstream fs1;
	 fs1.open("delstinfo.txt",ios::out|ios::ate);
	 fs.seekg(0);
	 while(!fs.eof())
	{
	   fs.read((char *)&f,sizeof(Admin));
	   f.delstsub();
	   fs1.write((char *)&f,sizeof(Admin));
	 }
	 fs.close();
	 fs1.close();
	 remove("stinfo.txt");
	 rename("delstinfo.txt","stinfo.txt");
       }
       if(inchoice==5)
       {
	  fstream fs;
	  fstream fs1;
	  fs.open("stinfo.txt",ios::in|ios::binary);
	  fs.seekg(0);
	  fs1.open("modstinfo.txt",ios::out|ios::ate);
	  while(!fs.eof())
	  {
	     fs.read((char *)&f,sizeof(Admin));
	     f.modstprofile();
	     fs1.write((char *)&f,sizeof(Admin));
	  }
	  fs.close();
	  fs1.close();
	  remove("stinfo.txt");
	  rename("modstinfo.txt","stinfo.txt") ;
	}
	if(inchoice<1||inchoice>5)
	   cout<<"\nInvalid input provided....";
	cout<<"\n\n\t\t\tEnter to continue";
	getch();
	cout<<"\n\nPress y , otherwise n to perform more operations:";
	cin>>moreop;
	if(moreop!='Y'&&moreop!='y')
	{
	   system ("CLS");
	   cout<<"\n\n\n\t\t\tThank you !!!";
	   getch();
	   exit(0);
	}
      }while(moreop=='Y'||moreop=='y');
      getch();
    }
    if(ch<1||ch>3)
     {
       cout<<"\nInvalid input provided....";
       getch();
       system ("CLS");
       cout<<"\n\n\n\t\t\tTHANK YOU !!!!";
     }
	return 0;
}



























































































































