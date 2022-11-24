CC=g++
CFLAGS=-c -Wall

all: lms server client

lms: login.cpp Database.o
	$(CC) login.cpp Database.o -o lms -l sqlite3

Database.o: Database.cpp
	$(CC) $(CFLAGS) Database.cpp -l sqlite3

server: server.cpp
	$(CC) server.cpp -o server

client: client.cpp
	$(CC) client.cpp -o client

