#include <iostream>
#include <Windows.h>
#include <stdio.h>

using namespace std;

int libcheck() {

  // Color Win32 API

  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  WORD saved_attributes;
  GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  saved_attributes = consoleInfo.wAttributes;

  // Checking Libraries (Couldn't pull off a looping method)

  int librariesSize = 0;
  int librariesOn = 0;
  int librariesOff = 0;

  #if __has_include("iostream")
    #include "iostream"
    cout << "["; SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); cout << "Ok"; SetConsoleTextAttribute(hConsole, saved_attributes); cout << "] " << "iostream" << "\n";
    librariesOn++;
  #else
    cout << "["; SetConsoleTextAttribute(hConsole, FOREGROUND_RED); cout << "Error"; SetConsoleTextAttribute(hConsole, saved_attributes); cout << "] " << "iostream" << "\n";
    librariesOff++;
  #endif

  #if __has_include("unistd.h")
    #include "unistd.h"
    cout << "["; SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); cout << "Ok"; SetConsoleTextAttribute(hConsole, saved_attributes); cout << "] " << "unistd.h" << "\n";
    librariesOn++;
  #else
    cout << "["; SetConsoleTextAttribute(hConsole, FOREGROUND_RED); cout << "Error"; SetConsoleTextAttribute(hConsole, saved_attributes); cout << "] " << "unistd.h" << "\n";
    librariesOff++;
  #endif

  #if __has_include("stdlib.h")
    #include "stdlib.h"
    cout << "["; SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); cout << "Ok"; SetConsoleTextAttribute(hConsole, saved_attributes); cout << "] " << "stdlib.h" << "\n";
    librariesOn++;
  #else
    cout << "["; SetConsoleTextAttribute(hConsole, FOREGROUND_RED); cout << "Error"; SetConsoleTextAttribute(hConsole, saved_attributes); cout << "] " << "stdlib.h" << "\n";
    librariesOff++;
  #endif

  #if __has_include("Windows.h")
    #include "Windows.h"
    cout << "["; SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); cout << "Ok"; SetConsoleTextAttribute(hConsole, saved_attributes); cout << "] " << "Windows.h" << "\n";
    librariesOn++;
  #else
    cout << "["; SetConsoleTextAttribute(hConsole, FOREGROUND_RED); cout << "Error"; SetConsoleTextAttribute(hConsole, saved_attributes); cout << "] " << "Windows.h" << "\n";
    librariesOff++;
  #endif

  #if __has_include("winsock2.h")
    #include "winsock2.h"
    cout << "["; SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); cout << "Ok"; SetConsoleTextAttribute(hConsole, saved_attributes); cout << "] " << "winsock2.h" << "\n";
    librariesOn++;
  #else
    cout << "["; SetConsoleTextAttribute(hConsole, FOREGROUND_RED); cout << "Error"; SetConsoleTextAttribute(hConsole, saved_attributes); cout << "] " << "winsock2.h" << "\n";
    librariesOff++;
  #endif

  #if __has_include("ws2tcpip.h")
    #include "ws2tcpip.h"
    cout << "["; SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); cout << "Ok"; SetConsoleTextAttribute(hConsole, saved_attributes); cout << "] " << "ws2tcpip.h" << "\n";
    librariesOn++;
  #else
    cout << "["; SetConsoleTextAttribute(hConsole, FOREGROUND_RED); cout << "Error"; SetConsoleTextAttribute(hConsole, saved_attributes); cout << "] " << "ws2tcpip.h" << "\n";
    librariesOff++;
  #endif

  #if __has_include("dlfcn.h")
    #include "dlfcn.h"
    cout << "["; SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); cout << "Ok"; SetConsoleTextAttribute(hConsole, saved_attributes); cout << "] " << "dlfcn.h" << "\n";
    librariesOn++;
  #else
    cout << "["; SetConsoleTextAttribute(hConsole, FOREGROUND_RED); cout << "Error"; SetConsoleTextAttribute(hConsole, saved_attributes); cout << "] " << "dlfcn.h" << "\n";
    librariesOff++;
  #endif

  cout << "\nOperative: ";
  cout << librariesOn;
  cout << " | Inoperative: ";
  cout << librariesOff;
  cout << "\n";

  librariesSize = librariesOn + librariesOff;

  return librariesSize;
}
