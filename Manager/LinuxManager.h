//
// Created by denis on 07.05.19.
//

#ifndef DISPLAYSWAPPER_LINUXMANAGER_H
#define DISPLAYSWAPPER_LINUXMANAGER_H

#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>
#include <X11/keysym.h>

#include "../include.h"

class LinuxManager {
private:
    Display *display;
    ulong rootWindow;

    //boundaries
    int width, halfWidth, height, halfHeight;

    //Mouse position fields
    Window windowReturned;
    int win_x, win_y;
    uint mask;
    int mouseX, mouseY;

public:
    LinuxManager();

    ~LinuxManager();

    void Process(bool);

private:
    void GetMousePosition();

    void MoveMouse();

    void PressCapsTwice();
};


#endif //DISPLAYSWAPPER_LINUXMANAGER_H
