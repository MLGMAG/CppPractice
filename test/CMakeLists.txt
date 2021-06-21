set(SOURCE_PATH ${PROJECT_SOURCE_DIR}/src)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_subdirectory(basicSum)
add_subdirectory(minString)
add_subdirectory(equation)
