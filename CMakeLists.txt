# CMakeList.txt : CMake project for Infinite2D-demo, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.10)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Infinite2D-demo")

# Add source to this project's executable.
add_executable (Infinite2D-demo 
"Infinite2D-demo.cpp" 
"Headers/Chunk.h" 
"Headers/LevelDesigner.h" 
"Headers/Game.h" 
"Headers/Behaviour.h" 
"Headers/PlayerMovement.h" 
"Headers/Player.h" 
"CameraMovement.cpp" 
"Headers/CameraMovement.h" 
 
"Headers/Physics2D.h" 
 
"Chunk.cpp" 
"LevelDesigner.cpp"  
"Game.cpp" 
"Player.cpp" "Headers/Point.h")

target_include_directories(Infinite2D-demo PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    "${CMAKE_CURRENT_SOURCE_DIR}/raylib/include" 
)
target_link_directories(Infinite2D-demo PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/raylib/lib"
)

target_compile_definitions(Infinite2D-demo PRIVATE 
    SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Infinite2D-demo PROPERTY CXX_STANDARD 20)
endif()

if (MSVC)

    target_link_libraries(Infinite2D-demo PRIVATE raylib winmm gdi32 user32 shell32)
else()

    target_link_libraries(Infinite2D-demo PRIVATE raylib)
endif()

# TODO: Add tests and install targets if needed.
