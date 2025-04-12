cmake_minimum_required(VERSION 3.10)
project(ProyectoFinal)

# Habilita cobertura si está disponible
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "--coverage")

add_subdirectory(ProyectoFinal)
add_subdirectory(test)
