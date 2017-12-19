cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
project(LifeIsBorne)

set(SRC_CORE src/core.cpp src/main.cpp)
set(HDR_CORE src/core.hpp)

set(SRC_MANAGER)
set(HDR_MANAGER src/Manager/InputManager/InputManager.hpp src/Manager/InputManager/AInput.hpp)

set(SRC ${SRC_CORE} ${SRC_MANAGER})
set(HDR ${HDR_CORE} ${HDR_MANAGER})


set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/module)
find_package(Boost COMPONENTS system filesystem REQUIRED)
find_package(SFML 2 REQUIRED system network audio graphics window)

include_directories(Headers ${Boost_INCLUDE_DIRS})
add_executable(${PROJECT_NAME} ${SRC} ${HDR})
link_directories(${Boost_LIBRARY_DIRS})

if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()
if (Boost_FOUND)
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()
