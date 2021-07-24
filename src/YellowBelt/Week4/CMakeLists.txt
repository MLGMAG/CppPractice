# Vector Part
add_executable(vectorPart vectorPart/vectorPart.h vectorPart/vectorPart.cpp vectorPart/vectorPartTests.cpp)
target_link_libraries(vectorPart PRIVATE testFrameworkLib)

# Greater Element
add_executable(greaterElement greaterElement/greaterElement.h greaterElement/greaterElement.cpp greaterElement/greaterElementTests.cpp)
target_link_libraries(greaterElement PRIVATE testFrameworkLib)

# Split String
add_executable(splitString splitString/splitString.h splitString/splitString.cpp splitString/splitStringTests.cpp)
target_link_libraries(splitString PRIVATE testFrameworkLib)

# Remove Duplicates
add_executable(removeDuplicates removeDuplicates/removeDuplicates.h removeDuplicates/removeDuplicatesTest.cpp)
target_link_libraries(removeDuplicates PRIVATE testFrameworkLib)

# Rearrangement
add_executable(rearrangement rearrangement/rearrangementCoursera.cpp)

# Person Details
add_executable(personDetails personDetails/personDetails.cpp)

# Group Strings
add_executable(groupBySymbol groupStrings/groupBySymbol.cpp)
add_executable(groupByString groupStrings/groupByString.cpp)

# Arithmetic
add_executable(arithmeticAmbiguous arithmetic/arithmeticAmbiguous.cpp)
add_executable(arithmeticNormal arithmetic/arithmeticNormal.cpp)
