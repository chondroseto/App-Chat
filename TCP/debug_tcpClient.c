#include <stdio.h> /*library yang digunakan untuk operasi input output*/
#include <string.h> /*library yang digunakan untuk menampilkan string.*/
#include <sys/socket.h>/*library untuk membuat socket*/
#include <sys/types.h> /*library untuk menyediakan data types */
#include <netinet/in.h>/*library yang digunakan untuk structur Socket Address */

#define PORT 4444 /* mendeklarasikan port = 4444 */

void main(){
	int clientSocket; /*deklarasi variabel yang digunakan untuk nilai menyimpan integer.*/
	struct sockaddr_in serverAddr; /*deklarasi variabel yang digunakan untuk menyimpan alamat ip server*/
	char buffer[1024]; /*deklarasi variabel yang digunakan untuk menyimpan char sebanyak 1024.*/

	clientSocket = socket(PF_INET, SOCK_STREAM, 0); 
	/*untuk membuat socket dengan parameter yaitu :
	  PF_INET adalah paket family berdasarkan protokol
	  SOCK_STREAM untuk menyatakan bahwa type socketnya berupa TCP atau full duplex*/
	printf("[+]Client Socket Berhasil dibuat.\n"); /*menampilkan teks pada konsole*/

	memset(&serverAddr, '\0', sizeof(serverAddr));/*menghapus isi dari variable yang digunakan server address*/
	serverAddr.sin_family = AF_INET; /*memasukan informasi address format ke variabel*/
	serverAddr.sin_port = htons(PORT); /*memasukan informasi port ke variabel*/
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); /*memasukan informasi alamat ke variabel*/

	connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	/*untuk menghubungkan client dengan server sesuai dengan alamat server.*/
	printf("[+]terhubung ke Server.\n"); /*menampilkan teks pada konsole*/

	recv(clientSocket, buffer, 1024, 0);/*untuk menaruh kata yang diterima dari server*/
	printf("[+]Data yang diterima: %s\n", buffer); /*menampilkan kata yang diterima pada konsole*/
	printf("[+]koneksi tertutup.\n"); /*menampilkan teks pada konsole*/

}
