#include <iostream>
#include <Windows.h>

using namespace std;

int libcount() {

  //Color Win32 API

  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  WORD saved_attributes;
  GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  saved_attributes = consoleInfo.wAttributes;

  const char *libraries[7] = { "iostream", "unistd.h", "stdlib.h", "Windows.h", "winsock2.h", "ws2tcpip.h", "dlfcn.h" };
  int librariesSize = sizeof(libraries)/sizeof(libraries[0]);
  int librariesOn = 0, librariesOff = 0;

  #if __has_include("unistd.h")
      #include "unistd.h"
      cout << "ok";
  #else
    cout << "bruh";
  #endif

  for (int i = 0; i < librariesSize; i++) {
    #if __has_include(<\"libraries[i]"\>)
        #include '<' << libraries[i] << '>
        cout << "[";
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        cout << "Ok";
        SetConsoleTextAttribute(hConsole, saved_attributes);
        cout << "] " << libraries[i] << "\n";
    #else
      cout << "[";
      SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
      cout << "Error";
      SetConsoleTextAttribute(hConsole, saved_attributes);
      cout << "] " << libraries[i] << "\n";
    #endif
  }

  return librariesSize;
}
