# Vector Part
add_executable(vectorPart vectorPart/vectorPart.h vectorPart/vectorPart.cpp vectorPart/vectorPartTests.cpp)
target_link_libraries(vectorPart PRIVATE testFrameworkLib)
