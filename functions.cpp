#include <iostream>
#include <Windows.h>
#include <stdio.h>

#define RAMDIV 1024 // Define Bytes to KB
#define RAMWIDTH 8 // Define Field Width

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

void ramUsage() {

  MEMORYSTATUSEX statex;
  statex.dwLength = sizeof (statex);
  GlobalMemoryStatusEx (&statex);

  _tprintf (TEXT("%*ld %% In Use\n"),
  RAMWIDTH, statex.dwMemoryLoad);

  _tprintf (TEXT("%*I64d KB | %*I64d MB | %*I64d GB of Total Physical Memory\n"),
  RAMWIDTH, statex.ullTotalPhys/RAMDIV,
  RAMWIDTH, statex.ullTotalPhys/RAMDIV/RAMDIV,
  4, statex.ullTotalPhys/RAMDIV/RAMDIV/RAMDIV);

  _tprintf (TEXT("%*I64d KB | %*I64d MB | %*I64d GB of Free Physical Memory\n"),
  RAMWIDTH, statex.ullAvailPhys/RAMDIV,
  RAMWIDTH, statex.ullAvailPhys/RAMDIV/RAMDIV,
  4, statex.ullAvailPhys/RAMDIV/RAMDIV/RAMDIV);

  _tprintf (TEXT("%*I64d KB | %*I64d MB | %*I64d GB of Occupied Physical Memory\n"),
  RAMWIDTH, statex.ullTotalPhys/RAMDIV - statex.ullAvailPhys/RAMDIV,
  RAMWIDTH, statex.ullTotalPhys/RAMDIV/RAMDIV - statex.ullAvailPhys/RAMDIV/RAMDIV,
  4, statex.ullTotalPhys/RAMDIV/RAMDIV/RAMDIV - statex.ullAvailPhys/RAMDIV/RAMDIV/RAMDIV);

  cout << "\n";

  _tprintf (TEXT("%*I64d Total KB of Paging File\n"),
  RAMWIDTH, statex.ullTotalPageFile/RAMDIV);

  _tprintf (TEXT("%*I64d Free KB of Paging File\n"),
  RAMWIDTH, statex.ullAvailPageFile/RAMDIV);

  _tprintf (TEXT("%*I64d Total KB of Virtual Memory\n"),
  RAMWIDTH, statex.ullTotalVirtual/RAMDIV);

  _tprintf (TEXT("%*I64d Free KB of Virtual Memory\n"),
  RAMWIDTH, statex.ullAvailVirtual/RAMDIV);

  _tprintf (TEXT("%*I64d Free KB of Extended Memory\n"),
  RAMWIDTH, statex.ullAvailExtendedVirtual/RAMDIV);
}

void cpuUsage() {
}

void pcStats() {

  SYSTEM_INFO siSysInfo;

  // Copy the hardware information to the SYSTEM_INFO structure.

  GetSystemInfo(&siSysInfo);

  // Display the contents of the SYSTEM_INFO structure.

  cout << "Hardware information: \n";
  cout << "OEM ID: " << siSysInfo.dwOemId << "\n";
  cout << "Number of processors: " << siSysInfo.dwNumberOfProcessors << "\n";
  cout << "Page size: " << siSysInfo.dwPageSize << "\n";
  cout << "Processor type: " << siSysInfo.dwProcessorType << "\n";
  cout << "Minimum application address: " << siSysInfo.lpMinimumApplicationAddress << "\n";
  cout << "Maximum application address: " << siSysInfo.lpMaximumApplicationAddress << "\n";
  cout << "Active processor mask: " << siSysInfo.dwActiveProcessorMask << "\n";
}
