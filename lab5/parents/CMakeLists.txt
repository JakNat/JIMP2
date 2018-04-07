
project(rodzic)

set(HEDEAR_FILES Rodzic.h Dziecko.h)
set(SOURCE_FILES Rodzic.cpp Dziecko.cpp)

add_library(librodzic STATIC ${SOURCE_FILES})
target_include_directories(librodzic PUBLIC .)

add_executable(rodzic ${SOURCE_FILES} main.cpp)

target_link_libraries(rodzic librodzic)

