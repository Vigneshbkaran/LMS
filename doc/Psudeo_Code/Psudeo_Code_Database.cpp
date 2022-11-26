Welcome to Database
Connect() 
{
	Create Database
	Open Database
	If(Database created) 
  {
		Table named library is created
		Parameters are Book ID, Book Name, Book URL
  }
	Else
  {
	Table library is not created
	}
Switch () 
{
   	1.Insert
    2.Retrieve
	  3.Delete
}
Insert{
	Print Enter Book ID, Book Name, Book URL
	Read Book ID, Book Name, Book URL from user
	Insert to Database
	Bind with present data
	If(Data is inserted) {
		Insertion successful
	}
	Else {
		Insertion Failed
	}
}
Retrieve{
	Select from library
	Read data from library
	Display the information present in library
	}
Delete books{
	Delete the book information which you want to delete by Book ID as key
	Print Enter book ID
	Read Book ID from user
	Delete from library
	If(book information is removed from library) {
		Deletion successful
}
Else{
	Deletion failed
}
}
	

