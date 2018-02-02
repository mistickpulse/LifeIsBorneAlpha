//
// Created by zouz on 01/02/18.
//

#ifndef LIFEISBORNE_GLOBALCONF_HPP
#define LIFEISBORNE_GLOBALCONF_HPP

#include <string>

struct Param
{
    Param();
    static unsigned int ScreenSize_x;
    static unsigned int ScreenSize_y;

    static std::string AssetRelativPath;
    static std::string AssetDirectory;

    static std::string AssetsPath;
};

#endif //LIFEISBORNE_GLOBALCONF_HPP
