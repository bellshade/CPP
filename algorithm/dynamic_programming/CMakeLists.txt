file( GLOB APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp )

# FIXME: informasi error:
#        failure was caused by a read of a variable outside its lifetime
#        error C2131: expression did not evaluate to a constant
#
#        error ditemukan pada:
#        https://github.com/bellshade/CPP/pull/117
list(REMOVE_ITEM APP_SOURCES "kadane.cpp")

foreach( testsourcefile ${APP_SOURCES} )
    string( REPLACE ".cpp" "" testname ${testsourcefile} )
    add_executable( ${testname} ${testsourcefile} )

    set_target_properties(${testname} PROPERTIES LINKER_LANGUAGE CXX)
    if(OpenMP_CXX_FOUND)
        target_link_libraries(${testname} OpenMP::OpenMP_CXX)
    endif()
    install(TARGETS ${testname} DESTINATION "bin/backtracking")

endforeach( testsourcefile ${APP_SOURCES} )
