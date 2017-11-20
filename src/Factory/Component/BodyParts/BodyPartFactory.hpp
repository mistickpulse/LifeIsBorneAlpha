//
// Created by zouz on 16/11/17.
//

#ifndef LIFEISBORNE_BODYPARTFACTORY_HPP
#define LIFEISBORNE_BODYPARTFACTORY_HPP

#include "../../../Components/Graphical/Body/CBody.hpp"

class BodyPartFactory {
public:
    static BodyPartFactory &getInstance() {
        static BodyPartFactory instance;
        return instance;
    }

    ~BodyPartFactory() = default;

public:
    BodyPart &getBodyPiece(BodyPartType bodyPart, const std::string &CharacterName) {
        //Fusion all parameters to get the Correct Sprite vector to build the BodyPart;
    }


private:
    BodyPartFactory() = default;

};

#endif //LIFEISBORNE_BODYPARTFACTORY_HPP
