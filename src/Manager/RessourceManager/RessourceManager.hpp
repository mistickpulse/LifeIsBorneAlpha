//
// Created by zouz on 12/01/18.
//

#ifndef LIFEISBORNE_RESSOURCEMANAGER_HPP
#define LIFEISBORNE_RESSOURCEMANAGER_HPP

#include <string>
#include <unordered_map>
#include <vector>
#include <memory>

template <typename Key, typename Obj>
class RessourceManager
{
public:
    RessourceManager() = default;
    ~RessourceManager() = default;

public:

    void clear()
    {
        _ressources.clear();
    }

    template <typename ... Args>
    void add(const Key &key, Args &&... arguments)
    {
        Obj toStore(std::forward<Args>(arguments) ...);
        _ressources.emplace({key, std::move(toStore)});
    }

    Obj &get(const Key &id)
    {
        return _ressources.at(id);
    }

    Obj &operator[](const Key &id)
    {
        return get(id);
    }

private:
    std::unordered_map<Key, Obj> _ressources;
};

template <typename Key>
class RessourceManager<Key, sf::Texture>
{
public:
    RessourceManager() = default;
    ~RessourceManager() = default;

public:

    void clear()
    {
        _ressources.clear();
    }

    template <typename ... Args>
    void add(const Key &key, Args &&... arguments)
    {
        sf::Texture toStore;
        if (toStore.loadFromFile(std::forward<Args>(arguments) ...)) {
            _ressources.insert({key, std::move(toStore)});
        }
    }

    sf::Texture &get(Key val)
    {
        return _ressources.at(val);
    }

    sf::Texture &operator[](const Key &id)
    {
        return get(id);
    }

private:
    std::unordered_map<Key, sf::Texture> _ressources;
};

template <typename Key>
class RessourceManager<Key, sf::Sprite>
{
public:
    RessourceManager() = default;
    ~RessourceManager() = default;

public:

    void clear()
    {
        _ressources.clear();
    }

    template <typename ... Args>
    void add(const Key &key, Args &&... arguments)
    {
        sf::Sprite toStore;
        toStore.setTexture(std::forward<Args>(arguments) ...);
        _ressources.insert({key, std::move(toStore)});
    }

    sf::Sprite &get(const Key &id)
    {
        return _ressources.at(id);
    }

    sf::Sprite &operator[](const Key &id)
    {
        return get(id);
    }

private:
    std::unordered_map<Key, sf::Sprite> _ressources;
};


#endif //LIFEISBORNE_RESSOURCEMANAGER_HPP
