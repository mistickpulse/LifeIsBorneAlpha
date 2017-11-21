//
// Created by zouz on 16/11/17.
//

#ifndef LIFEISBORNE_CONFIGMANAGER_HPP
#define LIFEISBORNE_CONFIGMANAGER_HPP

#include <string>
#include <vector>
#include <map>
#include <boost/filesystem.hpp>
#include <iostream>

namespace {
    const std::string DefaultConfigPath = "../Ressources/json/";
    const std::string DefaultExtension = ".json";
}

class ConfigManager {
public:
    explicit ConfigManager(const std::string &ConfigPath = DefaultConfigPath,
                           const std::string &FileExtension = DefaultExtension);
    ~ConfigManager() = default;

public:

    void load();
    void reload(const std::string &path = DefaultConfigPath);

private:
    void _subload();
    void _computeFiles(const std::vector<std::string> &files, const std::string &TypeFile);
    void _loadAllConfigFilePaths(const std::string &path, const std::string &ext);
    void _indexFiles(const std::string &fileToIndex);

private:
    const std::string _configPath;
    const std::string _extension;
    std::vector<std::string> _collectedFilePaths;
    std::map<std::string, std::vector<std::string>> _FileConfigPaths{};
};

#endif //LIFEISBORNE_CONFIGMANAGER_HPP
