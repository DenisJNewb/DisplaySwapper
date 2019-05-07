cmake_minimum_required(VERSION 3.13)
project(DisplaySwapper)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall)

if (${CMAKE_SYSTEM_NAME} MATCHES Linux)

    add_compile_definitions(UNIX)
    set(INC
            Manager/LinuxManager.h
            Manager/LinuxManager.cpp)
    set(LNK
            X11
            Xtst)

elseif (${CMAKE_SYSTEM_NAME} MATCHES Windows)

    add_compile_definitions(Win32)
    add_link_options(-static)
    set(INC
            Manager/WinManager.h
            Manager/WinManager.cpp)
    set(LNK
            pthread)

endif ()

add_executable(${PROJECT_NAME} main.cpp include.h include.cpp ${INC})
target_link_libraries(${PROJECT_NAME} ${LNK})