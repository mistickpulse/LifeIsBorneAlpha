//
// Created by zouz on 26/11/17.
//

#include "TestCharacter.hpp"
#include "../Components/Body/CGraphicalBody.hpp"

TestCharacter::TestCharacter() {
    std::vector<std::pair<BodyPartType, std::string>> bodyInfo;
//  bodyInfo.push_back(std::make_pair(BodyPartType::Head, "Boris"));
//  bodyInfo.push_back(std::make_pair(BodyPartType::Arms, "Boris"));
//  bodyInfo.push_back(std::make_pair(BodyPartType::Leggs, "Boris"));
//  bodyInfo.push_back(std::make_pair(BodyPartType::Chest, "Boris"));
    bodyInfo.push_back(std::make_pair(BodyPartType::Hair, "Boris"));
    CGraphicalBody *body = new CGraphicalBody(bodyInfo);
}
