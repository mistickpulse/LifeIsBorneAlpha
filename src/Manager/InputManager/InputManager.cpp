//
// Created by zouz on 19/12/17.
//


#include "InputManager.hpp"
#include "Context/InputContext.hpp"

Inputs::InputManager::InputManager()
{
    __load();
}

Inputs::InputManager::~InputManager()
{
}

void Inputs::InputManager::__load()
{
    InputContext _test("../Assets/Inputs/InputMapping/Maps", "RawMenu");
}

