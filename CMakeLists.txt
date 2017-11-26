cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
project(LifeIsBorne)
set(SRC src/main.cpp src/Systems/SystemManger.cpp src/core.cpp src/Manager/Intro/IntroManager.cpp src/Manager/RessourceManager/RessourceManager.cpp src/Manager/RessourceManager/TextureHandler.cpp src/Manager/ConfigManager/ConfigManager.cpp src/Components/Body/GraphicalBodyPart.cpp src/Components/Body/CGraphicalBody.cpp src/Manager/RessourceManager/RessourceManagerCharacterLoader.cpp src/Manager/RessourceManager/RessourceManagerSpellLoader.cpp src/Manager/RessourceManager/RessourceManagerSceneryLoader.cpp src/Factory/Component/BodyParts/BodyPartFactory.cpp src/Entities/AComponent.cpp src/Systems/Animation/SysAnimation.cpp)
set(HDR src/core.hpp src/Components/AComponent.hpp src/Components/Stats/CHp.hpp src/Entities/AEntity.hpp src/Components/Stats/CMana.hpp src/Components/Collision/Hitbox.hpp src/Systems/SystemManager.hpp src/Systems/ASystem.hpp src/Systems/SystemLore.hpp src/GamePhases.hpp src/Manager/Intro/IntroManager.hpp src/Manager/RessourceManager/RessourceManager.hpp src/enum.h src/Manager/RessourceManager/TextureHandler.hpp Submodules/json/src/json.hpp src/Manager/ConfigManager/ConfigManager.hpp src/Components/Body/GraphicalBodyPart.hpp src/Components/Body/GraphicalBodyPart.hpp src/Components/Body/GraphicalBodyPart.hpp src/Components/Body/GraphicalBodyPart.hpp src/Components/Body/CGraphicalBody.hpp src/Components/Common/CPosition.hpp src/Utils/Position.hpp src/Utils/Size.hpp src/Components/Stats/COrientation.hpp src/Components/Stats/Orientation.hpp src/Components/Body/BodyPartType.hpp src/Factory/Component/BodyParts/BodyPartFactory.hpp src/Manager/RessourceManager/TypeLoaded.hpp src/Manager/RessourceManager/RessourceManagerException.hpp src/Systems/Animation/SysAnimation.hpp src/Components/Common/CDirection.hpp)


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
