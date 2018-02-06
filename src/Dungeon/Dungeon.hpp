//
// Created by zouz on 05/02/18.
//

#ifndef LIFEISBORNE_DUNGEON_HPP
#define LIFEISBORNE_DUNGEON_HPP

#include <ctime>
#include <functional>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include "GenerationProfile.hpp"
#include "../utils/Singleton.hpp"
#include "RoomGenerationMode.hpp"
#include "../utils/Position.hpp"
#include "Cell.hpp"

namespace gen
{

    class Cell;

    class Dungeon : public Singleton<Dungeon>
    {
    public:
        Dungeon();

        ~Dungeon() final = default;

    public:

        void create(const GenerationProfile &profile, int Iteration);

        friend void operator<<(sf::RenderWindow &win, const Dungeon &d);

        std::unordered_map<RoomGenerationMode, GenBehavior> _RoomBehavior =
            {{
                 {RoomGenerationMode::Normal, [](const Room &roomA, const Room &roomB, const GenerationProfile &profile,
                                                 bool odd) {
                     if (odd) {
                         if (roomA.SizeX <= profile.MinimumSizeRoomX || roomB.SizeX <= profile.MinimumSizeRoomX)
                             return false;
                     } else {
                         if (roomA.SizeY <= profile.MinimumSizeRoomY || roomB.SizeY <= profile.MinimumSizeRoomY)
                             return false;
                     }
                     return true;
                 }},

                 {RoomGenerationMode::Heterogenous, [](const Room &roomA, const Room &roomB,
                                                       const GenerationProfile &profile, bool odd) {
                     return true;
                 }},

                 {RoomGenerationMode::Homogenous, [](const Room &roomA, const Room &roomB,
                                                     const GenerationProfile &profile, bool odd) {
                     return true;
                 }},
             }};

    private:
        std::shared_ptr<GenerationProfile> _profile;
        std::shared_ptr<Cell> _dungeon;
    };

    void operator<<(sf::RenderWindow &win, const gen::Dungeon &d);
}

#endif //LIFEISBORNE_DUNGEON_HPP
