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
set(SRC_MANAGER_INPUT src/Manager/InputManager/InputManager.cpp src/Manager/InputManager/Context/InputContext.cpp src/Manager/InputManager/Context/InputContextManager.cpp)
set(HDR_MANAGER_INPUT src/Manager/InputManager/InputManager.hpp src/Manager/InputManager/RawInputConstant.hpp src/Manager/InputManager/InputConstant.hpp src/Manager/InputManager/Context/InputContextManager.hpp src/Manager/InputManager/Context/ContextList.hpp src/Manager/InputManager/RangeConverter.hpp src/Manager/InputManager/Context/InputContext.hpp src/Manager/InputManager/BindingContextHelper.hpp src/Manager/InputManager/InputMapper.hpp src/Manager/InputManager/MappedInput.hpp)

set(SRC_SCENE src/Scenes/Intro/IntroScene.cpp src/Scenes/SalleArcade/ArcadeScene.cpp src/Manager/SceneManager/ScenesManager.cpp)
set(HDR_SCENE src/Manager/SceneManager/ScenesManager.hpp src/Scenes/SalleArcade/ArcadeScene.hpp src/Scenes/SalleArcade/TextureId.hpp)


### Entity Manager
set(SRC_MANAGER_ETT)
set(HDR_MANAGER_ETT src/Manager/EntityManager/AEntity.hpp)

### Event Manager
set(HDR_EVENT_LIST src/Manager/EventManager/Events/SceneEvents.hpp src/Manager/EventManager/Events/InputEvents.hpp src/Manager/EventManager/Events/MainEvent.hpp src/Manager/EventManager/Events/EventList.hpp src/Manager/EventManager/Events/ParamEvent.hpp)

set(SRC_MANAGER_EVENT src/Manager/EventManager/Events/AEvent.cpp)

set(HDR_MANAGER_EVENT src/Manager/EventManager/EventManager.hpp src/Manager/EventManager/Events/AEvent.hpp ${HDR_EVENT_LIST})

### Ressource Manager


set(SRC_MANAGER_RESSOURCE src/Manager/RessourceManager/RessourceManager.cpp)
set(HDR_MANAGER_RESSOURCE src/Manager/RessourceManager/RessourceManager.hpp)

set(SRC_MANAGER ${SRC_MANAGER_INPUT} ${SRC_MANAGER_RESSOURCE} ${SRC_SCENE} ${SRC_MANAGER_EVENT} ${SRC_MANAGER_ETT})
set(HDR_MANAGER ${HDR_MANAGER_INPUT} ${HDR_MANAGER_RESSOURCE} ${HDR_SCENE} ${HDR_MANAGER_EVENT} ${HDR_MANAGER_ETT})

## Set all Sources to SRC & HDR variable

set(SRC ${SRC_CORE} ${SRC_MANAGER})
set(HDR ${HDR_CORE} ${HDR_MANAGER} src/utils/Singleton.hpp src/Scenes/SceneList.hpp src/Manager/SceneManager/AScene.hpp src/Scenes/Intro/IntroScene.hpp src/Scenes/Intro/TextureId.hpp src/Scenes/ForwardScene.hpp src/utils/Position.hpp src/utils/Interval.hpp src/GlobalConf.hpp src/GameAction.hpp src/GameState.hpp src/GlobalConf.cpp)


## Setup cmake Moule paths
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/module)

## Search for lib
set(Thor_LIBRARIES /usr/local/lib/libthor.so)
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
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${Thor_LIBRARIES})
    link_directories(${Boost_LIBRARY_DIRS})
endif()
