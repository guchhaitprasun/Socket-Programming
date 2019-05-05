#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define SERVER_PORT 1997
#define BUFF_SIZE 2048
int main(int argc, char **argv)
{
    /*DECLARE VARIABLES*/
    struct sockaddr_in client_address;
    int client_socket;
    int bind_status;
    struct sockaddr_in server_address;
    unsigned char buffer[BUFF_SIZE];
    int sent_bytes;
    socklen_t server_address_len = sizeof(server_address);
    int received_bytes;

    /*INITIALISING SOCKADDR_IN STRUCTURE*/
    client_address.sin_family = AF_INET;
    client_address.sin_port = htons(0);
    client_address.sin_addr.s_addr = htonl(INADDR_ANY);
    memset(&(client_address.sin_zero), '\0', 8);

    /*CREATING SOCKET*/
    client_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (client_socket < 0)
    {
        perror("Error in creating socket !");
        return 0;
    }
    else
    {
        printf("Client Socketfd is created \n");
    }

    /*BINDING*/
    bind_status = bind(client_socket, (struct sockaddr *)&client_address,
                       sizeof(client_address));
    if (bind_status < 0)
    {
        perror("Error in binding i.e. binding failed");
        return 0;
    }
    else
    {
        printf("Bind success ! \n");
    }

    /*SETTING UP THE SOCKADDR_IN FOR SERVER WITH WHOM CLIENT WILL COMMUNICATE */
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    memset(&(server_address.sin_zero), '\0', 8);
    
    /*SENDING DATA/MESSSAGE TO SERVER AND PRINTING IT ON CONSOLE*/
    memset(buffer, 0, BUFF_SIZE);
    sprintf(buffer, "HELLO I'AM PRASUN GUCHHAIT ! ;)");
    sent_bytes = sendto(client_socket, buffer, strlen(buffer), 0, (struct sockaddr *)&server_address, server_address_len);
    if (sent_bytes < 0)
    {
        perror("Error in sentto from client to server!");
        return 0;
    }
    else
    {
        printf("Message Sent to Serve and bytes sent are: | %d | \n", sent_bytes);
    }
    close(client_socket);
    printf("~~~~~~~~~~~~~~~Client socket is shutdown!~~~~~~~~~~~~~~~~~~~~~~~");
}