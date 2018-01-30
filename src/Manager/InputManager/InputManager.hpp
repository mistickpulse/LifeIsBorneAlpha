//
// Created by zouz on 28/01/18.
//

#ifndef LIFEISBORNE_INPUTMANAGER_HPP
#define LIFEISBORNE_INPUTMANAGER_HPP

#include <memory>
#include <iostream>
#include "Controller.hpp"
#include "../../utils/Singleton.hpp"
#include "../EventManager/EventManager.hpp"
#include "../EventManager/Events/InputEvents.hpp"

namespace Inputs
{

    namespace
    {
        constexpr uint8_t MaxPlayer = 4;
        constexpr uint8_t MaxController = 8;
    }

    class InputManager : public Singleton<InputManager>
    {

    public:
        InputManager() : _evtMgr(Evt::EventManager::getInstance())
        {
            _evtMgr.subscribe<Evt::AddPlayer>(*this);
            _evtMgr.subscribe<Evt::RemovePlayer>(*this);
            _evtMgr.subscribe<Evt::ChangeControlMode>(*this);
        }

        ~InputManager() final = default;

    public: // Receivers
        void receive([[maybe_unused]]const Evt::AddPlayer &evt)
        {
            std::cout << "Adding Player" << std::endl;
        }

        void receive([[maybe_unused]]const Evt::RemovePlayer &evt)
        {
            std::cout << "Removing Player" << std::endl;
        }

        void receive([[maybe_unused]]const Evt::ChangeControlMode &evt)
        {
            std::cout << "Changing Control mode" << std::endl;
        }

    private:

        void removePlayer()
        {
            --_playerQte;
        }

        PlayerInput &addPlayer([[maybe_unused]]const std::string &profileName)
        {
            //TODO
            return _playerBinds[_playerQte];
        }

        void __buildController([[maybe_unused]]const std::string &ProfileName)
        {
            ++_playerQte;
        }

        void __buildController()
        {
            ++_playerQte;
        }

    private:
        Evt::EventManager &_evtMgr;

        std::array<std::unique_ptr<Controller>, MaxPlayer> _inputs;
        std::array<PlayerInput, MaxPlayer> _playerBinds;
        uint8_t _playerQte{1};
        uint8_t _controllerConnected{0};
        uint8_t _controllerUsed{0};
    };
}

#endif //LIFEISBORNE_INPUTMANAGER_HPP
