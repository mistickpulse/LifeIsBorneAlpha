//
// Created by zouz on 19/12/17.
//

#ifndef LIFEISBORNE_INPUTMANAGER_HPP
#define LIFEISBORNE_INPUTMANAGER_HPP

#include <queue>
#include <array>
#include <unordered_map>
#include <map>
#include "../../utils/Singleton.hpp"
#include "../EventManager/Events/EventList.hpp"
#include "RawInputConstant.hpp"
#include "MappedInput.hpp"
#include "Context/InputContextManager.hpp"

namespace Inputs
{

# define KEYBOARD_ID (-1)
    class InputContextManager;

    namespace
    {
        const unsigned int MaximumController = 5;
        const unsigned int MinimumControler = 1;
        const unsigned int MaxPlayer = 4;
    }

    using PlayerMappedInput = std::deque<std::shared_ptr<MappedInput>>;

    class InputManager : public Singleton<InputManager>
    {
    public:
        InputManager();

        ~InputManager() override;

        PlayerMappedInput &getPlayerInputs()
        {
            return _playersMappedInputs;
        }

        void update();

        unsigned int getPlayerQte() const
        {
            return _playerQte;
        }

        struct ContextRawAxis
        {
            std::vector<RawInputAxis> _controller;
            std::vector<RawInputAxis> _mouse;
        };

    public: /* Event Handlers */

        void receive(const Evt::ChangeInputContext &evt);
        void receive(const Evt::ChangePlayerMode &evt);
        void receive(const Evt::DisconectedJoystick &evt);

    private:
        void __updateContext();
        void __updateConnectedController();
        void __ifUnplugedUnloadController();
        char __getNewControllerId() const;
        void __loadController();
        auto __loadKeyboard();
        void __initControllers();
        void __updateControllers();
        unsigned int __getControlerConnectedQte();

    private:

        Evt::EventManager &_evtMgr;
        ContextList _activeContext{ContextList::Menu};
        PlayerMappedInput _playersMappedInputs{};
        InputContextManager _ictxMgr;
        unsigned int _playerQte{1};
        unsigned int _controllerConnected{0};
        PlayerMode _currentMode{PlayerMode::ONE_PLAYER};
        std::vector<char> _controllerIdConnected{};

    private:

        std::unordered_map<ContextList, ContextRawAxis> _ContextToRaw =
            {{
                 {ContextList::Game, {
                                         {
                                             RawInputAxis::LEFT_X,
                                             RawInputAxis::LEFT_Y,
                                             RawInputAxis::RIGHT_X,
                                             RawInputAxis::RIGHT_Y,
                                             RawInputAxis::CROSS_X,
                                             RawInputAxis::CROSS_Y
                                         },
                                         {
                                             RawInputAxis::MOUSE_X,
                                             RawInputAxis::MOUSE_Y
                                         }
                                     },
                 },
                 {
                     ContextList::Menu, {
                                            {
                                                RawInputAxis::LEFT_X,
                                                RawInputAxis::LEFT_Y,
                                                RawInputAxis::RIGHT_X,
                                                RawInputAxis::RIGHT_Y,
                                                RawInputAxis::CROSS_X,
                                                RawInputAxis::CROSS_Y
                                            },
                                            {
                                                RawInputAxis::MOUSE_X,
                                                RawInputAxis::MOUSE_Y
                                            }
                                        }
                 },
                 {
                     ContextList::RawMenu, {

                                               {

                                                   RawInputAxis::LEFT_X,
                                                   RawInputAxis::LEFT_Y,
                                                   RawInputAxis::CROSS_X,
                                                   RawInputAxis::CROSS_Y
                                               },
                                               {
                                                   RawInputAxis::MOUSE_X,
                                                   RawInputAxis::MOUSE_Y
                                               }
                                           }
                 }
             }};
    };
}

#endif //LIFEISBORNE_INPUTMANAGER_HPP

