//
// Created by zouz on 30/01/18.
//

#ifndef LIFEISBORNE_EVENTMANAGER_HPP
#define LIFEISBORNE_EVENTMANAGER_HPP

#include <functional>
#include <map>
#include <memory>
#include <typeinfo>

#include "Events/AEvent.hpp"
#include "../../utils/Singleton.hpp"

// Pattern Inspired From Slyris (Roman Sztergbaum)

namespace Evt
{
    using RcvProtocol = std::function<void(const AEvent &ev)>;

    class EvtCallBack
    {
    public:
        explicit EvtCallBack(RcvProtocol cb) : _cb(std::move(cb))
        {
        }

        ~EvtCallBack() = default;

        void operator()(const AEvent &ev)
        {
            return _cb(ev);
        }

    private:
        RcvProtocol _cb;
    };

    class EventManager : public Singleton<EventManager>
    {
    public:
        EventManager() = default;
        ~EventManager() = default;

    public:

        template <typename Event, typename rcv>
        void subscribe(rcv &r)
        {
            _callbacks[typeid(Event).name()].push_back(std::make_unique<EvtCallBack>(
                [&r](const AEvent &ev) {
                    r.receive(static_cast<const Event &>(ev)); //Safe upcast
                }));
        }

        template <typename Event, typename ... Args>
        void emit(Args ... args)
        {
            Event evt(std::forward<Args>(args) ...);
            auto &vec = _callbacks.at(typeid(Event).name());
            std::for_each(vec.begin(), vec.end(), [&evt](auto &cb) {
                (*cb)(evt);
            });
        }

    private:
        using UniqueId = std::string;
        std::map<UniqueId, std::vector<std::unique_ptr<EvtCallBack>>> _callbacks;
    };
}

#endif //LIFEISBORNE_EVENTMANAGER_HPP
