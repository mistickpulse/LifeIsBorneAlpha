//
// Created by zouz on 29/01/18.
//

#ifndef LIFEISBORNE_CONTROLERPROFILEMANAGER_HPP
#define LIFEISBORNE_CONTROLERPROFILEMANAGER_HPP

#include <unordered_map>
#include <fstream>
#include "InputMode.hpp"
#include "ControlProfile.hpp"
#include "../../../Submodules/json/src/json.hpp"

namespace Inputs
{
    using json = nlohmann::json;

    namespace
    {
        std::string RelativPath("../");
        const std::string Path(RelativPath + "./Confs/Controls/");
        const std::string DefaultProfil("Default");
        const std::string Extension(".json");
    }

    class ControlerProfilManager
    {
    public:
        ControlerProfilManager() = default;
        ~ControlerProfilManager() = default;

        ControlProfile &getProfile(const std::string &profileName, InputMode mode);

        void loadProfile(const std::string &profileName)
        {
            std::string finalPath;
            if (profileName.find(Extension, profileName.size() - Extension.size()) != std::string::npos) {
                finalPath = RelativPath + Path + profileName;
            } else
                finalPath = RelativPath + Path + profileName + Extension;
            std::ifstream profileFile(finalPath);

            json profileData;
            profileFile >> profileData;
            //Need to accept Json shit
        }

    private:
        using ProfilBind = std::array<std::pair<InputMode, ControlProfile>, 2>;
        std::unordered_map<std::string, ProfilBind> _profiles;
    };
}

#endif //LIFEISBORNE_CONTROLERPROFILEMANAGER_HPP
