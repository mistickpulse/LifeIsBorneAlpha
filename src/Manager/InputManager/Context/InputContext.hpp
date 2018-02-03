//
// Created by zouz on 02/02/18.
//

#ifndef LIFEISBORNE_INPUTCONTEXT_HPP
#define LIFEISBORNE_INPUTCONTEXT_HPP

#include <string>
#include "../../../GlobalConf.hpp"
#include "../../../../Submodules/json/src/json.hpp"
#include "../RawInputConstant.hpp"
#include "../BindingContextHelper.hpp"
#include "../RangeConverter.hpp"
#include "../MappedInput.hpp"

namespace Inputs
{

    namespace
    {
        const std::string INPUT_DIR = "Inputs";
        const std::string INPUT_MAPPING_DIR = "InputMapping/";
        const std::string MAP_LIST_FILE = "InputMapList.json";

        const std::string MAP_LIST_PATH = Param::AssetsPath + INPUT_MAPPING_DIR + MAP_LIST_FILE;

        const std::string MAPLIST_FIELD_EXTENSION = "Extension";
        const std::string MAPLIST_FIELD_DIR = "Directory";
        const std::string MAPLIST_FIELD_MAPNAMES = "MapsNames";

        const std::string MAINFIELD = "RawInputs";
        const std::string CONTROLLER_FIELD = "RawInputController";
        const std::string KEYBOARD_FIELD = "RawInputKeyboard";
        const std::string AXIS_FIELD = "RawInputAxis";
        const std::string AXIS_SENSI_FIELD = "AxisSensivity";
    }

    struct Sensivity
    {
        unsigned int x;
        unsigned int y;
    };

    class InputContext
    {
        using InputMapId = std::string;
        using json = nlohmann::json;
    public:
        explicit InputContext(const std::string &DirMapPath, const InputMapId &MapName);
        ~InputContext() = default;

        void compute(MappedInput &mi);


    private:
        void __computeKeyboard(MappedInput &mi);
        void __computeController(MappedInput &mi);

        void __loadMapping();

    private:

        void __loadControllerInputs(json &data);
        void __loadKeyboardInputs(json &data);
        void __loadAxisInputs(json &data);
        void __loadAxisSensivity(json &data);

    private:
        InputMapId _inputFilePath;
        RangeConverter &_rangeConverter;
        BindingContextHelper &_contxtHelper;
        json _mainFile;
        std::vector<std::string> _inputMapNames;
        std::string MapsDir;

    private:
        std::unordered_map<RawInputControllerButton, GameAction> _ControllerButtonMapping;
        std::unordered_map<sf::Keyboard::Key, GameAction> _KeyboarButtonMapping;
        std::unordered_map<RawInputAxis, GameRange> _AxisMapping;
        Sensivity _sensivity;
    };
}
#endif //LIFEISBORNE_INPUTCONTEXT_HPP
