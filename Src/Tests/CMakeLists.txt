cmake_minimum_required( VERSION 3.11 )

set( TEST_SOURCE_FILES
    gTestsMain.cpp
    Sources/converterTests.cpp

    ../Converter/Sources/converter.cpp
    ../Converter/Headers/converter.hpp
)

add_executable(converterTests ${TEST_SOURCE_FILES})

target_link_libraries(converterTests gtest gmock pthread)
