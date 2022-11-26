
void login();
void registr();
void forgor();
void Admin_Login();
void Server()
{
	Declare a Null Poiner is {"./Server, NULL"};
	execv Function to ignore the all remaining function from void Server
}

void Client()
{
	Declare a Null Poiner is {"./Client, NULL"};
	execv Function to ignore the all remaining function from void Client
}

Void menu()
{
       Print welcome to login page
       Prints 1.Login  2.Register 3.Forgot password (or)username 4.customer support 5. Exit
       Int choice
       Print Enter your choice
       asks user to enter the choice
        Switch(choice)
       {
         Case 1: login()
         Case 2: registr()
         Case 3: forgot()
         Case 4: Server()
         Case 5: Print thanks for using this program. This program is created by group-1
         Default: Print You’ve made a mistake, Try again…
          And returns back to Menu()
      }
}
Void userMenu()
{
        Prints 1. Retrieve data 2. Customer support 3. exit
         Int choice
        Print Enter your choice
        asks user to enter the choice
        switch (choice)
        {
          Case 1: retrieve()
          Case 2: server()
          Case 3: exit(0)
          default: Print enter valid choice
        }
}
Void login()
{
       Int count
        String user, pass, user_, pass_
        Print please enter the following details
        Print Username, password
        And ask user to enter them
        Input(database.txt) file is created to store registered details of user
        while(input>>user_>>pass_)
        {
                If(user_ == user &7 pass_ ==pass)
                  count = start_value
                 close the file
                 if(count == start_value)
                  {
                      Prints hello
                      Prints login successful
                      Prints 1. Retrieve data 2. Customer data 3. Exit
                       Int choice
                       Print enter the choice
                       asks user to enter choice
                        switch(choice)
                        {
                         Case 1: connection()
                                       Retrieve()
                         Case 2: server()
                         Case 3: exit(0)
                         Default : enter valid choice
                 Menu()    
         }
}
Void forgot()
{
      Int ch
      Print forgot your password
      Prints 1. Search your is by username 2. Search your id by password
      3. Main menu
      Prints enter your choice  and ask for user input
      Switch(ch)
      {
         Case 1: {
                    Int count=0
                    String searchuser, search_user, search_pass
                    Print enter your username and ask for user choice
                    serachu(database.txt) is used to store registered credentials of user
                    While(search>>serach_user>>search_pass)
                    {
                       If (search_user==searchuser)
                           count=start_value
                           search.close()
                       if (count==start_value)
                       {
                          Print Hurray, Account found
                          Print your password
                          Menu()
                        }
                        Else
                        {
                           Print Sorry, Your UserId not found in our database
                           Print Please contact your system administrator for more details
                           Menu()
                         }
                      break;
                   Case 2: 
                   {
                        Int count =0
                        String searchpass,searchuser2,searchpass2
                        Print enter the password and ask for user to enter
                        search(database.txt) is created to store registered credentials of user
                        while(serachp>>searchuser2>>searchpass2)
                        {
                           If(searchpass2==serachpass)
                           Count=start_value
                        }
                        searchp.close()
                        if(count==1)
                        {
                           Print Account found in the database
                           Print your ID is and ask user to enterserachuser2
                           Menu()
                         }
                         Else
                         {
                            Print Sorry we cannot find your account in our database
                            Print kindly contact your administrator for more information
                            Menu()
                         }
                    }
                    Case 3:
                    {
                          Menu()
                    }
                    Default:
                         Print Sorry, You entered wrong choice. Kindly try again
                         forgot()
              }                 
         }
 }
  
Adminlogin ()
{
 	Do
	{
		Reads password from admin
   		If (input_pin ==pin)
		{
			Prints” Login success”
			Provides below choice to admin 
                      1.accessing database
                      2.for customer support
			Switch(choice)
                      {
                      	Case 1: Database ();
                             Admin get access to database to perform certain operations
                             Like insert, delete, and retrieve.
                              Case 2: client ()
				    Calls client-side program for Establishment of communication 
                                                             If admin enter none of above choice, then 
				  Prints “enter valid choice”
			}
                                  }
                                  Else
     {
	     If admin enter wrong password, then variable warning will be incremented and
                    Prints “try again”
        }
 }
While (warning<=3 && input_pin! =pin);
{
If (warning >3)
{
         Prints “account blocked”
}
}
}
