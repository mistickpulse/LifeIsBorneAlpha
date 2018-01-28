//
// Created by zouz on 28/01/18.
//

#ifndef LIFEISBORNE_EVENTMANAGER_HPP
#define LIFEISBORNE_EVENTMANAGER_HPP

#include <functional>
#include <map>
#include "Events/AEvent.hpp"
#include "Receiver.hpp"
#include "../../utils/Singleton.hpp"

struct CallBackBase
{

    virtual ~CallBackBase() = default;
    virtual void operator()(const AEvent *evt) const = 0;
};

template <typename TEvent>
struct CallBackWrapper : public CallBackBase
{
    CallBackWrapper(const std::function<void(const TEvent &)> &cb) : _cb(cb)
    {
    }

    void operator()(const AEvent *ev) const override
    {
        _cb(*static_cast<const TEvent *>(ev));
    }

    std::function<void(const TEvent &)> _cb;
};

class EventManager : public Singleton<EventManager>
{
public:
    EventManager() = default;
    ~EventManager() = default;

public:

    template <typename TEvent, typename Receiver>
    void subscribe(Receiver &rcv)
    {
        size_t uniqueId = __getTypeId<TEvent>();
        CallBackWrapper<TEvent> tmp([&rcv](const auto &evt) {
            rcv.receive(evt);
        });
        _receivers[uniqueId].push_back(std::make_unique<CallBackWrapper<TEvent>>(tmp));
    }

    template <typename TEvent, typename ... Args>
    void emit(Args ... args)
    {
        TEvent evt(std::forward<Args>(args) ...);

        size_t EvtId = __getTypeId<TEvent>();
        std::for_each(begin(_receivers[EvtId]), end(_receivers[EvtId]), [&evt](const auto &cb) {
            (*cb)(&evt);
        });
    };

private:
    size_t __genUniqueId()
    {
        static size_t nbr{0};
        return nbr++;
    }

    template <typename T>
    size_t __getTypeId()
    {
        static size_t EvtId{__genUniqueId()};
        return EvtId;
    }

private:
    using VectorReceiver = std::vector<std::unique_ptr<CallBackBase>>;
    std::map<size_t, VectorReceiver> _receivers;
};

#endif //LIFEISBORNE_EVENTMANAGER_HPP
