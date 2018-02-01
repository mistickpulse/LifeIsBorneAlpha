//
// Created by zouz on 01/02/18.
//

#ifndef LIFEISBORNE_CONTEXTMANAGER_HPP
#define LIFEISBORNE_CONTEXTMANAGER_HPP

#include <string>
#include "../../../utils/Singleton.hpp"

namespace Inputs
{

    namespace
    {
        const std::string ContextDirectory = "Context";
        const std::string ContextListFile = "ContextList.json";

        const std::string ContextFieldExt = "Extension";
        const std::string ContextFieldDir = "Directory";
        const std::string ContextFieldNames = "ContextsNames";
    }

    class ContextManager : public Singleton<ContextManager>
    {
    public:
        ContextManager() = default;
        ~ContextManager() final = default;

        void addContext(const std::string &ContextName)
        {
        }

    private:
    };
}

#endif //LIFEISBORNE_CONTEXTMANAGER_HPP
