#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <Windows.h>
#include <tchar.h>
#include <winsock2.h> // Port Routing | https://docs.microsoft.com/en-us/windows/win32/api/winsock2/
#include <ws2tcpip.h> // Port Routing | https://docs.microsoft.com/en-us/windows/win32/api/winsock2/
#include <dlfcn.h> // Library Checking | https://linux.die.net/man/3/dlopen
#include "resource.rc" // Icon

// Including Files

#include "header.h"
#include "functions.cpp"

// Preparations

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "ws2_32.lib")
using namespace std;

int main(int argc , char *argv[]) {

  // Color Win32 API

  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  WORD saved_attributes;
  GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  saved_attributes = consoleInfo.wAttributes;

  // Global Variables

  int option, portoption, settingoption, settingoption1;

  int i, debugging = 0;

  int startport, endport;

  // Presentation

  cout << "Copyright Tovape | tovape.github.io\n\n";

  // Checking Libs

  cout << libcheck() << " Libraries Loaded.\n\n";

  sleep(1);

  // Init Winsock

  WSADATA wsa;
  SOCKET sock;

  if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
    cout << "[";
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << "Error";
    SetConsoleTextAttribute(hConsole, saved_attributes);
    cout << "] Initializing WinSock, " << WSAGetLastError() << "\n";
    return 1;
  }

  cout << "[";
  SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
  cout << "OK";
  SetConsoleTextAttribute(hConsole, saved_attributes);
  cout << "] WinSock Started\n";

  // Init Sockets

	if ((sock = socket(AF_INET, SOCK_STREAM, 0 )) == INVALID_SOCKET) {
    cout << "[";
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << "Error";
    SetConsoleTextAttribute(hConsole, saved_attributes);
    cout << "] Initializing Socket, " << WSAGetLastError() << "\n";
	}

  cout << "[";
  SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
  cout << "OK";
  SetConsoleTextAttribute(hConsole, saved_attributes);
  cout << "] Socket Created\n";

  sleep(1);
  system("cls");

  // Menu

  menu:

  cout << "\n\tWindows Inspect Manager\n";
  cout << "\nDebugging [";

  if (debugging == 0) {
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    cout << "OFF";
    SetConsoleTextAttribute(hConsole, saved_attributes);
  } else {
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout << "ON";
    SetConsoleTextAttribute(hConsole, saved_attributes);
  }

  cout << "]\n\n";

  cout << "(1) Port Inspection\n";
  cout << "(2) Ram Usage\n";
  cout << "(3) Cpu Usage\n";
  cout << "(4) Computer Stats\n";
  cout << "(5) TCP Server\n";
  cout << "(6) Settings\n";
  cout << "(7) Exit\n";

  cin >> option;

  if (option <= 0 || option > 7) {
    cout << "Invalid Choice\n";
    sleep(3);
    system("cls");
    goto menu;
  }

  if (option == 1) {
    system("cls");
    ports:

    cout << "\tPort Inspection\n\n";

    cout << "(1) Scan\n";
    cout << "(2) Other\n";
    cout << "(3) Other\n";
    cout << "(4) Other\n";
    cout << "(5) Other\n";

    cin >> portoption;

    if (portoption <= 0 || portoption > 5) {
      cout << "Invalid Choice\n";
      sleep(3);
      system("cls");
      goto ports;
    }

    if (portoption == 1) {
      system("cls");
      cout << "Select the Range to Scan in Local Machine\n";
      cout << "From: ";
      cin >> startport;
      cout << "\nTo: ";
      cin >> endport;
      cout << "\n";

      int openedPorts = 0, closedPorts = 0;
      struct sockaddr_in server;
      server.sin_addr.s_addr = inet_addr("127.0.0.1");

      for (i = startport ; i <= endport ; i++) {

        server.sin_family = AF_INET;
      	server.sin_port = htons(i);

      	if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
      		cout << "Port " << i << " is Closed\n";
          closedPorts++;
      	} else {
          cout << "Port " << i << " is Open\n";
          openedPorts++;
        }

        fflush(stdout);
      }

      cout << "\n\tStats\n\n";
      cout << closedPorts << " Ports are Closed.\t";
      cout << openedPorts << " Ports are Open.\n";

      sleep(10);
      system("cls");
      goto menu;
    }

    system("cls");
    goto menu;
  }

  if (option == 2) {
    ramUsage();
    sleep(7);
    system("cls");
    goto menu;
  }

  if (option == 3) {
    cpuUsage();
    sleep(7);
    system("cls");
    goto menu;
  }

  if (option == 4) {
    pcStats();
    sleep(7);
    system("cls");
    goto menu;
  }

  if (option == 5) {
    system("cls");
    tcp:

    /*

    cout << "\tTCP Server\n\n";

    // Bind the ip address and port to a socket
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    hint.sin_addr.S_un.S_addr = INADDR_ANY;

    bind(sock, (sockaddr*) &hint, sizeof(hint));

    // Tell Winsock the socket is for listening
    listen(sock, SOMAXCONN);

    // Wait for a Connection
    sockaddr_in client;
    int clientSize = sizeof(client);

    SOCKET clientSocket = accept(sock, (sockaddr*) &client, &clientSize);

    if (clientSocket == INVALID_SOCKET) {
      cout << "[";
      SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
      cout << "Error";
      SetConsoleTextAttribute(hConsole, saved_attributes);
      cout << "] Invalid Socket\n";
    } else {
      cout << "[";
      SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
      cout << "Ok";
      SetConsoleTextAttribute(hConsole, saved_attributes);
      cout << "] Valid Socket\n";
    }

    char host[NI_MAXHOST];    // Client Remote Name
    char service[NI_MAXHOST]; // Service the client is connected on

    ZeroMemory(host, NI_MAXHOST);
    ZeroMemory(service, NI_MAXHOST);

    if (getnameinfo((sockaddr*) &client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
      cout << "[";
      SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
      cout << "Ok";
      SetConsoleTextAttribute(hConsole, saved_attributes);
      cout << "] " << host << " connected on port " << service << "\n";
    } else {
      cout << "[";
      SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
      cout << "Ok";
      SetConsoleTextAttribute(hConsole, saved_attributes);
      inet_ntoa(AF_INET, &client.sin_addr, host, NI_MAXHOST);
      cout << "] " << host << " connected on port " << ntohs(client.sin_port) << "\n";
    }

    // Close Socket
    closesocket(sock);

    // While Loop, accept messages
    char buf[4096];

    while(true) {
        ZeroMemory(buf, 4096);

        // Wait for client to send data

        int bytesReceived = recv(clientSocket, buf, 4096, 0);
        if (bytesReceived == SOCKET_ERROR) {
          cout << "[";
          SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
          cout << "Error";
          SetConsoleTextAttribute(hConsole, saved_attributes);
          cout << "] in recv()";
          break;
        }

        if (bytesReceived == 0) {
          cout << "\nClient Disconnected\n";
          break;
        }

        // Echo Message back to client

        send(clientSocket, buf, bytesReceived + 1, 0);

    }

    // Close the socket

    closesocket(clientSocket);

    // Cleanup

    WSACleanup();

    */

    sleep(3);
    system("cls");
    goto menu;
  }

  if (option == 6) {
    system("cls");
    settings:

    cout << "\tSettings\n\n";

    cout << "(1) Debugging\n";
    cout << "(2) Other\n";
    cout << "(3) Other\n";
    cout << "(4) Other\n";
    cout << "(5) Other\n";

    cin >> settingoption;

    if (settingoption <= 0 || settingoption > 5) {
      cout << "Invalid Choice\n";
      sleep(3);
      system("cls");
      goto settings;
    }

    if (settingoption == 1) {
      system("cls");
      cout << "(0) Turn Off Debugging\n";
      cout << "(1) Turn On Debugging\n";
      cin >> settingoption1;

      debugging = settingoption1;

      system("cls");
      goto menu;
    }

    system("cls");
    goto menu;
  }

  if (option == 7) {
    cout << "\tExit\n\n";
    sleep(3);
    return 0;
  }

  sleep(2);

  return 0;
}
