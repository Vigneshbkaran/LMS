Server side:
Void func(int connfd)
{
      read (connfd, buff, sizeof(buff))
      Print buffer which contains client contents
      If strncmp(“exit”,buff,4) ==0
      Print server exit
      Copy server message in buffer
      write (connfd, buff,sizeof(buff)) 
      If strncmp(“exit”,buff,4) ==0
      Print closing server connection
      Print program exited successfully
}
Void sigtstp_handler(int signal)
{
       Strcpy(msg, “exit)
        Print caught ^Z
        Print closing server connection
        write(connfd, msg, sizeof(msg))
}
In main function
{
If socket == fail
          Print socket creation failed
Else
          Print socket creation is successful
If bind != 0
          Print socket bind failed
Else
          Print socket successfully binded
If listen !=0
           Print listen failed
Else
          Print server listening
If connfd<0
           Print server accept failed
Else
          Print connection established successfully
Call to func(int connfd)
close socket
}
