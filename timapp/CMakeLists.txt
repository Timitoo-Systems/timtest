############################
### Timitoo Systems Gmbh ###
###     Simple APP       ###
############################


##
## TIMAPP
##
set(TIM_APP "timapp")

message(STATUS "thebest " ${CMAKE_SOURCE_DIR}/header)

add_executable(${TIM_APP} "")

target_include_directories( ${TIM_APP}
 PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}
   ${CMAKE_SOURCE_DIR}/header
)

target_sources(${TIM_APP}
PRIVATE
   timapp.cpp
   ../header/timtest.h
)

##
## compile definitions
##
target_compile_definitions(${TIM_APP}
 PRIVATE 
 TIM_APP
  "$<$<PLATFORM_ID:Windows>:_SBCS>"
  "$<$<PLATFORM_ID:Windows>:WIN32>"
  "$<$<PLATFORM_ID:Windows>:WIN64>"
)

##
## Position independent code in Linux
##
target_compile_options( ${TIM_APP}
  PRIVATE 
  "$<$<PLATFORM_ID:Linux>:-fPIC>"
  "$<$<PLATFORM_ID:Linux>:-std=c++11>"
  "$<$<PLATFORM_ID:Windows>:/W3>"
)

target_link_libraries(${TIM_APP}
 PRIVATE
 timtest
)

