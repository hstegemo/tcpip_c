#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int sockfd;
	int len;
	struct sockaddr_un address;
	int result;
	char ch = 'A';

	// Create a socket for the client
	sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

	// Name the socket as agreed with the server
	address.sun_family = AF_UNIX;
	strcpy(address.sun_path, "server_socket");
	len = sizeof(address);

	// Connect your socket to the server's socket
	result = connect(sockfd, (struct sockaddr *)&address, len);

	// You can now read and write via sockfd
	if(result == -1) {
		perror("oops: client1");
		exit(1);
	}
}
