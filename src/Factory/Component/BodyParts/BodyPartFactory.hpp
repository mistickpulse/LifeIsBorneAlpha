//
// Created by zouz on 16/11/17.
//

#ifndef LIFEISBORNE_BODYPARTFACTORY_HPP
#define LIFEISBORNE_BODYPARTFACTORY_HPP

#include <map>
#include <boost/shared_ptr.hpp>
#include <iostream>
#include "../../../Components/Graphical/Body/CBody.hpp"


class BodyPartFactory {
public:
    static BodyPartFactory &getInstance();

    ~BodyPartFactory();

public:

    BodyPart *genBodyPart(const std::string &characterName, BodyPartType type);

    void getModelOfType(std::vector<const BodyPart *> &toFill, BodyPartType type);

    void modelRegister(const std::string &CharacterName, BodyPartType bodypart, BodyPart data);

    const BodyPart *getBodyModel(BodyPartType bodyPart, const std::string &CharacterName);


private:
    BodyPartFactory() = default;

    std::string genMapKey(BodyPartType bodyPart, const std::string &CharacterName);

private:

    std::map<std::string, BodyPart *> _BodyPartModel;
    std::map<BodyPartType, std::vector<BodyPart *>> _BodyPartModelBind;
};

#endif //LIFEISBORNE_BODYPARTFACTORY_HPP
