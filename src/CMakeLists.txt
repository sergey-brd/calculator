add_executable(calculator main.cpp)

FILE(GLOB SOURCES *.cpp)
list(REMOVE_ITEM SOURCES main.cpp)
add_library(parser ${SOURCES})
target_link_libraries(calculator parser)
