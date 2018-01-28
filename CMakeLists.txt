cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-W -Wall -Wextra")
project(LifeIsBorne)

#Sources
## Main sources
set(SRC_CORE src/core.cpp src/main.cpp)
set(HDR_CORE src/core.hpp)


## Manager Sources
##InputManager Sources
set(SRC_MANAGER_INPUT src/Manager/InputManager/InputManager.cpp src/Manager/InputManager/HitMaps/AControlMapping.cpp src/Manager/InputManager/HitMaps/Controller/ControllerMapping.cpp src/Manager/InputManager/HitMaps/Keyboard/KeyboardMapping.cpp src/Manager/InputManager/InputController/Controller/Controller.cpp)
set(HDR_MANAGER_INPUT src/Manager/InputManager/InputManager.hpp src/Manager/InputManager/InputController/AInputController.hpp src/Manager/InputManager/InputControllerType.hpp src/Manager/InputManager/InputController/AInputController.cpp src/Manager/InputManager/GameInput.hpp src/Manager/InputManager/HitMaps/AControlMapping.hpp src/Manager/InputManager/HitMaps/Controller/ControllerMapping.hpp src/Manager/InputManager/HitMaps/Keyboard/KeyboardMapping.hpp src/Manager/InputManager/InputController/Controller/Controller.hpp src/Manager/InputManager/InputController/ButtonBind.hpp src/Manager/SceneManager/ScenesManager.hpp src/Manager/EventManager/EventManager.hpp)


set(SRC_MANAGER_RESSOURCE src/Manager/RessourceManager/RessourceManager.cpp)
set(HDR_MANAGER_RESSOURCE src/Manager/RessourceManager/RessourceManager.hpp)


set(SRC_MANAGER ${SRC_MANAGER_INPUT} ${SRC_MANAGER_RESSOURCE})
set(HDR_MANAGER ${HDR_MANAGER_INPUT} ${HDR_MANAGER_RESSOURCE} src/Manager/EventManager/EventManager.hpp)


## Set all Sources to SRC & HDR variable
set(SRC ${SRC_CORE} ${SRC_MANAGER} src/Manager/EventManager/Events/AEvent.cpp src/Manager/SceneManager/ScenesManager.cpp src/Scenes/Intro/IntroScene.cpp)
set(HDR ${HDR_CORE} ${HDR_MANAGER} src/Manager/EventManager/Events/AEvent.hpp src/Manager/EventManager/Receiver.hpp src/utils/Singleton.hpp src/Manager/EventManager/Events/Events.hpp src/Scenes/SceneList.hpp src/Manager/SceneManager/AScene.hpp src/Scenes/Intro/IntroScene.hpp src/Scenes/Intro/TextureId.hpp)


## Setup cmake Moule paths
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/module)

## Search for lib
find_package(Boost COMPONENTS system filesystem REQUIRED)
find_package(SFML 2 REQUIRED system network audio graphics window)


##
add_executable(${PROJECT_NAME} ${SRC} ${HDR})


##
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()


if (Boost_FOUND)
    include_directories(Headers ${Boost_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
    link_directories(${Boost_LIBRARY_DIRS})
endif()
