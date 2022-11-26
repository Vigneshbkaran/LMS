Void func (int sockfd)
{
         Establishes communication with server.
          Write (sockfd, buff, sizeof(buff))
            Accepts admin inputs.
          If (strncmp (“exit”, buff,4) ==0)
          Client will exit from connection.
           Read (sockfd, buff, sizeof(buff))
            Displays buffer which contains user contents. 
           }
Void sigtstp_handler (int signal)
{
             Strcpy (msg,” exit”)
              Prints “closing client connection”
               prints “program exited successfully”
}
Int main ()
{
                Sockfd=socket (af_inet, sock_stream,0)
                 If sockfd== -1
                            Prints” socket creation failed”
                  Else
                            Prints "Socket successfully created"
        If Connect ()! =0
              Prints "connection with the server failed"
        Else
	       Prints “connected to the server"
}
