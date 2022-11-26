#include <iostream>
#include <iomanip>
#include <string>
#include <sqlite3.h>
#include "Database.h"
using namespace std;


sqlite3 *DB;
sqlite3_stmt *stmt;
int result, bookid;
string query, bookname, bookURL;

/*main code for database to insert, delete or retrieve books from database
 *By providing book ID, book name and URL of books we can provide proper book details for user
 *User can download books digitally by the URL mentioned in database
 */

void Database() {
    int choice;
    char yes;
    cout << "------------------------------------------------------" << endl;
    cout << "--------------- Welcome To DataBase ------------------" << endl;
    cout << "------------------------------------------------------" << endl;
    do {
        cout << "\n1.Insert books" << endl << "2.Retrieve books" << endl << "3.Delete books" << endl;
        cin >> choice;
        connection();
        switch (choice) {
                case 1:insertbooks();
                       break;
                case 2:retrieve();
                       break;
                case 3:deletebooks();
                       break;
                default:
                       cout << "Enter valid choice" << endl;
        }
        cout << "Do you want to continue(y/n)" << endl;
        cin >> yes;
    }while (yes == 'y');
    sqlite3_close(DB);
}

 // To connect to database
 // To create a database with required details
void connection() {
    if (sqlite3_open("books.db", &DB) == SQLITE_OK) {
        result = sqlite3_prepare_v2(DB, "CREATE TABLE IF NOT EXISTS library(bookid INT, bookname VARCHAR(50), bookURL VARCHAR(80));", -1, &stmt, NULL);
        sqlite3_step(stmt);     // To read all the rows within database
        sqlite3_finalize(stmt);  // To finalize end of database
        if (result != SQLITE_OK) {
            cout << "error: " << sqlite3_errmsg(DB) << endl;
        }
    }
}

/*To Insert books to database
 * Bookid, Bookname and bookURL should be provided
 * Enables user to download digitally */
void insertbooks() {
    cout << "Enter Book ID" << endl;
    cin >> bookid;
    cout << "Enter Book Name" << endl;
    cin >> bookname;
    cout << "Enter URL" << endl;
    cin >> bookURL;
    query = "INSERT INTO library(bookid,bookname,bookURL) VALUES(?,?,?);";
    result = sqlite3_prepare_v2(DB, query.c_str(), -1, &stmt, NULL);  // Binds with previosly given information within a row
    sqlite3_bind_int(stmt, 1, bookid);
    sqlite3_bind_text(stmt, 2, bookname.c_str(), bookname.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, bookURL.c_str(), bookURL.length(), SQLITE_TRANSIENT);
    /*To rebind the data sqlite transient is used
    * It makes its own copy of string and free memory */
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (result != SQLITE_OK) {
        cout << "error: " <<sqlite3_errmsg(DB) << endl;
    }
    else {
        cout << "data inserted successfully" << endl;
    }
}

// Function to display the contents of the Database
void retrieve() {
    query = "SELECT * FROM library";
    result = sqlite3_prepare_v2(DB, query.c_str(), -1, &stmt, NULL);
    if (result != SQLITE_OK) {
        cout << "error: " << sqlite3_errmsg(DB) << endl;
    }
    else {
        while ((result = sqlite3_step(stmt) == SQLITE_ROW)) {
            cout << "bookid" << "\t" << "bookname" << "\t" << "bookURL" << endl;
            cout << sqlite3_column_text(stmt, 0) << "\t" << sqlite3_column_text(stmt, 1) << "\t" << sqlite3_column_text(stmt, 2) << endl;
        }
        cout << "Books displayed successfully" << endl;
    }
}
// Function to delete the contents of the Database based on the given Book ID
void deletebooks() {
    int bookid;
    cout << "Enter Book ID which you want to delete" << endl;
    cin >> bookid;
    getchar();
    query = "DELETE FROM library WHERE bookid = ?";
    result = sqlite3_prepare_v2(DB, query.c_str(), -1, &stmt, NULL);
    sqlite3_bind_int(stmt, 1, bookid);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
        cout << "error: " <<sqlite3_errmsg(DB) << endl;
    }
    else {
                cout << "Book deleted successfully" << endl;
    }
}
