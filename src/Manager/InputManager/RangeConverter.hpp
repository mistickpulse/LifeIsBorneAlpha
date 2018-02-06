//
// Created by zouz on 01/02/18.
//

#ifndef LIFEISBORNE_RANGECONVERTER_HPP
#define LIFEISBORNE_RANGECONVERTER_HPP

#include <unordered_map>
#include <queue>
#include "InputConstant.hpp"
#include "../../utils/Interval.hpp"
#include "../EventManager/EventManager.hpp"
#include "../EventManager/Events/ParamEvent.hpp"
#include "../../utils/Position.hpp"
#include "MappedInput.hpp"

# define CONSTANT_JOYSTICK_MINRANGE 10

namespace Inputs
{
    enum class InputMode
    {
        MOUSE,
        CONTROLLER
    };


    //Forward
    struct RangeConvertedPackage;

    using RangeCompute = std::function<void(RangeConvertedPackage &, int ControlerId, RawInputAxis RawAxis)>;

    struct RangeConvertedPackage
    {
        RangeCompute computeRange{};
        Interval<int> interval{0, 0};
        Position pos{0, 0};
        int Sensivity_x{50};
        int Sensivity_y{50};
        MappedInput *mappedInputs{nullptr};
    };

    class RangeConverter : public Singleton<RangeConverter>
    {
    public:
        RangeConverter()
        {
            auto &evtMgr = Evt::EventManager::getInstance();
            evtMgr.subscribe<Evt::ChangeScreenSize>(*this);
        }

        ~RangeConverter() = default;

    public:
        const std::vector<GameRange> &getAuthorisedGameRange(InputMode mode) const
        {
            return _InputRangeConverter.at(mode);
        }

        RangeConvertedPackage &getRangeConvertedPackage(GameRange range)
        {
            return _rangesInterval.at(range);
        }

    public: // Event Handler
        void receive(const Evt::ChangeScreenSize &evt)
        {
            _rangesInterval[GameRange::BASIC_MOUSE_H].interval.min = 0;
            _rangesInterval[GameRange::BASIC_MOUSE_H].interval.max = evt.size_x;

            _rangesInterval[GameRange::BASIC_MOUSE_V].interval.min = 0;
            _rangesInterval[GameRange::BASIC_MOUSE_V].interval.max = evt.size_y;
        }

    private:

        std::unordered_map<InputMode, std::vector<GameRange>> _InputRangeConverter =
            {{
                 {InputMode::CONTROLLER, {
                                             GameRange::BASIC_JOYSTICK_H,
                                             GameRange::BASIC_JOYSTICK_V,
                                             GameRange::BASIC_CROSS_H,
                                             GameRange::BASIC_CROSS_V,
                                             GameRange::VIEWER_JOYSTICK_H,
                                             GameRange::VIEWER_JOYSTICK_V
                                         }},
                 {InputMode::MOUSE, {
                                        GameRange::BASIC_MOUSE_H,
                                        GameRange::BASIC_MOUSE_V,
                                        GameRange::VIEWER_MOUSE_H,
                                        GameRange::VIEWER_MOUSE_V
                                    }}
             }};

        /*
         * Pour le moi de demain,
         * Pense a remplir les callback en suivant le model du comportement de la range que tu traite
         * Basic mouse : ne rien faire.
         * Viewer mouse : compute avec la trigonometrie du cul
         * Basic Joystick : ne rien faire.
         * Viewer Joystick : compute avec la trigonometrie du cul (aussi)
         *
         * REFAIRE LA TRIGONOMETRIE SA MERE
         */

