# CMakeList.txt : CMake project for Infinite2D-demo
cmake_minimum_required (VERSION 3.14)


if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Infinite2D-demo")


include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        5.0 # You can set this to a specific version tag or commit hash
)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # Don't build raylib examples to speed up compilation

FetchContent_MakeAvailable(raylib)


add_executable (Infinite2D-demo 
    "Infinite2D-demo.cpp" 
    "Headers/Chunk.h" 
    "Headers/LevelDesigner.h" 
    "Headers/Game.h" 
    "Headers/Behaviour.h" 
    "Headers/PlayerMovement.h" 
    "Headers/Player.h" 
    "Headers/CameraMovement.h" 
    "Headers/BoxCollider2D.h" 
    "Headers/Ray2D.h" 
    "Headers/Raycast2D.h" 
    "Headers/Physics2D.h" 
    "Headers/Collision2D.h"  
    "Headers/Point.h" 
    "Headers/BlockModification.h"
    "Headers/Screens/Screen.h"  
    "Headers/Screens/HomeScreen.h" 
    "HomeScreen.cpp" 
    "Headers/Screens/ContinueScreen.h" 
    "Headers/Screens/OptionsScreen.h" 
    "Headers/Screens/StartScreen.h" 
    "Headers/Screens/PlayScreen.h" 
    "SideToolbar.cpp" 
    "Headers/GUI/GUI.h"
    "Headers/GUI/Hotbar.h"
    "BlockModification.cpp"
    "Chunk.cpp" 
    "LevelDesigner.cpp"  
    "Game.cpp" 
    "Player.cpp" 
    "Physics2D.cpp" 
    "CameraMovement.cpp" 
    "BoxCollider2D.cpp" 
    "Ray2D.cpp" 
    "PlayerMovement.cpp"  
    "ContinueScreen.cpp" 
    "OptionsScreen.cpp" 
    "StartScreen.cpp" 
    "Hotbar.cpp"
    "PlayScreen.cpp"
    "Headers/GUI/Inventory.h" 
    "Headers/GUI/GUIHandler.h" 
    "Inventory.cpp"
 "Headers/Rectangle.h")

target_include_directories(Infinite2D-demo PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(Infinite2D-demo PRIVATE 
    SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/"
    WORLD_DIR="${CMAKE_CURRENT_SOURCE_DIR}/Worlds"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Infinite2D-demo PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(Infinite2D-demo PRIVATE raylib)