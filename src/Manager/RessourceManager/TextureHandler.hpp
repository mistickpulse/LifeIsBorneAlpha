//
// Created by zouz on 15/11/17.
//

#ifndef LIFEISBORNE_TEXTUREHANDLER_HPP
#define LIFEISBORNE_TEXTUREHANDLER_HPP

#include <SFML/Graphics/Texture.hpp>

struct TextureInfo {
    TextureInfo(const TextureInfo &src) = default;
};

class TextureHandler {
public:
    TextureHandler(const std::string &TexturePath, const TextureInfo &textureCurrentInfo);
    ~TextureHandler() = default;

private:
    const TextureInfo _textureInfos;
    sf::Texture _texture;
};

#endif //LIFEISBORNE_TEXTUREHANDLER_HPP
