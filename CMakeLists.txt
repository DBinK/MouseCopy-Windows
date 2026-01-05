cmake_minimum_required(VERSION 3.20)
project(MouseCopy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(MouseCopy
    src/mousecopy.cpp
    src/tray.cpp
)

target_link_libraries(MouseCopy user32 shell32 advapi32)