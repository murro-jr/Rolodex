cmake_minimum_required (VERSION 2.8.11)
project (Rolodex)

add_subdirectory (rolodex)
include_directories (rolodex)

add_executable (rolodexproject main.cpp)
target_link_libraries (rolodexproject LINK_PUBLIC rolodex)
