cmake_minimum_required(VERSION 3.16)
project(passes)

set(CMAKE_CXX_STANDARD 11)

add_executable(passes src/main.cpp src/StaticLib/TreeSerializer.cpp src/StaticLib/TreeSerializer.hpp src/CommandLine.cpp src/CommandLine.hpp src/Command/Command.cpp src/Command/Command.hpp src/Command/ShowUsernames.cpp src/Command/ShowUsernames.hpp src/Command/AddAccount.cpp src/Command/AddAccount.hpp src/Command/GetPassword.cpp src/Command/GetPassword.hpp src/Command/Removal.cpp src/Command/Removal.hpp src/StaticLib/StringHandler.cpp src/StaticLib/StringHandler.hpp)
