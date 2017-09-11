#ifndef FTPClient_H
#define FTPClient_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "Program.h"

//#define NDEBUG

#ifndef NDEBUG
#define DEBUG_DESTRUCTOR clog << "-> Line " << __LINE__ << " in file " << __FILE__ << ": " << endl << "Destructor." << endl;
#define DEBUG_CONSTRUCTOR clog << "-> Line " << __LINE__ << " in file " << __FILE__ << ": " << endl << "Constructor." << endl;
#else
#define DEBUG_DESTRUCTOR
#define DEBUG_CONSTRUCTOR
#endif

#define DEFAULT_BUFLEN 0x10240
#define NUMBER_DIGIT_PORT 10


class FTPClient: public Program
{
private:
	SOCKET controlSocket, dataSocket;
	char controlPort[NUMBER_DIGIT_PORT] = "21";
	char dataPort[NUMBER_DIGIT_PORT];
	char* ipADDRESS;
public:
	FTPClient(void);
	~FTPClient(void);
	int execute(int argc, char **argv);
	void closeProgram(void);
	void getIPServer(char* ipADDRESS);
	void connectServer(char *port, char *ipServer, SOCKET &connectSocket);
	void login(char* username, char* password);
	void establishDataChanel(void);

	friend void sendCommand(FTPClient *myFTPClient, char* sendbuf);
	friend int receiveResponse(FTPClient *myFTPClient, char* recvbuf);
	
	void closeConnect(void);
};

#endif