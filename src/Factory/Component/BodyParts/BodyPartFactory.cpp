//
// Created by zouz on 22/11/17.
//

#include "BodyPartFactory.hpp"

BodyPartFactory &BodyPartFactory::getInstance() {
    static BodyPartFactory instance;
    return instance;
}

GraphicalBodyPart *BodyPartFactory::genBodyPart(const std::string &characterName, BodyPartType type) {
    std::string key = genMapKey(type, characterName);

    std::cout << "------------------------------Researching Key[" << key << "]" << std::endl;
    if (_BodyPartModel.find(key) != _BodyPartModel.end()) {
        return new GraphicalBodyPart(*_BodyPartModel[key]);
    }
    std::cout << "[Error]:Can't create Instance of :" << characterName << " type:" << type._to_string() << std::endl;
    return nullptr;
}

void BodyPartFactory::getModelOfType(std::vector<const GraphicalBodyPart *> &toFill, BodyPartType type) {
    if (_BodyPartModelBind.find(type) != _BodyPartModelBind.end()) {
        for (const auto *i : _BodyPartModelBind[type]) {
            toFill.push_back(i);
        }
    }
}

void BodyPartFactory::modelRegister(const std::string &characterName, BodyPartType bodyPart, GraphicalBodyPart &data) {
    std::cout << "=============" << "Registering Model of BodyPart" << std::endl;
    GraphicalBodyPart *ptr = new GraphicalBodyPart(data);

    _BodyPartModel[genMapKey(bodyPart, characterName)] = ptr;
    _BodyPartModelBind[bodyPart].push_back(ptr);
}

const GraphicalBodyPart *BodyPartFactory::getBodyModel(BodyPartType bodyPart, const std::string &CharacterName) {
    std::string MapKey(CharacterName);
    MapKey += ":";
    MapKey += bodyPart._to_string();

    if (_BodyPartModel.find(MapKey) != _BodyPartModel.end()) {
        return _BodyPartModel[MapKey]; //TODO to change
    }
    return nullptr;
}

std::string BodyPartFactory::genMapKey(BodyPartType bodyPart, const std::string &CharacterName) {
    std::string key(CharacterName);
    key += "::";
    key += bodyPart._to_string();
    return key;
}

BodyPartFactory::~BodyPartFactory() {
    for (const auto &i : _BodyPartModelBind) {
        for (const auto *ptr : i.second) {
            delete ptr;
        }
    }
    _BodyPartModelBind.clear();
    _BodyPartModel.clear();
}
