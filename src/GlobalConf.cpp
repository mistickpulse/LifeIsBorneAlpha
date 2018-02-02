//
// Created by zouz on 02/02/18.
//

#include "GlobalConf.hpp"

unsigned int Param::ScreenSize_x = 1920;
unsigned int Param::ScreenSize_y = 1080;
std::string Param::AssetRelativPath("../");
std::string Param::AssetDirectory("Asssets/");
std::string Param::AssetsPath;

Param::Param()
{
    AssetsPath = AssetRelativPath + AssetDirectory;
}
