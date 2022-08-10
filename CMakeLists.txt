cmake_minimum_required( VERSION 3.11 )

project( converter VERSION 0.1.0 )

set( CMAKE_CXX_STANDARD 20 )

set( SOURCE_FILES 
    Src/main.cpp
    Src/Converter/Sources/converter.cpp
)

include_directories( 
    Src/Converter/Headers/
)

add_executable( ${PROJECT_NAME} ${SOURCE_FILES} )


##########
# GTests
##########

add_subdirectory(Src/Tests)
