cmake_minimum_required(VERSION 2.8)

project(CCV)

set(CCV_src main.cpp functions.cpp class_hori.cpp class_vert.cpp class.cpp operators.cpp)
set(CCV_hdr operators.h functions.h class_hori.h class_vert.h class.h AT.h factory.h factory_hori.h factory_vert.h)

add_executable(${PROJECT_NAME} ${CCV_src} ${CCV_hdr})