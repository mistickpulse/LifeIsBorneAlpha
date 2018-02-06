//
// Created by zouz on 05/02/18.
//

#include "Dungeon.hpp"

void gen::Dungeon::create(const gen::GenerationProfile &profile, int Iteration)
{
    _profile = std::make_shared<GenerationProfile>(profile);
    *_profile = profile;
    Position pos{0, 0};
    _dungeon = std::make_shared<Cell>(profile.size_x, profile.size_y, pos);
    _dungeon->setGenerationProfile(_profile);

    _dungeon->generateRooms(Iteration);
}

void gen::operator<<(sf::RenderWindow &win, const gen::Dungeon &d)
{
    win << *d._dungeon;
}

gen::Dungeon::Dungeon()
{
    std::srand(time(NULL));
}
