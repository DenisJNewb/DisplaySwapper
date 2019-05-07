//
// Created by denis on 07.05.19.
//

#include "WinManager.h"

WinManager::WinManager() {
    auto hConsole = GetConsoleWindow();
    ShowWindow(hConsole, SW_HIDE);

    RECT d;
    auto hD = GetDesktopWindow();
    GetWindowRect(hD, &d);

    halfWidth = d.right / 2;
    width = d.right - 4;
    halfHeight = d.bottom / 2;
    height = d.bottom - 100;
}

void WinManager::Process(bool leftSide) {
    POINT point;
    while (true) {
        GetCursorPos(&point);
        if ((leftSide ? point.x == 0 : point.x >= width) && point.y >= halfHeight &&
            point.y < height) {
            PressKey(VK_CAPITAL, 2);
            SetCaretPos(halfWidth, halfHeight);
            Sleep(10 * 1000);
        }
        Sleep(500);
    }
}

void WinManager::PressKey(WORD key, int times) {
    for (int i = 0; i < times; ++i) {

        //type 1
        INPUT input[2];
        ZeroMemory(input, sizeof(input));
        input[0].type = input[1].type = INPUT_KEYBOARD;
        input[0].ki.wVk = input[1].ki.wVk = key;
        input[1].ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, input, sizeof(INPUT));
        Sleep(50);
        SendInput(1, input + 1, sizeof(INPUT));
        Sleep(50);

        /*
        //type 2
        keybd_event(key, 0x45, KEYEVENTF_EXTENDEDKEY, 0);
        Sleep(50);
        keybd_event(key, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
        Sleep(50);
         */
    }
}
