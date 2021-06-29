# CMakeList.txt : CMake project for makeCalendar, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("makeCalendar")

# Add source to this project's executable.
add_executable (makeCalendar "makeCalendar.cpp" "makeCalendar.h" "defineFun.h")

# TODO: Add tests and install targets if needed.
