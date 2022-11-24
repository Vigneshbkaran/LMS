#include<iostream>
#include<iomanip>
#include<sqlite3.h>
#include "Database.h"
using namespace std;


sqlite3 *DB;
sqlite3_stmt *stmt;
int result,bookid;
string query,bookname,bookURL;



void Database()
{
    int choice;
    char yes;
    cout<<"------------------------------------------------------"<<endl;
    cout<<"--------------- Welcome To DataBase ------------------"<<endl;
    cout<<"------------------------------------------------------"<<endl;
    do
    {
        cout<<"1.Insert books"<<endl<<"2.Retrieve books"<<endl<<"3.Delete books"<<endl;
        cin>>choice;
        connection();
        switch(choice){
                case 1:insertbooks();
                       break;
                case 2:retrieve();
                       break;
                case 3:deletebooks();
                       break;
                default:
                       cout<<"Enter valid choice"<<endl;
        }
        cout<<"Do you want to continue(y/n)"<<endl;
        cin>>yes;
    }while(yes=='y');
    sqlite3_close(DB);
}


void connection()
{
    if(sqlite3_open("books.db",&DB)==SQLITE_OK)
    {
        result = sqlite3_prepare_v2(DB,"CREATE TABLE IF NOT EXISTS library(bookid INT, bookname VARCHAR(50), bookURL VARCHAR(80));", -1, &stmt, NULL);
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
        if(result != SQLITE_OK)
        {
            cout<<"error: "<<sqlite3_errmsg(DB)<<endl;
        }
    }
}


void insertbooks()
{
    cout<<"Enter Book ID"<<endl;
    cin>>bookid;
    cout<<"Enter Book Name" << endl;
    cin>>bookname;
    cout << "Enter URL" << endl;
    cin>>bookURL;
    query = "INSERT INTO library(bookid,bookname,bookURL) VALUES(?,?,?);";
    result = sqlite3_prepare_v2(DB,query.c_str(), -1, &stmt, NULL);
    sqlite3_bind_int(stmt, 1, bookid);
    sqlite3_bind_text(stmt, 2, bookname.c_str(), bookname.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, bookURL.c_str(), bookURL.length(), SQLITE_TRANSIENT);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if(result != SQLITE_OK)
    {
        cout<<"error: "<<sqlite3_errmsg(DB)<<endl;
    }
    else
    {
        cout<<"data inserted successfully"<<endl;
    }
}

void retrieve()
{
    query = "SELECT * FROM library";
    result = sqlite3_prepare_v2(DB,query.c_str(), -1, &stmt, NULL);
    if(result != SQLITE_OK)
    {
        cout<<"error: "<<sqlite3_errmsg(DB)<<endl;
    }
    else
    {
        while( (result = sqlite3_step(stmt) == SQLITE_ROW))
        {
            cout<<"bookid"<<"\t"<<"bookname"<<"\t"<<"bookURL"<<endl;
            cout<<sqlite3_column_text(stmt,0)<<"\t"<<sqlite3_column_text(stmt,1)<<"\t"<<sqlite3_column_text(stmt,2)<<endl;
        }
        cout<<"Books displayed successfully"<<endl;
    }
}
void deletebooks()
{
    int bookid;

    cout<<"Enter Book ID which you want to delete"<<endl;
    cin>>bookid;
    getchar();
    query = "DELETE FROM library WHERE bookid = ?";
    result = sqlite3_prepare_v2(DB,query.c_str(), -1, &stmt, NULL);
    sqlite3_bind_int(stmt, 1, bookid);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    
    if(result != SQLITE_OK)
    {
        cout<<"error: "<<sqlite3_errmsg(DB)<<endl;
    }
    else
    {
                cout<<"Book deleted successfully"<<endl;
    }
}
