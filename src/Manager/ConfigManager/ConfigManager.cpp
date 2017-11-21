//
// Created by zouz on 16/11/17.
//

#include <sstream>
#include "ConfigManager.hpp"
#include "../RessourceManager/RessourceManagerException.hpp"
#include "../RessourceManager/TypeLoaded.hpp"
#include "../RessourceManager/RessourceManager.hpp"

void ConfigManager::_loadAllConfigFilePaths(const std::string &path, const std::string &ext) {
    boost::filesystem::path p(path);
    boost::filesystem::directory_iterator end_;
    for (boost::filesystem::directory_iterator itr(p); itr != end_; ++itr) {
        if (boost::filesystem::is_regular_file(itr->path()) && boost::filesystem::extension(itr->path()) == ext) {
            _indexFiles(itr->path().string());
        } else if (boost::filesystem::is_directory(itr->path())) {
            _loadAllConfigFilePaths(itr->path().string(), ext);
        }
    }
}

ConfigManager::ConfigManager(const std::string &ConfigPath, const std::string &FileExtension) :
        _configPath(ConfigPath), _extension(FileExtension) {
}


void ConfigManager::load() {
    std::cout << "Searching Configuration Files:" << std::endl;
    try {
        _loadAllConfigFilePaths(_configPath, _extension);
        _subload();
    }
    catch (const std::exception &err) {
        std::cerr << err.what() << std::endl;
    }
}

void ConfigManager::reload(const std::string &path) {
    _collectedFilePaths.clear();
    _FileConfigPaths.clear();
    _loadAllConfigFilePaths(path, _extension);
    _subload();
}

void ConfigManager::_indexFiles(const std::string &fileToIndex) {
    //TODO
    // Call the LogManager to tell the state of the research
    std::vector<std::string> ArchitectureDir;
    std::string key;

    boost::filesystem::path tmp(fileToIndex);
    boost::filesystem::path FileName(fileToIndex);
    tmp = tmp.parent_path();
    while (tmp.filename().string() != "json") {
        ArchitectureDir.emplace_back(tmp.filename().string());
        tmp = tmp.parent_path();
    }
    for (auto i = ArchitectureDir.rbegin(); i != ArchitectureDir.rend(); ++i) {
        key += *i;
        key += ":";
    }
    key = key.substr(0, key.size() - 1);
    _FileConfigPaths[key].push_back(fileToIndex);
    std::cout << "  Found:[" << fileToIndex << "]" << std::endl;
}

void ConfigManager::_subload() {
    std::string tmp;
    char buff[256];
    bool found;

    for (const auto &i : _FileConfigPaths) {
        std::stringstream ss;
        ss << i.first;
        ss.getline(buff, 256, ':');
        ss.getline(buff, 256, ':');
        tmp = buff;
        std::cout << "[Loading " << tmp << "]" << std::endl;
        _computeFiles(i.second, tmp);
        std::cout << std::endl;
    }
}

void ConfigManager::_computeFiles(const std::vector<std::string> &files, const std::string &TypeFile) {
    bool found;
    for (const auto &file : files) {
        found = false;

        for (TypeLoaded val : TypeLoaded::_values()) {
            if (TypeFile == val._to_string()) {
                found = true;
                RessourceManager::getInstance().addRessources(file, val);
                break;
            }
        }
        if (found == false) {
            std::cerr << "Fail to load[" << file << "] of Unkowd Type" << TypeFile << std::endl;
            //throw UnknowedRessourceType(i.first);
        }
    }
}

