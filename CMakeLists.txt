cmake_minimum_required(VERSION 2.6)
project(double_pendulum)

find_package(SFML 2 COMPONENTS graphics window system)
add_executable(double_pendulum main.cpp) 
target_link_libraries(double_pendulum sfml-graphics sfml-audio sfml-window sfml-system)


