//
// Created by zouz on 02/02/18.
//

#include "InputContextManager.hpp"

Inputs::InputContextManager::InputContextManager()
{
    __subscribeEvent();
    std::string MapListRpath = Param::AssetsPath + InputMapPath + InputListFile;
    std::cout << "File:[" << MapListRpath << "]" << std::endl;
    std::ifstream file(MapListRpath);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to load Input Context: " + MapListRpath);
    }
    file >> _contextFile;

    _inputContextDir = Param::AssetsPath + InputMapPath;
    std::string tmp = _contextFile[MappingFieldDir];
    _inputContextDir += tmp + "/";
    auto vec = _contextFile[MappingFieldNames];
    for (auto i : vec) {
        std::string tmp2(i);
        tmp2 += _contextFile[MappingFieldExt];
        try {
            InputContext ctx(_inputContextDir, i);
            _contexts.insert({_contextNameConverter[i], ctx});
        }
        catch (const std::runtime_error &err) {
            std::cerr << err.what() << std::endl;
        }
    }
    __changeContext(ContextList::Menu);
}

Inputs::InputContext *Inputs::InputContextManager::getActiveContext()
{
    return _ActiveContext;
}

void Inputs::InputContextManager::receive(const Evt::ChangeInputContext &evt)
{
    __changeContext(evt.ctx);
}

void Inputs::InputContextManager::__changeContext(Inputs::ContextList ctx)
{
    _ActiveContext = &(_contexts.at(ctx));
}

void Inputs::InputContextManager::__subscribeEvent()
{
    auto &evtMgr = Evt::EventManager::getInstance();

    evtMgr.subscribe<Evt::ChangeInputContext>(*this);
}

void Inputs::InputContextManager::compute(Inputs::MappedInput &mi)
{
    _ActiveContext->compute(mi);
}
