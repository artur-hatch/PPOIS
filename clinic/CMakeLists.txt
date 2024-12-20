cmake_minimum_required(VERSION 3.10)
project(Lab1)

set(CMAKE_CXX_STANDARD 14)

set(GTEST_ROOT "/home/skiliabobsik2006/googletest")
set(CMAKE_PREFIX_PATH ${GTEST_ROOT})

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")

add_executable(my_test 
    realisation/Chamber.cpp test/Chamber_test.cpp   
    realisation/Client.cpp test/Client_test.cpp
    realisation/CustomDate.cpp test/CustomDate_test.cpp
    realisation/Doctor.cpp test/Doctor_test.cpp
    realisation/Employee.cpp test/Employee_test.cpp
    realisation/DocumentSignature.cpp test/DocumentSignature_test.cpp
    realisation/FullName.cpp test/FullName_test.cpp
    realisation/IDCard.cpp test/IDCard_test.cpp
    realisation/HealthProfessional.cpp test/HealthProfessional_test.cpp
    realisation/Identity.cpp test/Identity_test.cpp
    realisation/Individual.cpp test/Individual_test.cpp
    realisation/MedicalRecord.cpp test/MedicalRecord_test.cpp
    realisation/Recipe.cpp test/Recipe_test.cpp
    test/main.cpp
)

target_link_libraries(my_test ${GTEST_LIBRARIES} pthread)

enable_testing()

add_test(NAME MyTest COMMAND my_test)