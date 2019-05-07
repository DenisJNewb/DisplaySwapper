//
// Created by denis on 07.05.19.
//

#ifndef DISPLAYSWAPPER_WINMANAGER_H
#define DISPLAYSWAPPER_WINMANAGER_H

#include <windows.h>

class WinManager {
private:
    int width, halfWidth, height, halfHeight;

public:
    WinManager();

    void Process(bool);

private:
    static void PressKey(WORD, int);
};


#endif //DISPLAYSWAPPER_WINMANAGER_H
