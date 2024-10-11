include(GoogleTest)
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "*.h" "*.cpp")
add_executable(khaki-test ${SOURCE_FILES})
set_target_properties(khaki-test  PROPERTIES LINKER_LANGUAGE CXX)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.13.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_link_libraries(khaki-test khaki gtest)
gtest_discover_tests(khaki-test)
