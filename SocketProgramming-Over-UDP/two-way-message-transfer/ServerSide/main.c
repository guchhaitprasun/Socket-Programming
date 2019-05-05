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
    struct sockaddr_in server_address;
    int server_socket;
    int bind_status;
    int received_bytes;
    unsigned char buffer[BUFF_SIZE];
    struct sockaddr_in client_address;
    int sent_bytes, i = 1;
    socklen_t client_address_len = sizeof(client_address);
    
    //DECLARING MESSAGE
    const char *svr_msg[5];
    svr_msg[1] = "Hi First Client, I am server ";
    svr_msg[2] = "i'am fine first client, what about you !";
    svr_msg[3] = "why? what happen client !";
    svr_msg[4] = "ohh poor boy, Don't worry everything will be fine !!!";
    svr_msg[5] = " But i'am Still running";
    
    /*REST BODY*/
    printf("The value of AF_INET is %d \n", AF_INET);
    printf("The value of SERVER_PORT is %d \n", SERVER_PORT);
    printf("The address of computer is %d \n", INADDR_ANY);
    
    /*INITIALISING SOCKADDR_IN STRUCTURE*/
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    memset(&(server_address.sin_zero), '\0', 8);
    printf("Server Address details: \n 1. Server Port: %hu \n 2. Address: %u \n 3:
        Family %
        hhu \n ", server_address.sin_port, server_address.sin_addr.s_addr,
        server_address.sin_family
    );
    
    /*CREATING SOCKET*/
    server_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_socket < 0)
    {
        perror("Error in creating socket !");
        return 0;
    }
    else
    {
        printf("Server Socketfd is created \n");
    }
    
    /*BINDING*/
    bind_status = bind(server_socket, (struct sockaddr *)&server_address,
        sizeof(server_address)
    );
    if (bind_status < 0)
    {
        perror("Error in binding i.e. binding failed");
        return 0;
    }
    else
    {
        printf("~~~~~~~~~~Bind success !~~~~~~~~~~ \n");
    }
    
    /*RECEIVING DATA/MESSAGE FROM CLIENT AND PRINTING IT ON CONSOLE*/
    while (i)
    {
        memset(buffer, 0, BUFF_SIZE);
        printf("Waiting for receiving data on socket created ! \n");
        received_bytes = recvfrom(server_socket, buffer, BUFF_SIZE, 0, (struct sockaddr *)&client_address, &(client_address_len));
        if (received_bytes != 0)
        {
            buffer[received_bytes] = 0;
            printf ("Received message from client: | %s | and bytes received is: | %d |
                \n", buffer,received_bytes
            );

            /*SENDING DATA/MESSSAGE TO CLIENT AND PRINTING IT ON CONSOLE*/
            memset (buffer,0,BUFF_SIZE);
            sprintf (buffer,svr_msg[i]);
            sent_bytes = sendto (server_socket, buffer, strlen(buffer), 0, (struct
            sockaddr *) &client_address, client_address_len);
            if (sent_bytes < 0)
            {
                perror("Error in sentto !");
                return 0;
            }
            else
            {
                printf ("Sent message to client is: | %s | and bytes sent is: | %d |
                    \n\n", buffer, sent_bytes
                );
            }
        }
        i++;
    }
}