file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "*.h" "*.cpp")
add_library(khaki ${SOURCE_FILES})
set_target_properties(khaki PROPERTIES LINKER_LANGUAGE CXX)
target_compile_features(khaki PUBLIC cxx_std_20)

set_target_properties(khaki PROPERTIES POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS})
target_include_directories(khaki INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
target_link_libraries(khaki PUBLIC Fastor)

if(MSVC)
        target_compile_options(khaki PRIVATE /W4)
else()
        target_compile_options(khaki PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
