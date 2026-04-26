cmake_minimum_required(VERSION 4.2)
project(NewStomachLangauge)

set(CMAKE_CXX_STANDARD 20)

add_executable(NewStomachLangauge main.cpp
        StomachLang.h
        CPU.h
        Memory.h
        Memory.cpp
        CPU.cpp
        StomachLang.cpp
        Variable.h
        Variable.cpp
        Calorie.h
        Calorie.cpp
        Foods.h
        Foods.cpp
        Edible.h
        Edible.cpp)
