//
// Created by zouz on 28/01/18.
//

#ifndef LIFEISBORNE_SINGLETON_HPP
#define LIFEISBORNE_SINGLETON_HPP

template <typename T>
class Singleton
{
public:
    ~Singleton() = default;

    static T &getInstance()
    {
        static T inst;
        return inst;
    }
};

#endif //LIFEISBORNE_SINGLETON_HPP
