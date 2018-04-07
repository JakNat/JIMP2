
project(marsjanin)

set(HEDEAR_FILES Marsjanin.h)
set(SOURCE_FILES Marsjanin.cpp)

add_library(libmarsjanin STATIC ${SOURCE_FILES})
target_include_directories(libmarsjanin PUBLIC .)

add_executable(marsjanin ${SOURCE_FILES} main.cpp)

target_link_libraries(marsjanin libmarsjanin)

