//
// Created by zouz on 02/02/18.
//

#include <fstream>
#include "InputContext.hpp"

Inputs::InputContext::InputContext(const std::string &DirMapPath, const Inputs::InputContext::InputMapId &MapName) :
    _inputFilePath(""), _rangeConverter(RangeConverter::getInstance()),
    _contxtHelper(BindingContextHelper::getInstance())
{
    //No "/" at the end of the path
    _inputFilePath = DirMapPath + "/" + MapName + ".json";
    __loadMapping();
}

void Inputs::InputContext::__loadMapping()
{
    std::ifstream file(_inputFilePath);

    if (!file.is_open()) {
        std::cerr << "Unable to load file : " << _inputFilePath << std::endl;
        return;
    }
    json fileData;
    file >> fileData;
    fileData = fileData[MAINFIELD];
    auto &&JRawInputController = fileData[CONTROLLER_FIELD];
    auto &&JRawInputKeyboard = fileData[KEYBOARD_FIELD];
    auto &&JRawInputAxis = fileData[AXIS_FIELD];
    auto &&JRawInputSensi = fileData[AXIS_SENSI_FIELD];

    __loadControllerInputs(JRawInputController);
    __loadKeyboardInputs(JRawInputKeyboard);
    __loadAxisInputs(JRawInputAxis);
    __loadAxisSensivity(JRawInputSensi);
}

void Inputs::InputContext::__loadControllerInputs(Inputs::InputContext::json &data)
{
    for (json::iterator i = data.begin(); i != data.end(); ++i) {
        _ControllerButtonMapping.insert({
                                            _contxtHelper.RawInputControllerButtonConverter[i.key()],
                                            _contxtHelper.ActionConverter[i.value()]
                                        });
    }
}

void Inputs::InputContext::__loadKeyboardInputs(Inputs::InputContext::json &data)
{
    for (json::iterator i = data.begin(); i != data.end(); ++i) {
        _KeyboarButtonMapping.insert({
                                         _contxtHelper.rawKeyConverter[i.key()],
                                         _contxtHelper.ActionConverter[i.value()]
                                     });
    }
}

void Inputs::InputContext::__loadAxisInputs(Inputs::InputContext::json &data)
{
    for (json::iterator i = data.begin(); i != data.end(); ++i) {
        _AxisMapping.insert({
                                _contxtHelper.RawInputAxisEnumConverter[i.key()],
                                _contxtHelper.GameRangeConverter[i.value()]
                            });
    }
}

void Inputs::InputContext::__loadAxisSensivity(Inputs::InputContext::json &data)
{
    unsigned char tmp = 0;
    for (json::iterator i = data.begin(); i != data.end(); ++i) {
        if (tmp == 0) {
            _sensivity.x = i.value();
        } else if (tmp == 1) {
            _sensivity.y = i.value();
        }
        ++tmp;
    }
}

void Inputs::InputContext::compute(MappedInput &mi)
{
    if (mi.ControllerId == -1) {
        __computeKeyboard(mi);
    } else {
        __computeController(mi);
    }
}

void Inputs::InputContext::__computeKeyboard(MappedInput &mi)
{
    for (const auto &i : _KeyboarButtonMapping) {
        if (sf::Keyboard::isKeyPressed(i.first)) {
            mi._action.push(i.second);
        }
    }

    RangeConverter &rc = RangeConverter::getInstance();
    for (const auto &i : *mi._axis) {
        GameRange currentRange = _AxisMapping[i];
        RangeConvertedPackage &rangePckge = rc.getRangeConvertedPackage(currentRange);
        rangePckge.mappedInputs = &mi;
        rangePckge.computeRange(rangePckge, mi.ControllerId, i);
    }
}

void Inputs::InputContext::__computeController(MappedInput &mi)
{
    for (const auto &i : _ControllerButtonMapping) {
        if (sf::Joystick::isButtonPressed(mi.ControllerId, i.first)) {
            mi._action.push(i.second);
        }
    }

    RangeConverter &rc = RangeConverter::getInstance();
    for (const auto &i : *mi._axis) {
        GameRange currentRange = _AxisMapping.at(i);
        RangeConvertedPackage &rangePckge = rc.getRangeConvertedPackage(currentRange);
        rangePckge.mappedInputs = &mi;
        rangePckge.computeRange(rangePckge, mi.ControllerId, i);
    }
}

