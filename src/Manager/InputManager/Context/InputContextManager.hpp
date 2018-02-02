//
// Created by zouz on 01/02/18.
//

#ifndef LIFEISBORNE_CONTEXTMANAGER_HPP
#define LIFEISBORNE_CONTEXTMANAGER_HPP

#include <string>
#include <fstream>
#include "../../../utils/Singleton.hpp"
#include "InputContext.hpp"
#include "ContextList.hpp"
#include "../../EventManager/Events/EventList.hpp"
#include "../../../GlobalConf.hpp"

namespace Inputs
{

    namespace
    {
        const std::string InputDirectory = "Inputs";
        const std::string InputMappingDirectory = "InputMapping";
        const std::string InputListFile = "InputMapList.json";

        const std::string InputMapPath = InputDirectory + "/" + InputMappingDirectory + "/";

        const std::string MappingFieldExt = "Extension";
        const std::string MappingFieldDir = "Directory";
        const std::string MappingFieldNames = "MapsNames";
    }

    class InputContextManager : public Singleton<InputContextManager>
    {
        using json = nlohmann::json;

    public:
        InputContextManager();
        ~InputContextManager() final = default;

    public:
        InputContext *getActiveContext();

    public: // Event Handler
        void receive(const Evt::ChangeInputContext &evt);



        /* ====================== Private Field =================  */



    private:
        void __changeContext(ContextList ctx);
        void __subscribeEvent();

    private:
        std::unordered_map<std::string, ContextList> _contextNameConverter =
            {{
                 {"Game", ContextList::Game},
                 {"Menu", ContextList::Menu},
                 {"RawMenu", ContextList::RawMenu}
             }};

        std::map<ContextList, InputContext> _contexts;

    private: // FileSystem
        std::string _inputContextDir;
        json _contextFile;

    private:
        InputContext *_ActiveContext;
    };
}

#endif //LIFEISBORNE_CONTEXTMANAGER_HPP
