cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (OpenGLTest)

find_package(assimp CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

set (HEADERS
  "include/OpenGLTest.h"
  "include/Shader.h"
  "include/Camera.h"
  "include/Mesh.h"
  "include/Model.h"
  "include/stb_image.h"
  "include/glad/glad.h"
  "include/KHR/khrplatform.h")

set (SOURCES
  "src/OpenGLTest.cpp"
  "src/Shader.cpp"
  "src/Camera.cpp"
  "src/Mesh.cpp"
  "src/Model.cpp"
  "src/glad.c"
  "src/stb_image.cpp"
)

include_directories ( include/ )

add_executable (OpenGLTest ${SOURCES} ${HEADERS})

add_custom_target(copy_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/res
        ${PROJECT_BINARY_DIR}/res
        COMMENT "Copying resources into binary directory")

add_dependencies(OpenGLTest copy_resources)

target_link_libraries(OpenGLTest PRIVATE assimp::assimp)
target_link_libraries(OpenGLTest PRIVATE glfw)
target_link_libraries(OpenGLTest PRIVATE glm::glm)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET OpenGLTest PROPERTY CXX_STANDARD 20)
endif()


