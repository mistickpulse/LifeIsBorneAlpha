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

    class InputContextManager;


    namespace
    {
        const unsigned int maxController = 3; // start to 0
        const unsigned int maxSfmlController = 7;
        const unsigned int MaxPlayer = 5; // (1 more for the control of Keyboard + controller for the player 1
    }

    using PlayerMappedInput = std::vector<std::shared_ptr<MappedInput>>;

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

        void compute();

        struct ContextRawAxis
        {
            std::vector<RawInputAxis> _controller;
            std::vector<RawInputAxis> _mouse;
        };

        std::unordered_map<ContextList, ContextRawAxis> _ContextToRaw =
            {{
                 {ContextList::Game, {
                                         {
                                             RawInputAxis::LEFT_X,
                                             RawInputAxis::LEFT_Y,
                                             RawInputAxis::RIGHT_X,
                                             RawInputAxis::RIGHT_Y
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

    public: /* Event Handlers */

        void receive(const Evt::ChangeInputContext &evt);
        void receive(const Evt::ChangePlayerMode &evt);
        void receive(const Evt::DisconectedJoystick &evt);

    private:

        int __checkControllerQte() const;
        void __handleJoystickChanges(int qte);
        char __getNewControllerId();
        void __handleDisconnectedJoystick();
        void __disconnectJoystick(int JoystickId);

        bool __loadControler();

        void __loadKeyboard();

        void __changeInputContext(ContextList ctx);

    private:
        Evt::EventManager &_evtMgr;
        ContextList activeContext{ContextList::Menu};
        PlayerMappedInput _playersMappedInputs{};
        InputContextManager _ictxMgr;
        unsigned int _playerQte{0};
        unsigned int _controllerConnected{0};
        PlayerMode _currentMode{PlayerMode::ONE_PLAYER};
    };
}

#endif //LIFEISBORNE_INPUTMANAGER_HPP

