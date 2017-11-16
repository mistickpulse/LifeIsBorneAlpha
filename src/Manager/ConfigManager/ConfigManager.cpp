//
// Created by zouz on 16/11/17.
//

#include "ConfigManager.hpp"

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
    std::cout << "Searching Configuration Files:" << std::endl;
    _loadAllConfigFilePaths(_configPath, _extension);
}

void ConfigManager::reload(const std::string &path) {
    _collectedFilePaths.clear();
    _FileConfigPaths.clear();
    _loadAllConfigFilePaths(path, _extension);
}

void ConfigManager::_indexFiles(const std::string &fileToIndex) {
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