        std::unordered_map<GameRange, RangeConvertedPackage> _rangesInterval =
            {{

                 /* Basic Mouse */
                 {GameRange::BASIC_MOUSE_H, {{[](RangeConvertedPackage &pck, [[maybe_unused]]int ControlerId,
                                                 [[maybe_unused]]RawInputAxis RawAxis) {
                     sf::Vector2i v = sf::Mouse::getPosition();
                     pck.pos.x = (v.x - pck.pos.x) * pck.Sensivity_x;
                     if (pck.pos.x < pck.interval.min) {
                         pck.pos.x = pck.interval.min;
                     } else if (pck.pos.x >= pck.interval.max) {
                         pck.pos.x = pck.interval.max;
                     }
                     pck.mappedInputs->_pos.x = pck.pos.x;
                 }}, {-1, -1}, {}}},

                 {GameRange::BASIC_MOUSE_V, {{[](RangeConvertedPackage &pck, [[maybe_unused]]int ControlerId,
                                                 [[maybe_unused]]RawInputAxis RawAxis) {
                     sf::Vector2i v = sf::Mouse::getPosition();
                     pck.pos.y = (v.y - pck.pos.y) * pck.Sensivity_y;
                     if (pck.pos.y < pck.interval.min) {
                         pck.pos.y = pck.interval.min;
                     } else if (pck.pos.y > pck.interval.max) {
                         pck.pos.y = pck.interval.max;
                     }
                     pck.mappedInputs->_pos.y = pck.pos.y;
                 }}, {-1, -1}, {}}},



                 /* Viewer Mouse */

                 {GameRange::VIEWER_MOUSE_H, {{[]([[maybe_unused]]RangeConvertedPackage &pck,
                                                  [[maybe_unused]]int ControlerId,
                                                  [[maybe_unused]]RawInputAxis RawAxis) {
                     sf::Vector2i v = sf::Mouse::getPosition();
                     pck.pos.x = v.x;
                 }}, {-1, -1}, {}}},
                 {GameRange::VIEWER_MOUSE_V, {{[]([[maybe_unused]]RangeConvertedPackage &pck,
                                                  [[maybe_unused]]int ControlerId,
                                                  [[maybe_unused]]RawInputAxis RawAxis) {
                     sf::Vector2i v = sf::Mouse::getPosition();
                     pck.pos.y = v.y;
                 }}, {-1, -1}, {}}},



                 /* Basic Joystick */

                 {GameRange::BASIC_JOYSTICK_H, {{[]([[maybe_unused]]RangeConvertedPackage &pck,
                                                    [[maybe_unused]]int ControlerId,
                                                    [[maybe_unused]]RawInputAxis RawAxis) {
                     BindingContextHelper &ctxHelper = BindingContextHelper::getInstance();
                     float pos = sf::Joystick::getAxisPosition(static_cast<unsigned int>(ControlerId),
                                                               ctxHelper.JoystickAxisConverter[RawAxis]);
                     if (pos > CONSTANT_JOYSTICK_MINRANGE) {
                         pck.mappedInputs->_action.push(GameAction::RIGHT);
                     } else if (pos < -CONSTANT_JOYSTICK_MINRANGE) {
                         pck.mappedInputs->_action.push(GameAction::LEFT);
                     }

                 }}, {-100, 100}, {}}},
                 {GameRange::BASIC_JOYSTICK_V, {{[]([[maybe_unused]]RangeConvertedPackage &pck,
                                                    [[maybe_unused]]int ControlerId,
                                                    [[maybe_unused]]RawInputAxis RawAxis) {
                     BindingContextHelper &ctxHelper = BindingContextHelper::getInstance();
                     float pos = static_cast<int>(sf::Joystick::getAxisPosition(static_cast<unsigned int>(ControlerId),
                                                                                ctxHelper.JoystickAxisConverter[RawAxis]));

                     if (pos > CONSTANT_JOYSTICK_MINRANGE) {
                         pck.mappedInputs->_action.push(GameAction::DOWN);
                     } else if (pos < -CONSTANT_JOYSTICK_MINRANGE) {
                         pck.mappedInputs->_action.push(GameAction::UP);
                     }
                 }}, {-100, 100}, {}}},



                 /* Viewer Joystick */

                 {GameRange::VIEWER_JOYSTICK_H, {{[]([[maybe_unused]]RangeConvertedPackage &pck,
                                                     [[maybe_unused]]int ControlerId,
                                                     [[maybe_unused]]RawInputAxis RawAxis) {
                     BindingContextHelper &ctxHelper = BindingContextHelper::getInstance();
                     float pos = sf::Joystick::getAxisPosition(ControlerId,
                                                               ctxHelper.JoystickAxisConverter[RawAxis]);
                     (void)pos;
                 }}, {-1, -1}, {}}},

                 {GameRange::VIEWER_JOYSTICK_V, {{[]([[maybe_unused]]RangeConvertedPackage &pck,
                                                     [[maybe_unused]]int ControlerId,
                                                     [[maybe_unused]]RawInputAxis RawAxis) {
                     BindingContextHelper &ctxHelper = BindingContextHelper::getInstance();
                     float pos = sf::Joystick::getAxisPosition(ControlerId,
                                                               ctxHelper.JoystickAxisConverter[RawAxis]);
                     (void)pos;
                 }}, {-1, -1}, {}}},


                 /* Basic Cross */


                 {GameRange::BASIC_CROSS_H, {{[]([[maybe_unused]]RangeConvertedPackage &pck,
                                                 [[maybe_unused]]int ControlerId,
                                                 [[maybe_unused]]RawInputAxis RawAxis) {

                     std::cout << "Computing Cross" << std::endl;
                     BindingContextHelper &ctxHelper = BindingContextHelper::getInstance();
                     float pos = sf::Joystick::getAxisPosition(ControlerId,
                                                               ctxHelper.JoystickAxisConverter[RawAxis]);
                     if (pos < -CONSTANT_JOYSTICK_MINRANGE) {
                         pck.mappedInputs->_action.push(GameAction::LEFT);
                     } else if (pos > CONSTANT_JOYSTICK_MINRANGE) {
                         pck.mappedInputs->_action.push(GameAction::RIGHT);
                     }
                 }}, {-100, 100}, {}}},
                 {GameRange::BASIC_CROSS_V, {{[]([[maybe_unused]]RangeConvertedPackage &pck,
                                                 [[maybe_unused]]int ControlerId,
                                                 [[maybe_unused]]RawInputAxis RawAxis) {
                     std::cout << "Computing Cross" << std::endl;
                     BindingContextHelper &ctxHelper = BindingContextHelper::getInstance();
                     float pos = sf::Joystick::getAxisPosition(ControlerId,
                                                               ctxHelper.JoystickAxisConverter[RawAxis]);

                     if (pos < -CONSTANT_JOYSTICK_MINRANGE) {
                         pck.mappedInputs->_action.push(GameAction::UP);
                     } else if (pos > CONSTANT_JOYSTICK_MINRANGE) {
                         pck.mappedInputs->_action.push(GameAction::DOWN);
                     }
                 }}, {-100, 100}, {}}}
             }};
    };
}

#endif //LIFEISBORNE_RANGECONVERTER_HPP
