cmake_minimum_required(VERSION 3.17)
project(Speech_contest_process)

set(CMAKE_CXX_STANDARD 14)

add_executable(Speech_contest_process "Speech contest process management system.cpp" SpeechManager.cpp SpeechManager.h Speaker.h)