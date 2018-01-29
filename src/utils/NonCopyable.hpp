//
// Created by zouz on 29/01/18.
//

#ifndef LIFEISBORNE_NONCOPYABLE_HPP
#define LIFEISBORNE_NONCOPYABLE_HPP

class NonCopyable
{
public:
    NonCopyable() = default;
    virtual ~NonCopyable() = default;
    NonCopyable(const NonCopyable &) = delete;
    NonCopyable &operator=(const NonCopyable &) = delete;
};

#endif //LIFEISBORNE_NONCOPYABLE_HPP
