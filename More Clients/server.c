#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 4444

void main(){



	int sockfd;

	struct sockaddr_in serverAddr;



	int client1,client2,client3,client4;

	struct sockaddr_in newAddr;



	socklen_t addr_size;

	char buffer[1024];



	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	printf("[+]Server Socket Berhasil dibuat.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));



	serverAddr.sin_family = AF_INET;

	serverAddr.sin_port = htons(PORT);

	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");



	bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

	printf("[+]mengikat ke Port number %d.\n", 4444);


	listen(sockfd, 5);

	printf("[+]mencari koneksi client 1...\n");

	client1 = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
	
	listen(sockfd, 5);

	printf("[+]mencari koneksi client 2...\n");
	
	client2 = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);

	listen(sockfd, 5);

	printf("[+]mencari koneksi client 3...\n");
	
	client3 = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);

	listen(sockfd, 5);

	printf("[+]mencari koneksi client 4...\n");
	
	client4 = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);

	printf("[+]Semua Client Tersambung....\n");


	while(1)
     	{
	
           bzero(buffer,1024);
           read(client1,buffer,1024);
         
	  printf("Client 1 : %s",buffer);
          write(client2,buffer,strlen(buffer));
          write(client3,buffer,strlen(buffer));
          write(client4,buffer,strlen(buffer));
           
	 int c1=strncmp("Bye" , buffer, 3);
   		if(c1 == 0)
               break;
	
	bzero(buffer,1024);
           read(client2,buffer,1024);
          
	 printf("Client 2: %s",buffer);
	write(client1,buffer,strlen(buffer));
          write(client3,buffer,strlen(buffer));
          write(client4,buffer,strlen(buffer));
           
           int c2=strncmp("Bye" , buffer, 3);
           if(c2 == 0)
               break;
	
	 bzero(buffer,1024);
           read(client3,buffer,1024);
         
	  printf("Client 3 : %s",buffer);
          write(client1,buffer,strlen(buffer));
          write(client2,buffer,strlen(buffer));
          write(client4,buffer,strlen(buffer));
           
	 int c3=strncmp("Bye" , buffer, 3);
   		if(c3 == 0)
               break;
	
	 bzero(buffer,1024);
           read(client4,buffer,1024);
         
	  printf("Client 4 : %s",buffer);
          write(client1,buffer,strlen(buffer));
          write(client2,buffer,strlen(buffer));
          write(client3,buffer,strlen(buffer));
           
	 int c4=strncmp("Bye" , buffer, 3);
   		if(c4 == 0)
               break;
	

        }

	printf("[+]koneksi tertutup.\n");

}
