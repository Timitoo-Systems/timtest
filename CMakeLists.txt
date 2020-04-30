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

set(TIM_TEST "timtest")
  
add_library(${TIM_TEST} SHARED "")


target_include_directories( ${TIM_TEST}
 PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(${TIM_TEST} 
PRIVATE
   timlib/timtest.cpp
   timtest.h
)

##
## compile definitions
##
target_compile_definitions(${TIM_TEST}
 PRIVATE 
  TIM_TEST_LIB
  "$<$<PLATFORM_ID:Windows>:_SBCS>"
  "$<$<PLATFORM_ID:Windows>:WIN32>"
  "$<$<PLATFORM_ID:Windows>:WIN64>"
)

##
## Position independent code in Linux
##
target_compile_options( ${TIM_TEST}
  PRIVATE 
  "$<$<PLATFORM_ID:Linux>:-fPIC>"
  "$<$<PLATFORM_ID:Linux>:-std=c++11>"
  "$<$<PLATFORM_ID:Windows>:/W3>"
)

target_link_libraries(${TIM_TEST}
 PRIVATE
)


##
## TIMAPP
##
set(TIM_APP "timapp")
  
add_executable(${TIM_APP} "")

target_include_directories( ${TIM_APP}
 PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(${TIM_APP} 
PRIVATE
   timapp/timapp.cpp
   timtest.h
)

##
## compile definitions
##
target_compile_definitions(${TIM_TEST}
 PRIVATE 
  "$<$<PLATFORM_ID:Windows>:_SBCS>"
  "$<$<PLATFORM_ID:Windows>:WIN32>"
  "$<$<PLATFORM_ID:Windows>:WIN64>"
)

##
## Position independent code in Linux
##
target_compile_options( ${TIM_TEST}
  PRIVATE 
  "$<$<PLATFORM_ID:Linux>:-fPIC>"
  "$<$<PLATFORM_ID:Linux>:-std=c++11>"
  "$<$<PLATFORM_ID:Windows>:/W3>"
)

target_link_libraries(${TIM_APP}
 PRIVATE
 ${TIM_TEST}
)
