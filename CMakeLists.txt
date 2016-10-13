cmake_minimum_required(VERSION 2.8.9)
project(ArbolBin)

include_directories(include)

set(SOURCES src/Nodo.cpp src/main.cpp src/Arbol.cpp)

add_executable(ArbolBin ${SOURCES})
SET(saludo "Proyecto Configurado Correctamente")
MESSAGE(${saludo})