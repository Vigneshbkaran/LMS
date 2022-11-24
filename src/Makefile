CC=g++
CFLAGS=-c -Wall

all: eBooks server client

eBooks: main.cpp Database.o
	$(CC) main.cpp Database.o -o eBooks -l sqlite3

Database.o: Database.cpp
	$(CC) $(CFLAGS) Database.cpp -l sqlite3

server: server.cpp
	$(CC) server.cpp -o server

client: client.cpp
	$(CC) client.cpp -o client

clean:
	rm *.o
