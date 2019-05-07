#include "include.h"

#ifdef UNIX

#include "Manager/LinuxManager.h"

#elif Win32

#include "Manager/WinManager.h"

#endif

int main() {
    printf("1 - Left side\n");
    printf("0 - Right side\n");
    int side;
    std::cin >> side;
#ifdef UNIX
    LinuxManager lmanager;
    lmanager.Process(side);
#elif Win32
    WinManager manager;
    manager.Process(side);
#endif
}