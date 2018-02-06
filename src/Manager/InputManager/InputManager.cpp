//
// Created by zouz on 19/12/17.
//


#include "InputManager.hpp"

Inputs::InputManager::InputManager() :
    _evtMgr(Evt::EventManager::getInstance())
{
    _evtMgr.subscribe<Evt::ChangeInputContext>(*this);
    _evtMgr.subscribe<Evt::DisconectedJoystick>(*this);
    _evtMgr.subscribe<Evt::ChangePlayerMode>(*this);
    __initControllers();
    //__loadKeyboard();
}

Inputs::InputManager::~InputManager()
{
}

void Inputs::InputManager::update()
{
    __updateControllers();
    for (auto &it : _playersMappedInputs) {
        _ictxMgr.compute(*it);
    }
    //Tmp test
    if (_currentMode == PlayerMode::ONE_PLAYER && _controllerConnected >= 2) {
        while (_playersMappedInputs[1]->_action.size()) {
            _playersMappedInputs[0]->_action.push(_playersMappedInputs[1]->_action.front());
            _playersMappedInputs[1]->_action.pop();
        }
    }
}

/* Event Handlers */

void Inputs::InputManager::receive(const Evt::ChangeInputContext &evt)
{
    _activeContext = evt.ctx;
    __updateContext();
}

void Inputs::InputManager::receive(const Evt::ChangePlayerMode &evt)
{
    _currentMode = evt._mode;
    _playerQte = static_cast<unsigned int>(evt._mode);
}

void Inputs::InputManager::receive(const Evt::DisconectedJoystick &evt)
{
    (void)evt;
}

auto Inputs::InputManager::__loadKeyboard()
{
    MappedInput mi;
    mi._axis = &_ContextToRaw.at(_activeContext)._mouse;
    mi.ControllerId = KEYBOARD_ID;
    ++_controllerConnected;

    std::shared_ptr<MappedInput> ptr = std::make_shared<MappedInput>(mi);
    return ptr;
}

void Inputs::InputManager::__initControllers()
{
    auto ptr = __loadKeyboard();
    _playersMappedInputs.push_back(ptr);
}

void Inputs::InputManager::__updateControllers()
{
    __updateConnectedController();
    unsigned int qte = static_cast<unsigned int>(_controllerIdConnected.size());
    while (_controllerConnected < qte && _controllerConnected < MaximumController) {
        __loadController();
    }
    while (_controllerConnected > qte && _controllerConnected > MinimumControler) {
        __ifUnplugedUnloadController();
    }
}

unsigned int Inputs::InputManager::__getControlerConnectedQte()
{
    return 0;
}

void Inputs::InputManager::__loadController()
{
    MappedInput mi;
    mi.ControllerId = __getNewControllerId();
    if (mi.ControllerId == -1) {
        std::cout << "No new Controller Connected" << std::endl;
        return;
    }
    std::cout << "Loading Controller" << std::endl;
    mi._axis = &_ContextToRaw.at(_activeContext)._controller;
    std::shared_ptr<MappedInput> ptr = std::make_shared<MappedInput>(mi);
    _playersMappedInputs.push_back(ptr);
    ++_controllerConnected;
}

char Inputs::InputManager::__getNewControllerId() const
{
    for (const auto &Connectedid : _controllerIdConnected) {

        bool check = true;
        for (const auto &MappedInput : _playersMappedInputs) {
            if (Connectedid == MappedInput->ControllerId) {
                check = false;
            }
        }
        if (check) {
            return static_cast<char>(Connectedid);
        }
    }
    return -1;
}

void Inputs::InputManager::__ifUnplugedUnloadController()
{
    std::vector<int> _ControllerPos;
    int Pos = 0;

    for (auto &Mi : _playersMappedInputs) {
        bool check = false;
        for (const auto &ControllerId : _controllerIdConnected) {
            if (Mi->ControllerId == ControllerId) {
                check = true;
                break;
            }
        }
        if (!check) {
            _ControllerPos.push_back(Pos);
        }
        ++Pos;
    }
    for (const auto &i : _ControllerPos) {
        _playersMappedInputs.erase(_playersMappedInputs.begin() + i);
        --_controllerConnected;
    }
}

void Inputs::InputManager::__updateConnectedController()
{
    _controllerIdConnected.clear();
    _controllerIdConnected.push_back(-1);
    for (unsigned int ControllerId = 0; ControllerId < sf::Joystick::Count; ++ControllerId) {
        if (sf::Joystick::isConnected(ControllerId)) {
            _controllerIdConnected.push_back(static_cast<char>(ControllerId));
        }
    }
}

void Inputs::InputManager::__updateContext()
{
    for (auto i = _playersMappedInputs.begin(); i != _playersMappedInputs.end(); ++i) {
        if (i == _playersMappedInputs.begin()) {
            (*i)->_axis = &_ContextToRaw.at(_activeContext)._mouse;
        } else {
            (*i)->_axis = &_ContextToRaw.at(_activeContext)._controller;
        }
    }
}


/* End Event Handler */

