#include<iostream>
#include<stdio.h>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include "logger.h"
#include "Database.h"
#define PIN 1234
#define START_VALUE 1
#define LIMIT 3

using namespace std;

void login();
void registr();
void forgot();
void AdminLogin();
void mainMenu();

void Client()
{
        //A null terminated array of character
        //pointers
        char *args[]={"./client",NULL};
        execvp(args[0],args);
     
        /*All statements are ignored after execvp() call as this whole
        process(execDemo.c) is replaced by another process (EXEC.c)
        */
        cout<<"Ending-----"<<endl;
}

void Server()
{
    //A null terminated array of character
    //pointers
    char *args[]={"./server",NULL};
    execvp(args[0],args);

    /*All statements are ignored after execvp() call as this whole
    process(execDemo.c) is replaced by another process (EXEC.c)
    */
    cout<<"Ending-----"<<endl;
}

void sigint_handler(int signal)
{
	cout << "\n\nCaught ^C\n " << endl;
	cout << "Returning to main menu\n" << endl;
	mainMenu();
}

void sigtstp_handler(int signal)
{
	cout << "\n\nCaught ^Z\n "<< endl;
	cout << "Program exited Successfully ...\n" << endl;
	exit(1);
}


void AdminLogin()
{
    int Pin=PIN;
    int Input_Pin=0;
    int Warning=1;
    int ch;
    do
    {
        //Checking Pass Code
        LOG_INFO("Enter Pin: ");
        cin>>Input_Pin;
        if(Input_Pin==Pin)
        {
            LOG_INFO("Login Succesful");
            cout<<endl;
            LOG_INFO("***");
            cout<<endl;
            LOG_INFO("*HELLO ADMIN*");
            cout<<endl;
            LOG_INFO("***");

            LOG_INFO("1.Access Database\n");
	    LOG_INFO("2.Customer Support\n");
            LOG_INFO("Enter your choice");
            cin>>ch;
            switch(ch){
                case 1:Database();
                       break;
		case 2:Client();
		       break;
                default:LOG_ERROR("Enter valid choice");
            }
        }
        else
        {
                        //Wrong Pin attemps 3
            Warning++;
            LOG_ERROR("Try again");
            cout<<endl;
        }
    }
         //Pass Code attempts Exceeded 3 times then Accout is Bloked
    while(Warning<=LIMIT && Input_Pin!=Pin);
    {
        if(Warning>LIMIT)
        {
            LOG_ERROR("Your Account Is Blocked! ");
            cout<<endl;
            exit(0);
        }
    }
}


void Menu()
{
    int choice;
    LOG_INFO("             ***");
    cout<<endl<<endl;
    LOG_INFO("             *    Welcome to login page     **");
    cout<<endl<<endl;
    LOG_INFO("             ***");
    cout<<endl<<endl<<endl;


    LOG_INFO("                 *        MENU        ***\n\n");
    LOG_INFO("1.LOGIN");
    cout<<endl;
    LOG_INFO("2.REGISTER");
    cout<<endl;
    LOG_INFO("3.FORGOT PASSWORD (or) USERNAME");
    cout<<endl;
    LOG_INFO("4.Customer Support");
    cout<<endl;
    LOG_INFO("5.Exit");
    cout<<endl;
    LOG_INFO("\nEnter your choice :");
    cin>>choice;
    cout<<endl;
    switch(choice)
    {
        case 1:
            login();
            break;
        case 2:
            registr();
            break;
        case 3:
            forgot();
            break;
        case 4:
	    Server();
            break;
        case 5:
            LOG_INFO("Thanks for using this program.\nThis program is created by GROUP-1 \n\n");
            break;
        default:
            LOG_ERROR("You've made a mistake , Try again..\n");
            Menu();
    }
}

void UserMenu()
{
	cout<<"1.Retrieve Data"<<endl;
        cout<<"2.Customer Support"<<endl;
        cout<<"3.Exit"<<endl;
        int Choice;
        cout<<"Enter Your Choice: ";
        cin>>Choice;
        switch(Choice)
        {
                case 1:
                        retrieve();
                        break;
                case 2:
                        Server();
                        break;
                case 3:
                        exit(0);
                        break;
                default:
                        cout<<"Enter Valid Choice"<<endl;
        }


}

