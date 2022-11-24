CC=g++
CFLAGS=-c -Wall

all: lms server client

lms: login.cpp
	$(CC) login.cpp -o lms -l sqlite3

server: server.cpp
	$(CC) server.cpp -o server

client: client.cpp
	$(CC) client.cpp -o client

