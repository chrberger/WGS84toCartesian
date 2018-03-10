#MIT License
#
# Copyright (c) 2018  Christian Berger
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

cmake_minimum_required(VERSION 3.2)

project(wgs84tocartesian)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
if(NOT WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
        -D_XOPEN_SOURCE=700 \
        -D_FORTIFY_SOURCE=2 \
        -O2 \
        -fstack-protector \
        -fomit-frame-pointer \
        -pipe \
        -pedantic -pedantic-errors \
        -Werror \
        -Weffc++ \
        -Wall -Wextra -Wshadow -Wdeprecated \
        -Wdiv-by-zero -Wfloat-equal -Wsign-compare -Wpointer-arith \
        -Wuninitialized -Wunreachable-code \
        -Wunused -Wunused-function -Wunused-label -Wunused-parameter -Wunused-but-set-parameter -Wunused-but-set-variable \
        -Wunused-value -Wunused-variable -Wunused-result \
        -Wmissing-field-initializers -Wmissing-format-attribute -Wmissing-include-dirs -Wmissing-noreturn")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

enable_testing()
add_executable(${PROJECT_NAME}-Runner ${CMAKE_CURRENT_SOURCE_DIR}/test/Test-WGS84toCartesian.cpp)
target_link_libraries(${PROJECT_NAME}-Runner)
add_test(NAME ${PROJECT_NAME}-Runner COMMAND ${PROJECT_NAME}-Runner)

