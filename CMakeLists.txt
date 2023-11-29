cmake_minimum_required(VERSION 2.84)
set(CMAKE_CXX_STANDARD 11)
project(progetto_intermedio)

include_directories(include)

add_library(${PROJECT_NAME} SHARED
			src/Date.cpp
			src/Book.cpp
			src/BookShelf.cpp)

add_executable(main src/main.cpp)

target_link_libraries(main ${PROJECT_NAME})

install(TARGETS main DESTINATION $ENV{HOME}/Local/bin)
