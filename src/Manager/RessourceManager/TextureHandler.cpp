//
// Created by zouz on 15/11/17.
//


#include "TextureHandler.hpp"

TextureHandler::TextureHandler(const std::string &TexturePath, const TextureInfo &textureCurrentInfo): _textureInfos(textureCurrentInfo){
    _texture.loadFromFile(TexturePath);
}
