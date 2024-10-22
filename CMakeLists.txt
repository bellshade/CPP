cmake_minimum_required(VERSION 3.22)
project(Bellshade_cpp
    LANGUAGES CXX
    VERSION 1.0.0
    DESCRIPTION "kumpulan implementasi serta basic dari cpp"
)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    # set(CMAKE_CXX_STANDARD 14)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

option(USE_OPENMP "flag to use OpenMP for multithreading" ON)
if(USE_OPENMP)
    find_package(OpenMP 3.0 COMPONENTS CXX)
    if (OpenMP_CXX_FOUND)
        message(STATUS "Building with OpenMP Multithreading.")
    else()
        message(STATUS "No OpenMP found, no multithreading.")
    endif()
endif()

    
add_subdirectory(backtracking)
add_subdirectory(algorithm/algoritma_greedy)
add_subdirectory(algorithm/bit_manipulation)
add_subdirectory(algorithm/dynamic_programming)
add_subdirectory(algorithm/search_algorithm)
add_subdirectory(algorithm/sorting)
add_subdirectory(artificial_intelligence)
add_subdirectory(strings)
add_subdirectory(geometri)

# FIXME: ada beberapa fungsi header math terkhusus untuk
#        windows, oleh karena itu maka setting kompilasi
#        berjalan dari subdirektori `math` bekerja untuk
#        non windows
#        error tersebut ditemui pada pull request:
#        https://github.com/bellshade/CPP/pull/117
if(NOT WIN32)
add_subdirectory(math)
endif()

cmake_policy(SET CMP0054 NEW)
cmake_policy(SET CMP0057 NEW)
find_package(Doxygen OPTIONAL_COMPONENTS dot dia)
if(DOXYGEN_FOUND)
    set(DOXYGEN_GENERATE_MAN NO)
    set(DOXYGEN_USE_MATHJAX YES)
    set(DOXYGEN_GENERATE_HTML YES)
    # set(DOXYGEN_HTML_TIMESTAMP YES)
    set(DOXYGEN_EXTRACT_STATIC YES)
    set(DOXYGEN_INLINE_SOURCES YES)
    set(DOXYGEN_CREATE_SUBDIRS YES)
    set(DOXYGEN_EXTRACT_PRIVATE YES)
    set(DOXYGEN_GENERATE_TREEVIEW YES)
    set(DOXYGEN_STRIP_CODE_COMMENTS NO)
    set(DOXYGEN_EXT_LINKS_IN_WINDOW YES)
    set(DOXYGEN_BUILTIN_STL_SUPPORT YES)
    set(DOXYGEN_EXCLUDE_PATTERNS */build/*)
    set(DOXYGEN_ENABLE_PREPROCESSING YES)
    set(DOXYGEN_CLANG_ASSISTED_PARSING YES)
    set(DOXYGEN_FILE_PATTERNS *.cpp *.h *.hpp *.md)
set(DOXYGEN_MATHJAX_EXTENSIONS  TeX/AMSmath TeX/AMSsymbols)
    set(DOXYGEN_TAGFILES "doc/cppreference-doxygen-web.tag.xml=http://en.cppreference.com/w/")
    if(MSVC)
        set(DOXYGEN_CPP_CLI_SUPPORT YES)
    endif()
    set(DOXYGEN_MATHJAX_RELPATH "https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.7/MathJax.js?config=TeX-MML-AM_CHTML")
    if(Doxygen_dot_FOUND)
        set(DOXYGEN_HAVE_DOT YES)
        set(DOXYGEN_CALL_GRAPH YES)
        set(DOXYGEN_INTERACTIVE_SVG YES)
        set(DOXYGEN_DOT_IMAGE_FORMAT "svg")
    endif()
    if(OPENMP_FOUND)
        set(DOXYGEN_PREDEFINED "_OPENMP=1")
    endif()
    if(GLUT_FOUND)
        set(DOXYGEN_PREDEFINED ${DOXYGEN_PREDEFINED} "GLUT_FOUND=1")
    endif()

    doxygen_add_docs(
        doc
        ${PROJECT_SOURCE_DIR}
        COMMENT "Generate documentation"
    )
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
