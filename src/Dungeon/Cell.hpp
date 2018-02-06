//
// Created by zouz on 05/02/18.
//

#ifndef LIFEISBORNE_CELL_HPP
#define LIFEISBORNE_CELL_HPP

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>
#include "GenerationProfile.hpp"
#include "../utils/Position.hpp"
#include "../utils/Interval.hpp"
#include "RoomGenerationMode.hpp"
#include "TestRoom.hpp"

namespace gen
{

    class Cell
    {
    public:
        Cell(unsigned int size_x, unsigned int size_y, Position pos);

        ~Cell() = default;

        void generateRooms(int iteration);
        void setGenerationProfile(std::shared_ptr<GenerationProfile> &ptr);

        friend void operator<<(sf::RenderWindow &win, const Cell &c);

    private:
        unsigned int _SizeX;
        unsigned int _SizeY;
        Position _pos;
        std::shared_ptr<GenerationProfile> _profile;
        std::array<std::shared_ptr<Cell>, 2> _childs;
    };

    void operator<<(sf::RenderWindow &win, const gen::Cell &c);
}

#endif //LIFEISBORNE_CELL_HPP
