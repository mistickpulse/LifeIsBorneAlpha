cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)
project(LifeIsBorne)
set(SRC src/main.cpp src/Systems/SystemManger.cpp src/core.cpp src/Manager/IntroManager.cpp src/Manager/RessourceManager/RessourceManager.cpp src/Manager/RessourceManager/TextureHandler.cpp)
set(HDR src/core.hpp src/Components/AComponent.hpp src/Components/Stats/Hp.hpp src/Entities/AEntity.hpp src/Components/Stats/Mana.hpp src/Components/Graphical/Animation.hpp src/Components/Collision/Hitbox.hpp src/Systems/SystemManager.hpp src/Systems/ASystem.hpp src/Systems/SystemLore.hpp src/GamePhases.hpp src/Manager/IntroManager.hpp src/Manager/RessourceManager/RessourceManager.hpp src/enum.h src/Manager/RessourceManager/TextureHandler.hpp Submodules/json/src/json.hpp src/Manager/ConfigManager/ConfigManager.hpp)


set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/module)
find_package(Boost COMPONENTS regex system filesystem REQUIRED)
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
