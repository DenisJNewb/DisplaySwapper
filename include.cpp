//
// Created by denis on 07.05.19.
//

#include "include.h"

#include <chrono>
#include <thread>

void PrintError(const char *msg, bool pause, bool shutdown) {
    fprintf(stdout, "%s\n", msg);
    if (pause)
        std::cin.get();
    if (shutdown)
        exit(EXIT_FAILURE);
}

void Sleep(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}