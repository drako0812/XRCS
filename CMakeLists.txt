cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

# Project

project(xrcs VERSION 0.1.0 LANGUAGES CXX C)

# Fetch CPM

include(cmake/CPM.cmake)

# Dependencies
CPMAddPackage("gh:ArthurSonzogni/FTXUI@0.11")

# Executable

add_executable(xrcs-emu
    src/main.cpp
    src/xrcsterm.cpp
    src/instructions.cpp
    src/xrcscpu.cpp
)
target_include_directories(xrcs-emu PUBLIC include)
target_link_libraries(xrcs-emu ftxui::screen)
#target_link_libraries(xrcs-emu ftxui::screen ftxui::dom)
target_compile_features(xrcs-emu PUBLIC cxx_std_20)

if(MSVC)
    target_compile_options(xrcs-emu PRIVATE "/Fa" /FAs)
else()
    add_custom_command(TARGET xrcs-emu
                       POST_BUILD
                       COMMAND make ARGS ${SOURCE_FILENAME}.s
                       COMMAND ${CMAKE_COMMAND} -E copy
                            "${CMAKE_BINARY_DIR}/CMakeFiles/${TARGET}.dir/${SOURCE_FILENAME}.cpp.s"
                            "${OUTPUT_PATH}/${ASSEMBLY_LISTING_FILE}"
                       WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
endif()
