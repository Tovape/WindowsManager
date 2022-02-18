#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <Windows.h>
#include <winsock2.h> // Port Routing | https://docs.microsoft.com/en-us/windows/win32/api/winsock2/
#include <ws2tcpip.h> // Port Routing | https://docs.microsoft.com/en-us/windows/win32/api/winsock2/
#include <dlfcn.h> // Library Checking | https://linux.die.net/man/3/dlopen
#include "pugixml.hpp" // XML Parser | https://pugixml.org/
#include "resource.rc"

// Including Files

#include "header.h"
#include "macros.cpp"

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main(int argc , char *argv[]) {

  //Color Win32 API

  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  WORD saved_attributes;
  GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  saved_attributes = consoleInfo.wAttributes;

  // Global Variables

  int option, portoption, settingoption, settingoption1;

  int i, debugging = 0;

  // Dlfcn

  void *handle;
  double (*cosine)(double);
  char *error;

  // Presentation

  cout << "Copyright Tovape | tovape.github.io\n\n";

  // Checking Libs

  cout << libcount() << " Libraries Loaded.\n";

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

  sleep(1);

  cout << "[";
  SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
  cout << "OK";
  SetConsoleTextAttribute(hConsole, saved_attributes);
  cout << "] WinSock Started\n";

  sleep(1);

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
  cout << "(2) Settings\n";
  cout << "(3) Exit\n";

  cin >> option;

  if (option <= 0 || option > 3) {
    cout << "Invalid Choice\n";
    sleep(3);
    system("cls");
    goto menu;
  }

  if (option == 1) {
    system("cls");
    cout << "\tPort Inspection\n\n";
    system("cls");
    goto menu;
  }

  if (option == 2) {
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

  if (option == 3) {
    cout << "\tExit\n\n";
    sleep(3);
    return 0;
  }

  sleep(2);

  return 0;
}
