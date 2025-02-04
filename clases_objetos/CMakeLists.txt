cmake_minimum_required(VERSION 3.10)
project(EjercicioClasesObjetos)
set(CMAKE_CXX_STANDARD 11)

if(MSVC)
    set(CMAKE_CXX_FLAGS "/O2")
else()
    set(CMAKE_CXX_FLAGS "-Wall -Werror -O2")
endif()

add_executable(ejercicio main.cpp estudiante.cpp estudiante.hpp)
