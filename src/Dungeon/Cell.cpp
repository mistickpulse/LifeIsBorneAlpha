//
// Created by zouz on 05/02/18.
//

#include "Cell.hpp"

gen::Cell::Cell(unsigned int size_x, unsigned int size_y, Position pos) :
    _SizeX(size_x), _SizeY(size_y), _pos(pos)
{
    for (auto &i : _childs) {
        i = nullptr;
    }
}

void gen::Cell::generateRooms(int iteration)
{
    if (iteration <= 0) {
        return;
    }
    TestRoom room(_pos, _SizeX, _SizeY);
    if (room.cut(*_profile) == false) {
        _childs[0] = nullptr;
        _childs[1] = nullptr;
        return;
    }

    _childs[0] = std::make_shared<Cell>(room.roomA.SizeX, room.roomA.SizeY, room.roomA.pos);
    _childs[0]->setGenerationProfile(_profile);
    _childs[1] = std::make_shared<Cell>(room.roomB.SizeX, room.roomB.SizeY, room.roomB.pos);
    _childs[1]->setGenerationProfile(_profile);

    _childs[0]->generateRooms(iteration - 1);
    _childs[1]->generateRooms(iteration - 1);
}

void gen::operator<<(sf::RenderWindow &win, const gen::Cell &c)
{
    for (auto &i : c._childs) {
        if (i != nullptr) {
            win << *i;
        }
    }
    if (c._childs[0] == nullptr) { // Im a leaf
        sf::RectangleShape rec(sf::Vector2f(c._SizeX, c._SizeY));
        rec.setOutlineThickness(1.0f);
        rec.setOutlineColor(sf::Color::Green);
        rec.setPosition(c._pos.x, c._pos.y);
        rec.setFillColor(sf::Color::Black);
        win.draw(rec);
    }
}

void gen::Cell::setGenerationProfile(std::shared_ptr<gen::GenerationProfile> &ptr)
{
    _profile = std::shared_ptr<GenerationProfile>(ptr);
}
