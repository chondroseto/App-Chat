#include <stdio.h>/*library yang digunakan untuk operasi input output*/
#include <string.h>/*library yang digunakan untuk menampilkan string.*/
#include <sys/socket.h>/*library untuk membuat socket*/
#include <sys/types.h>/*library untuk menyediakan data types */
#include <netinet/in.h>/*library yang digunakan untuk structur Socket Address */

#define PORT 4444 /* mendeklarasikan port = 4444 */

void main(){
	int sockfd; /*deklarasi variabel yang digunakan untuk menyimpan nilai integer.*/
	struct sockaddr_in serverAddr;/*deklarasi variabel yang digunakan untuk menyimpan alamat ip server*/
	
	int newSocket; /*deklarasi variabel yang digunakan untuk menyimpan nilai integer.*/
	struct sockaddr_in newAddr; /*deklarasi variabel yang digunakan untuk menyimpan alamat ip baru.*/

	socklen_t addr_size; /*deklarasi variabel yang digunakan untuk size alamat ip.*/
	char buffer[1024]; /*deklarasi variabel yang digunakan untuk menyimpan char sebanyak 1024.*/

	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	/*untuk membuat socket dengan parameter yaitu :
	  AF_INET untuk menyatakan bahwa IP yang digunakan ipv4
	  SOCK_STREAM untuk menyatakan bahwa type socketnya berjenis TCP*/
	printf("[+]Server Socket Berhasil dibuat.\n"); /*menampilkan teks pada konsole*/
	
	memset(&serverAddr, '\0', sizeof(serverAddr));/*menghapus isi dari variable yang digunakan server address*/
	serverAddr.sin_family = AF_INET; /*memasukan informasi address format ke variabel*/
	serverAddr.sin_port = htons(PORT);/*memasukan informasi port ke variabel*/
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); /*memasukan informasi alamat ke variabel*/

	bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	/*mengikat informasi alamat IP yang digunakan untuk pengiriman antar terminal atau mesin .*/
	printf("[+]mengikat ke Port number %d.\n", 4444); /*menampilkan teks pada konsole*/

	listen(sockfd, 5); /*untuk menyatakan bahwa socket server siap menerima koneksi dengan waktu tunggu 5.*/
	printf("[+]mencari koneksi...\n"); /*menampilkan teks pada konsole*/
	newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size); 
	/*menerima koneksi yang masuk pada server serta alamat client disimpan di variabel*/

	strcpy(buffer, "mantap terkirim"); /*kata yang akan tampil pada terminal client*/
	send(newSocket, buffer, strlen(buffer), 0); /*mengirim kata ke client sesuai alamat client*/
	printf("[+]koneksi tertutup.\n"); /*menampilkan teks pada konsole*/
}