cmake_minimum_required(VERSION 3.24)
project(Supermercado C)

set(CMAKE_C_STANDARD 11)

add_executable(Supermercado main.c mercado.h mercado.c)
