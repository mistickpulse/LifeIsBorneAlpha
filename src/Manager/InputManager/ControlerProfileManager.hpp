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
#include "../../utils/Singleton.hpp"

namespace Inputs
{
    using ControlerProfile = std::array<std::pair<InputType, ControlProfile>, 2>;
    using ProfileBind = std::unordered_map<InputMode, ControlProfile>;
    using ProfileMap = std::unordered_map<std::string, ProfileBind>;
    using json = nlohmann::json;

    namespace
    {

        const std::string JsonMainKey = "ControllerInputMode";


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

        const ControlProfile &getProfile(const std::string &profileName, InputMode mode) const
        {
            (void)profileName;
            (void)mode;
        }

        const ProfileMap &getProfiles() const
        {
            return _profiles;
        }

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

            auto &VecStr = profileData[JsonMainKey];
            for (const auto &i : VecStr) {
                __loadMode(profileName, i, profileData);
            }
        }

    private:
        void __loadGameControls(const json &profileControls, const std::string &profileName, const std::string &label)
        {
            auto &ref = _profiles.at(profileName);
            //TODO
        }

        void __loadMenuControls(const std::string &profileName, const std::string &label)
        {
            //TODO
        }

        void __loadMode(const std::string &ProfileName, const std::string &label, const json &profile)
        {
            InputMode mode;
            mode = (label == "GAME") ? InputMode::GAME : InputMode::MENU;
            json profileControls = profile[InputLabel.at(mode)];

            switch (mode) {
                case InputMode::GAME:
                    __loadGameControls(profileControls, ProfileName, label);
                    break;
                case InputMode::MENU:
                    //__loadMenuControls(profileControls, ProfileName, label);
                    break;
                default:
                    break;
            }
        }


    private:

        ProfileMap _profiles;
    };
}

#endif //LIFEISBORNE_CONTROLERPROFILEMANAGER_HPP
