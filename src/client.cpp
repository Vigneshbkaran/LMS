#include<iostream>
#include <arpa/inet.h> // inet_addr()
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <strings.h> // bzero()
#include <sys/socket.h>
#include <unistd.h> // read(), write(), close()
using namespace std;
#define MAX 80
#define PORT 7070
#define SA struct sockaddr
int sockfd;

void func(int sockfd)
{
    char buff[MAX];
    int n;
    for (;;) {
        bzero(buff, sizeof(buff));
        cout<<"From User: ";
        n = 0;
        while ((buff[n++] = getchar()) != '\n');
            
        write(sockfd, buff, sizeof(buff));
        
	if (strncmp("exit", buff, 4) == 0) {
            cout<<"client Exit..."<<endl;
            exit(0);
        }
	bzero(buff,sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        cout<<"From Server : "<< buff<<endl;
        if (strncmp("exit", buff, 4) == 0) {
            cout<<"Closing client connection"<<endl;
	    cout<<"Program exited successfully.."<<endl;
            exit(0);
        }

    }
}
 
void sigtstp_handler(int signal)
{
	char msg[MAX];
	strcpy(msg,"exit");
	write(sockfd, msg, sizeof(msg));
	cout << "Closing client connection" << endl;
	cout << "Program exited successfully..." << endl; 
	exit(0);
}

int main()
{
    struct sockaddr_in servaddr;
    signal(SIGTSTP, sigtstp_handler);
    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        cout<<"socket creation failed..."<<endl;
        exit(0);
    }
    else
        cout<<"Socket successfully created.."<<endl;
    bzero(&servaddr, sizeof(servaddr));
 
    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);
	 
    // connect the client socket to server socket
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr))
        != 0) {
        cout<<"connection with the server failed..."<<endl;
        exit(0);
    }
    else
        cout<<"connected to the server.."<<endl;
 
    // function for chat
    func(sockfd);
 
    // close the socket
    close(sockfd);
}
