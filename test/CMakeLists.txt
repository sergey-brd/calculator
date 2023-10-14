include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

FILE(GLOB TEST_SOURCES *.cpp)
add_executable(unit_tests ${TEST_SOURCES})

target_link_libraries(unit_tests GTest::gtest_main parser)

include(GoogleTest)
gtest_add_tests(TARGET unit_tests)
