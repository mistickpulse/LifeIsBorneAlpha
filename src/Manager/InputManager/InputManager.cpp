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
    __loadKeyboard();
}

Inputs::InputManager::~InputManager()
{
}

void Inputs::InputManager::update()
{
    int ret = __checkControllerQte();
    if (ret != 0) {
        std::cout << "Handling Joystick Change" << std::endl;
        __handleJoystickChanges(ret);
    }
    compute();
}

void Inputs::InputManager::compute()
{
    for (auto &i : _playersMappedInputs) {
        _ictxMgr.compute(*i);
    }

    if (_currentMode == PlayerMode::ONE_PLAYER && _controllerConnected == 1) { //tmp
        auto &q = _playersMappedInputs[1]->_action;
        while (q.size()) {
            _playersMappedInputs[0]->_action.push(q.front());
            q.pop();
        }
    }
}

char Inputs::InputManager::__getNewControllerId()
{
    for (unsigned int ControllerId = 0; ControllerId < sf::Joystick::Count; ++ControllerId) {
        bool check = true;
        for (auto &i : _playersMappedInputs) {
            if (i->ControllerId == static_cast<char>(ControllerId)) {
                check = false;
            }
        }
        if (check && sf::Joystick::isConnected(ControllerId)) {
            return static_cast<char>(ControllerId);
        }
    }
    return -1;
}

bool Inputs::InputManager::__loadControler()
{
    char id = __getNewControllerId();
    if (id == -1) {
        std::cerr << "unable To handle Anymore Joystick" << std::endl;
        return false;
    }
    std::cout << "Loading Controller with id[" << static_cast<int>(id) << "]" << std::endl;

    ++_controllerConnected;
    ++_playerQte;
    MappedInput newController;
    newController.ControllerId = static_cast<char>(id);
    newController._axis = &_ContextToRaw.at(activeContext)._controller;

    for (unsigned int i = 0; i < _playersMappedInputs.size(); ++i) {
        if (i > 0 && _playersMappedInputs[i]->ControllerId == -1) {
            _playersMappedInputs[i] = std::make_shared<MappedInput>(newController);
            return true;
        }
    }

    _playersMappedInputs.push_back(std::make_shared<MappedInput>(newController));
    return true;
}

void Inputs::InputManager::__loadKeyboard()
{
    MappedInput newKeyboard;
    newKeyboard.ControllerId = -1;
    newKeyboard._axis = &_ContextToRaw.at(activeContext)._mouse;
    _playersMappedInputs.push_back(std::make_shared<MappedInput>(newKeyboard));
    ++_playerQte;
}

void Inputs::InputManager::__changeInputContext(Inputs::ContextList ctx)
{
    activeContext = ctx;
    for (auto &i : _playersMappedInputs) {
        if (i->ControllerId == -1) {
            i->_axis = &_ContextToRaw.at(ctx)._mouse;
        } else {
            i->_axis = &_ContextToRaw.at(ctx)._controller;
        }
    }
}

/* Event Handlers */

void Inputs::InputManager::receive(const Evt::ChangeInputContext &evt)
{
    __changeInputContext(evt.ctx);
}

void Inputs::InputManager::receive(const Evt::ChangePlayerMode &evt)
{
    int act = evt._mode - _currentMode;

    _currentMode = evt._mode;
    _playerQte = evt._mode;
    while (act < 0) {
        _playersMappedInputs.erase(_playersMappedInputs.end());
        --_playerQte;
        ++act;
    }
    while (act > 0) {
        __loadControler();
        --act;
    }
}

void Inputs::InputManager::receive(const Evt::DisconectedJoystick &evt)
{
    __disconnectJoystick(_playersMappedInputs[evt._playerId]->ControllerId);
}

/* End Event Handler */


int Inputs::InputManager::__checkControllerQte() const
{
    unsigned int qte = 0;
    for (unsigned int i = 0; i < sf::Joystick::Count; ++i) {
        if (sf::Joystick::isConnected(i)) {
            qte++;
        }
    }
    return static_cast<int>(qte) - static_cast<int>(_controllerConnected);
}

void Inputs::InputManager::__handleJoystickChanges(int qte)
{
    std::cout << "Joystick Difference [" << qte << "]" << std::endl;
    while (qte > 0) {
        if (_controllerConnected + 1 <= _playerQte) {
            std::cout << "Loading Controller" << std::endl;
            __loadControler();
            --qte;
        } else {
            break;
        }


    }
    if (qte < 0) {
        std::cout << "Removing Controller" << std::endl;
        __handleDisconnectedJoystick();
    }
}

void Inputs::InputManager::__handleDisconnectedJoystick()
{
    for (auto &i : _playersMappedInputs) {
        if (i->ControllerId != -1 && !sf::Joystick::isConnected(i->ControllerId)) {
            __disconnectJoystick(i->ControllerId);
        }
    }
}

void Inputs::InputManager::__disconnectJoystick(int JoystickId)
{
    for (auto i = _playersMappedInputs.begin(); i != _playersMappedInputs.end(); ++i) {
        if ((*i)->ControllerId == JoystickId) {
            _playersMappedInputs.erase(i);
            break;
        }
    }
    --_playerQte;
    --_controllerConnected;
}
