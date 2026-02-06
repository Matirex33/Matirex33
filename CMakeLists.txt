cmake_minimum_required(VERSION 4.0)
project(Matirex33)

set(CMAKE_CXX_STANDARD 14)

include_directories("Mis projectos")

add_executable(Matirex33
        "Mis projectos/main.cpp"
        "Mis projectos/funciones.cpp"
        "Mis projectos/funciones.h")
