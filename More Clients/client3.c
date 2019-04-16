#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 4444

void main(){

	

	int clientSocket;

	struct sockaddr_in serverAddr;

	char buffer[1024];



	clientSocket = socket(PF_INET, SOCK_STREAM, 0);

	printf("[+]Client Socket Berhasil dibuat\n");



	memset(&serverAddr, '\0', sizeof(serverAddr));

	serverAddr.sin_family = AF_INET;

	serverAddr.sin_port = htons(PORT);

	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");



	connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

	printf("[+]terhubung ke Server.\n");

    while(1)
    {
	bzero(buffer,1024);
           read(clientSocket,buffer,1024);
           printf("Client 1: %s",buffer);
 	
	int c1=strncmp("Bye" , buffer, 3);
   		if(c1 == 0)
               break;
        
	
	bzero(buffer,1024);
           read(clientSocket,buffer,1024);
     	      printf("Client 2: %s",buffer);
     
	   int c2 = strncmp("Bye" , buffer , 3);
        if(c2 == 0)
               break;

	printf("Client : ");
        bzero(buffer,1024);
        fgets(buffer,1024,stdin);
        write(clientSocket,buffer,strlen(buffer));
        
	int c3 = strncmp("Bye" , buffer , 3);
        if(c3 == 0)
               break;

	bzero(buffer,1024);
           read(clientSocket,buffer,1024);
     	      printf("Client 4: %s",buffer);
     
	   int c4 = strncmp("Bye" , buffer , 3);
        if(c4 == 0)
               break;
    }
	
	printf("[+]koneksi tertutup.\n");

}
