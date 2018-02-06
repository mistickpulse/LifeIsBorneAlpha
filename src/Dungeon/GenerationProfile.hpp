//
// Created by zouz on 05/02/18.
//

#ifndef LIFEISBORNE_GENERATIONPROFILE_HPP
#define LIFEISBORNE_GENERATIONPROFILE_HPP

#include <functional>
#include "RoomGenerationMode.hpp"

namespace gen
{

    struct Room;
    struct GenerationProfile;

    using GenBehavior = std::function<bool(const Room &roomA, const Room &roomB, const GenerationProfile &profile,
                                           bool odd)>;

    struct GenerationProfile
    {
        unsigned int MaxRandomTry;
        unsigned int size_x;
        unsigned int size_y;

        unsigned int MinimumSizeRoomX;
        unsigned int MinimumSizeRoomY;
        RoomGenerationMode mode;
    };
}

#endif //LIFEISBORNE_GENERATIONPROFILE_HPP
