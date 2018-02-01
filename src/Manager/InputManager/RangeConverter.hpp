//
// Created by zouz on 01/02/18.
//

#ifndef LIFEISBORNE_RANGECONVERTER_HPP
#define LIFEISBORNE_RANGECONVERTER_HPP

#include <unordered_map>
#include "InputConstant.hpp"
#include "../../utils/Interval.hpp"
#include "../EventManager/EventManager.hpp"
#include "../EventManager/Events/ParamEvent.hpp"
#include "../../utils/Position.hpp"

namespace Inputs
{

    //Forward
    struct RangeConvertedPackage;

    using RangeCompute = std::function<void(RangeConvertedPackage &)>;

    struct RangeConvertedPackage
    {
        RangeCompute computeRange;
        Interval<int> interval;
        Position pos;
    };

    class RangeConverter : public Singleton<RangeConverter>
    {
    public:
        RangeConverter()
        {
            //auto &evtMgr = Evt::EventManager::getInstance();
            //evtMgr.subscribe<Evt::ChangeScreenSize>(*this);
        }

        ~RangeConverter() = default;

    public:

    private:
        void __initRangeBehavior()
        {
        }

    private:

        std::unordered_map<std::string, GameRange> _rangedId =
            {{
                 {"BASIC_MOUSE_H", GameRange::BASIC_MOUSE_H},
                 {"BASIC_MOUSE_V", GameRange::BASIC_MOUSE_V},

                 {"VIEWER_MOUSE_H", GameRange::VIEWER_MOUSE_H},
                 {"VIEWER_MOUSE_V", GameRange::VIEWER_MOUSE_V},

                 {"BASIC_JOYSTICK_H", GameRange::BASIC_JOYSTICK_H},
                 {"BASIC_JOYSTICK_V", GameRange::BASIC_JOYSTICK_V},

                 {"VIEWER_JOYSTICK_H", GameRange::VIEWER_JOYSTICK_H},
                 {"VIEWER_JOYSTICK_V", GameRange::VIEWER_JOYSTICK_V},
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
                 {GameRange::BASIC_MOUSE_H, {{[]([[maybe_unused]]RangeConvertedPackage &pck) {}}, {-1, -1}, {}}},
                 {GameRange::BASIC_MOUSE_V, {{[]([[maybe_unused]]RangeConvertedPackage &pck) {}}, {-1, -1}, {}}},

                 {GameRange::VIEWER_MOUSE_H, {{[]([[maybe_unused]]RangeConvertedPackage &pck) {}}, {-1, -1}, {}}},
                 {GameRange::VIEWER_MOUSE_V, {{[]([[maybe_unused]]RangeConvertedPackage &pck) {}}, {-1, -1}, {}}},

                 {GameRange::BASIC_JOYSTICK_H, {{[]([[maybe_unused]]RangeConvertedPackage &pck) {}}, {-100, 100}, {}}},
                 {GameRange::BASIC_JOYSTICK_V, {{[]([[maybe_unused]]RangeConvertedPackage &pck) {}}, {-100, 100}, {}}},

                 {GameRange::VIEWER_JOYSTICK_H, {{[]([[maybe_unused]]RangeConvertedPackage &pck) {}}, {-1, -1}, {}}},
                 {GameRange::VIEWER_JOYSTICK_V, {{[]([[maybe_unused]]RangeConvertedPackage &pck) {}}, {-1, -1}, {}}}
             }};
    };
}

#endif //LIFEISBORNE_RANGECONVERTER_HPP
