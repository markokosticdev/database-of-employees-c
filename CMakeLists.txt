cmake_minimum_required(VERSION 3.5)


#########################################################
# PROJECT BUILD
#########################################################
project(database_of_employees_c)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/res DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/)


#########################################################
# Include Files
#########################################################
set(SOURCE_FILES src/main.c src/module/input.c src/module/input.h src/module/process.c src/module/process.h src/module/output.c src/module/output.h src/module/functions.c src/module/functions.h src/module/employee.h)
add_executable(database_of_employees_c ${SOURCE_FILES})




