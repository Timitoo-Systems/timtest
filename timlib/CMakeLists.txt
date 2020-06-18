############################
### Timitoo Systems Gmbh ###
###     Simple DLL       ###
############################


set(TIM_TEST "timtest")
  
add_library(${TIM_TEST} SHARED "")


target_include_directories( ${TIM_TEST}
 PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}
   ${CMAKE_SOURCE_DIR}/header
)

target_sources(${TIM_TEST}
PRIVATE
   timtest.cpp
   ../header/timtest.h
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

add_custom_command(
   TARGET ${TIM_TEST}
   COMMAND ${CMAKE_COMMAND} -E md5sum "$<TARGET_FILE:${TIM_TEST}>" > ${TIM_TEST}_$<CONFIG>.md5
)
