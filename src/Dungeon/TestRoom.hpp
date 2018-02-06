//
// Created by zouz on 06/02/18.
//

#ifndef LIFEISBORNE_TESTROOM_HPP
#define LIFEISBORNE_TESTROOM_HPP

#include "GenerationProfile.hpp"
#include "RoomPOD.hpp"
#include "../utils/Singleton.hpp"
#include "GenerationProfile.hpp"
#include "Dungeon.hpp"

namespace gen
{

    class Dungeon;

    struct TestRoom
    {

        TestRoom(Position pos, unsigned int size_x, unsigned int size_y);
        bool cut(const GenerationProfile &profile);

        Room Myroom;
        Room roomA;
        Room roomB;
    };
}

#endif //LIFEISBORNE_TESTROOM_HPP
