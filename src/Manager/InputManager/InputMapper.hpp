//
// Created by zouz on 02/02/18.
//

#ifndef LIFEISBORNE_INPUTMAPPER_HPP
#define LIFEISBORNE_INPUTMAPPER_HPP

#include "Context/InputContext.hpp"
#include "Context/ContextList.hpp"
#include "Context/InputContextManager.hpp"

namespace Inputs
{

    class InputMapper
    {
    public:
        InputMapper() :
            _evtMgr(Evt::EventManager::getInstance()), _context(InputContextManager::getInstance().getActiveContext())
        {
        }

        ~InputMapper() = default;

    public:

    private:
        Evt::EventManager &_evtMgr;
        InputContext *_context;
    };
}

#endif //LIFEISBORNE_INPUTMAPPER_HPP
