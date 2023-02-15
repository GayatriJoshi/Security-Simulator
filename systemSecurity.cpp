#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

int main()
{
	int a,i=0;
	
	string text,old,password1,password2,pass,name,password0,age,user,word,word1;
	string cred[2],cp[2];
	
	cout<<"\n\n\t\t___________________Security System_____________________"<<endl;
	cout<<"\n\n";
	cout<<"\t\t----------------------------------------------"<<endl;
	cout<<"\t\t|             1.Register                     |"<<endl;
	cout<<"\t\t|             2.Login                        |"<<endl;
	cout<<"\t\t|             3.Change password              |"<<endl;
	cout<<"\t\t|             4.End Program                  |"<<endl;
	cout<<"\t\t----------------------------------------------"<<endl;
	
	do{
		cout<<endl<<endl;
		cout<<"\t\tEnter your choice:- ";
		
		cin>>a;
		
		switch(a)
		{
			case 1:
			{
				cout<<"\t\t|+++++++++++++++++++++++++++++++++++++|"<<endl;
				cout<<"\t\t|---------------Register--------------|"<<endl;
				cout<<"\t\t|+++++++++++++++++++++++++++++++++++++|"<<endl<<endl;
				cout<<"\t\tEnter a username: ";
				cin>>name;
				cout<<"\t\tEnter a password (A-Z,a-z,0-9): ";
				cin>>password0;
				cout<<"\t\tAGE: ";
				cin>>age;
				ofstream of1;
				of1.open("file.txt");
				if(of1.is_open())
				{
					of1<<name<<"\n";
					of1<<password0;
					cout<<"\t\tUser Registered Sucecesfully!!"<<endl;
				}
				break;	
			}
				
			case 2:
			{
				i=0;
				cout<<"\t\t|++++++++++++++++++++++++++++++++++++++|"<<endl;
				cout<<"\t\t|-----------------LOGIN----------------|"<<endl;
				cout<<"\t\t|++++++++++++++++++++++++++++++++++++++|"<<endl<<endl;
				ifstream of2;
				of2.open("file.txt");
				cout<<"\n\t\tUserName: ";
				cin>>user;
				cout<<"\n\t\tPassword: ";
				cin>>pass; 
				
				if(of2.is_open())
				{
					while(!of2.eof())
					{
						while(getline(of2,text))
						{
							istringstream iss(text);
							iss>>word;
							cred[i]=word;
							i++;
						}
						if(user==cred[0] && pass==cred[1])
						{
							cout<<"\t\t----LOG IN SUCCESSFULL!!----";
							cout<<endl<<endl;
							
							cout<<"\t\tDetails "<<endl;
							cout<<"\t\tUSERNAME: "+name<<endl;
							cout<<"\t\tPASSWORD: "+pass<<endl;
							cout<<"\t\tAge: "+age<<endl;
						}
						else
						{
							cout<<endl<<endl;
							cout<<"\t\t!! Incorrect Credentials !!"<<endl;
							cout<<"\t\t 1.Press 2 to log in "<<endl;
							cout<<"\t\t 2.Press 3 to change password "<<endl;
							break;
						}
					}
				}
				break;
			}
			case 3:
			{
				i=0;
				cout<<"\t\t|_______CHANGE PASSWORD_________|"<<endl;
				
				ifstream of0;
				of0.open("file.txt");
				cout<<"\t\tEnter the old password:-";
				cin>>old;
				if(of0.is_open())
				{
					while(of0.eof())
					{
						while(getline(of0,text))
						{
							istringstream iss(text);
							iss>>word1;
							cp[i]=word1;
						    i++;
						}
						if(old==cp[1])
						{
							of0.close();
							
							ofstream of1;
							if(of1.is_open())
							{
								cout<<"\t\tEnter your new password:- ";
								cin>>password1;
								cout<<"\t\tEnter your password again:- ";
								cin>>password2;
								
								if(password1==password2)
								{
									of1<<cp[0]<<"\n";
									of1<<password1;
									cout<<"\t\tPassword changed successfully"<<endl;
								}
								else
								{
									of1<<cp[0]<<"\n";
									of1<<old;
									cout<<"\t\tPassword do not match";
								}
							}
						}
						else
						{
							cout<<"\t\tPlease enter valid password: ";
							break;
						}
					}
				}
				break;
			}
			case 4:
				cout<<"\t\t_________ THANK YOU! : ) ____________";
				break;
			default:
				cout<<"\t\tEnter a valid choice:";
		}
	}
	while(a!=4);
	
	return 0;
}
