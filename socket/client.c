#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    // Create a socket
    int socketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFD < 0) {
        printf("Socket creation failed");
        return 0;
    }

    char* ip = "93.184.216.34"; // Example IP address
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(80);
    inet_pton(AF_INET,ip,&address.sin_addr.s_addr);

    // Connect to the server
    int result = connect(socketFD, (struct sockaddr *)&address, sizeof(address));

    if(result == 0)
            printf("socket creation successful\n");
    else
        printf("Socet failed");

    char* message;
    message = "GET \\ HTTP/1.1\r\nHOST:exaple.com\r\n\r\n";
    send(socketFD,message,strlen(message),0);

    char buffer[1024];
    recv(socketFD,buffer,1024,0);
    
    printf("response was\n%s",buffer);
    return 0;
}