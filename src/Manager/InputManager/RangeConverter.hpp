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

    using RangeCompute = std::function<void(RangeConvertedPackage &, int, int)>;

    struct RangeConvertedPackage
    {
        RangeCompute computeRange;
        Interval<int> interval;
        Position pos;
        int Sensivity_x{50};
        int Sensivity_y{50};
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
        void receive(Evt::ChangeScreenSize &evt)
        {
            _rangesInterval[GameRange::BASIC_MOUSE_H].interval.min = 0;
            _rangesInterval[GameRange::BASIC_MOUSE_H].interval.max = evt.size_x;

            _rangesInterval[GameRange::BASIC_MOUSE_V].interval.min = 0;
            _rangesInterval[GameRange::BASIC_MOUSE_V].interval.max = evt.size_y;
        }

    private:
        void __initRangeBehavior()
        {
        }

    private:

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
                 {GameRange::BASIC_MOUSE_H, {{[](RangeConvertedPackage &pck, [[maybe_unused]]int x,
                                                 [[maybe_unused]]int y) {

                     pck.pos.x = (x - pck.pos.x) * pck.Sensivity_x;
                     if (pck.pos.x < pck.interval.min) {
                         pck.pos.x = pck.interval.min;
                     } else if (pck.pos.x >= pck.interval.max) {
                         pck.pos.x = pck.interval.max;
                     }
                 }}, {-1, -1}, {}}},

                 {GameRange::BASIC_MOUSE_V, {{[](RangeConvertedPackage &pck, [[maybe_unused]]int x,
                                                 [[maybe_unused]]int y) {

                     pck.pos.y = (y - pck.pos.y) * pck.Sensivity_y;
                     if (pck.pos.y < pck.interval.min) {
                         pck.pos.y = pck.interval.min;
                     } else if (pck.pos.y > pck.interval.max) {
                         pck.pos.y = pck.interval.max;
                     }
                 }}, {-1, -1}, {}}},

                 {GameRange::VIEWER_MOUSE_H, {{[]([[maybe_unused]]RangeConvertedPackage &pck, [[maybe_unused]]int x,
                                                  [[maybe_unused]]int y) {
                     //trigo du cul sur mouse
                 }}, {-1, -1}, {}}},
                 {GameRange::VIEWER_MOUSE_V, {{[]([[maybe_unused]]RangeConvertedPackage &pck, [[maybe_unused]]int x,
                                                  [[maybe_unused]]int y) {
                 }}, {-1, -1}, {}}},

                 {GameRange::BASIC_JOYSTICK_H, {{[]([[maybe_unused]]RangeConvertedPackage &pck, [[maybe_unused]]int x,
                                                    [[maybe_unused]]int y) {
                 }}, {-100, 100}, {}}},
                 {GameRange::BASIC_JOYSTICK_V, {{[]([[maybe_unused]]RangeConvertedPackage &pck, [[maybe_unused]]int x,
                                                    [[maybe_unused]]int y) {
                 }}, {-100, 100}, {}}},

                 {GameRange::VIEWER_JOYSTICK_H, {{[]([[maybe_unused]]RangeConvertedPackage &pck, [[maybe_unused]]int x,
                                                     [[maybe_unused]]int y) {
                 }}, {-1, -1}, {}}},
                 {GameRange::VIEWER_JOYSTICK_V, {{[]([[maybe_unused]]RangeConvertedPackage &pck, [[maybe_unused]]int x,
                                                     [[maybe_unused]]int y) {
                 }}, {-1, -1}, {}}}
             }};
    };
}

#endif //LIFEISBORNE_RANGECONVERTER_HPP
