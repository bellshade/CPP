cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)
file( GLOB APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp )
foreach( testsourcefile ${APP_SOURCES} )
    string( REPLACE ".cpp" "" testname ${testsourcefile} )
    add_executable( ${testname} ${testsourcefile} )

    set_target_properties(${testname} PROPERTIES LINKER_LANGUAGE CXX)
    if(OpenMP_CXX_FOUND)
        target_link_libraries(${testname} OpenMP::OpenMP_CXX)
    endif()
    install(TARGETS ${testname} DESTINATION "bin/geometri")

endforeach( testsourcefile ${APP_SOURCES} )
