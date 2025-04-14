file(GLOB_RECURSE TESTS *.cpp)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(../ProyectoFinal)

add_executable(tests ${TESTS})
target_link_libraries(tests proyecto_lib GTest::GTest GTest::Main)

add_test(NAME AllTests COMMAND tests)
