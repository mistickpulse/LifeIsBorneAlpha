//
// Created by zouz on 06/02/18.
//

#include "TestRoom.hpp"

gen::TestRoom::TestRoom(Position pos, unsigned int size_x, unsigned int size_y)
{
    Myroom.pos = pos;
    Myroom.SizeX = size_x;
    Myroom.SizeY = size_y;
}

bool gen::TestRoom::cut(const GenerationProfile &profile)
{
    GenBehavior &bhrv = Dungeon::getInstance()._RoomBehavior[profile.mode];
    unsigned short nbrtry = 0;
    int nbr = 0;
    roomA = Myroom;
    roomB = Myroom;
    if (rand() % 2) {
        do {
            nbr = rand() % Myroom.SizeX;
            unsigned int NbrPos = static_cast<unsigned int>(Myroom.pos.x) + nbr;
            roomA.SizeX = static_cast<unsigned int>(std::abs(NbrPos - Myroom.pos.x));
            roomB.pos.x = NbrPos;
            roomB.SizeX = static_cast<unsigned int>(std::abs(Myroom.pos.x + Myroom.SizeX - NbrPos));
            nbrtry++;
        } while (!bhrv(roomA, roomB, profile, true) &&
                 nbrtry < profile.MaxRandomTry);
    } else {
        do {
            nbr = rand() % Myroom.SizeY;
            unsigned int NbrPos = static_cast<unsigned int>(Myroom.pos.y) + nbr;
            roomA.SizeY = static_cast<unsigned int>(std::abs(NbrPos - Myroom.pos.y));
            roomB.pos.y = NbrPos;
            roomB.SizeY = static_cast<unsigned int>(std::abs(Myroom.pos.y + Myroom.SizeY - NbrPos));
            nbrtry++;
        } while (!bhrv(roomA, roomB, profile, false) &&
                 nbrtry < profile.MaxRandomTry);
    }
    if (nbrtry >= profile.MaxRandomTry)
        return false;
    return true;
}
