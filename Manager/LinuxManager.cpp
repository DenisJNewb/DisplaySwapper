//
// Created by denis on 07.05.19.
//

#include "LinuxManager.h"

LinuxManager::LinuxManager() {
    display = XOpenDisplay(nullptr);
    if (!display)
        PrintError("Cannot get display");
    rootWindow = XDefaultRootWindow(display);
    if (rootWindow == 0)
        PrintError("Cannot get window");
    Screen *pScreen = ScreenOfDisplay(display, 0);
    if (pScreen == nullptr)
        PrintError("Cannot get pScreen");

    width = pScreen->width - 4;
    halfWidth = pScreen->width / 2;
    height = pScreen->height - 100;
    halfHeight = pScreen->height / 2;
}

LinuxManager::~LinuxManager() {
    XCloseDisplay(display);
}

void LinuxManager::Process(bool leftSide) {
    while (true) {
        GetMousePosition();
        if ((leftSide ? mouseX == 0 : mouseX >= width) && mouseY >= halfHeight &&
            mouseY < height) {
            PressCapsTwice();
            MoveMouse();
            Sleep(10 * 1000);
        }
        Sleep(500);
    }
}

void LinuxManager::GetMousePosition() {
    XQueryPointer(display, rootWindow, &windowReturned, &windowReturned, &mouseX,
                  &mouseY, &win_x, &win_y,
                  &mask);
}

void LinuxManager::MoveMouse() {
    XWarpPointer(display, None, rootWindow, 0, 0, 0, 0, halfWidth, halfHeight);
    XFlush(display);
}

void LinuxManager::PressCapsTwice() {
    auto keycode = XKeysymToKeycode(display, XK_Caps_Lock);
    for (int count = 2; count > 0; --count) {
        XTestFakeKeyEvent(display, keycode, True, CurrentTime);
        Sleep(50);
        XFlush(display);
        XTestFakeKeyEvent(display, keycode, False, CurrentTime);
        Sleep(50);
        XFlush(display);
    }
}
