# Two-Way-Message
### socket program to perform two-way message transfer using the User Datagram Protocol**

## Development Environmnet 
- **Operating System**  : Ubuntu 18.04 LTS
- **IDE**               : Eclipse Integrated development environment (IDE)
- **Integration**       : Eclipse CDT (C/C++ Development Tool) g++
- **Compiler**          : Linux gcc

## Genreal Overview
- Server has a well-known port number (in this code it is 1997).
- Client initiate contact with the server
- Less difference in server and client code
- Client send datagram to the well-known server port, server extracts the client’s address from
the datagram it receives to reply back to client .
-Since there is infinite loop in Server side programming in receiving and sending part, so it acts
like a actual server which runs forever until someone shut down it manually or something mis
happen is there.
- The program can also be implemented like chat-box where in client side and server side there
is gets function takes user defined messages and send over client and server respectively.

### Windows User can also use this project by installing Eclipse CDT on Windows
**For Any Help or Issue Reach to me on [Gmail](mailto:prasunguchhait1997@gmail.com) or [LinkedIn](https://www.linkedin.com/in/iamprasunguchhait)**
