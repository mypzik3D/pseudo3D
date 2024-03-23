cmake_minimum_required(VERSION 3.27)
project(pseudo3D_by_mypzik3D LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(pseudo3D_by_mypzik3D main.cpp
        draw.h
        raycasting.h
        data.h
        sfml_draw.h
)
target_link_libraries(pseudo3D_by_mypzik3D PRIVATE sfml-graphics)
target_compile_features(pseudo3D_by_mypzik3D PRIVATE cxx_std_20)

if(WIN32)
    add_custom_command(
            TARGET pseudo3D_by_mypzik3D
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:pseudo3D_by_mypzik3D>
            VERBATIM)
endif()

