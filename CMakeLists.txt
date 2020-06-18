############################
### Timitoo Systems Gmbh ###
###     Simple DLL       ###
############################

# REM how to build on Windows with VS Studio
# REM create a folder: 'buildwin64'
# REM then:
# cd buildwin64
# cmake -DCMAKE_INSTALL_PREFIX=E:\ -G  "Visual Studio 14 2015 Win64" ..
#
cmake_minimum_required (VERSION 3.9)
project (timtestprj)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/x64)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/x64)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/x64)


add_subdirectory(timlib)
add_subdirectory(timapp)