void login()
{
    int count;
    string user,pass,u,p;

    LOG_INFO("Please enter the following details");
    cout<<endl;
    LOG_INFO("USERNAME :");
    cout<<endl;
    cin>>user;
    LOG_INFO("PASSWORD :");
    cin>>pass;

    ifstream input("database.txt");
    while(input>>u>>p)
    {
        if(u==user && p==pass)

        {
            count = START_VALUE;
        }
    }
    input.close();
    if(count==START_VALUE)
    {
        LOG_INFO("\nHello   ");
        cout<<user;
        LOG_INFO("\n<---LOGIN SUCCESSFUL--->\n");

	cout<<"1.Retrieve Data"<<endl;
	cout<<"2.Customer Support"<<endl;
	cout<<"3.Exit"<<endl;
	int Choice;
	cout<<"Enter Your Choice : ";
	cin>>Choice;
	switch(Choice)
	{
		case 1:
			connection();
			retrieve();
			//UserMenu();
			break;
		case 2:
			Server();
			//UserMenu();
			break;
		case 3:
			exit(0);
			break;
		default:
			cout<<"Enter Valid Choice"<<endl;
	}

        cout<<endl;
        cin.get();
        cin.get();
        Menu();
    }
    else
    {
        LOG_ERROR("\nLOGIN ERROR\nUsername or Password is incorrect\n");
        Menu();
    }
}



void registr()
{

    string reguser,regpass,ru,rp;
        
    LOG_INFO("Enter the username :");
    cin>>reguser;
   LOG_INFO("\nEnter the password :");
    cin>>regpass;

    ofstream reg("database.txt",ios::app);
    reg<<reguser<<' '<<regpass<<endl;
        
        
    LOG_INFO("\nRegistration Sucessful\n");
    Menu();
}


void forgot()
{
    int ch;

    LOG_INFO("Forgot your password\n");
    LOG_INFO("1.Search your id by username");
    cout<<endl;
    LOG_INFO("2.Search your id by password");
    cout<<endl;
    LOG_INFO("3.Main menu");
    cout<<endl;
    LOG_INFO("Enter your choice :");
    cin>>ch;
    switch(ch)
    {
        case 1:
        {
            int count=0;
            string searchuser,su,sp;
            LOG_INFO("\nEnter your username :");
            cin>>searchuser;

            ifstream searchu("database.txt");
            while(searchu>>su>>sp)
            {
                if(su==searchuser)
                {
                    count=START_VALUE;
                }
            }
            searchu.close();
            if(count==1)
            {
                LOG_INFO("\n\nHurray, Account found\n");
                LOG_INFO("\nYour password is ");
                cout<<sp;
                cin.get();
                cin.get();

                Menu();
            }
            else
            {
                LOG_ERROR("\nSorry, Your UserID not found in our database\n");
                LOG_INFO("\nPlease contact your system administrator for more details \n");
                cin.get();
                cin.get();
                Menu();
            }
                break;
        }
        case 2:
        {
            int count=0;
            string searchpass,su2,sp2;
            LOG_INFO("\nEnter the password :");
            cin>>searchpass;

            ifstream searchp("database.txt");
            while(searchp>>su2>>sp2)
            {
                if(sp2==searchpass)
                {
                    count=START_VALUE;
                }
            }
            searchp.close();
            if(count==1)
            {
               LOG_INFO("\nAccount found in the Database \n");
                LOG_INFO("\nYour Id is : ");
                cout<<su2;
                cin.get();
                cin.get();

                Menu();
            }
            else
            {
                LOG_ERROR("Sorry, We cannot find your account in our database \n");
                LOG_INFO("\nKindly contact your administrator for more information\n");
                cin.get();
                cin.get();
                Menu();
            }

            break;
        }

        case 3:
        {
            cin.get();
            Menu();
        }
        default:
            LOG_ERROR("Sorry, You entered wrong choice. Kindly try again");
            cout<<endl;
            forgot();
    }
}

void mainMenu()
{
    LOG_INFO("----------------WELCOME TO THE ONLINE LMS------------------");
    cout<<endl;
    LOG_INFO("//   1.Admin Login   //");
    cout<<endl;
    LOG_INFO("//   2.User Login    //");
    cout<<endl;
    int Choice;
    signal(SIGINT, sigint_handler);
    signal(SIGTSTP, sigtstp_handler);    
    LOG_INFO("Enter Login Type ");
    cin>>Choice;
    
    switch(Choice)
    {
        case 1:
            AdminLogin();
            break;
        
        case 2:
            Menu();
            break;
        default:
            LOG_ERROR("Enter Correct Login Type");
            cout<<endl;
    }
}




int main()
{
    LOG_INIT();

    mainMenu();
    signal(SIGINT, sigint_handler);
    signal(SIGTSTP, sigtstp_handler);
    
    LOG_DEINIT();
    return 0;
}
