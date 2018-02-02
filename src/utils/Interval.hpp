//
// Created by zouz on 29/01/18.
//

#ifndef LIFEISBORNE_INTERVAL_HPP
#define LIFEISBORNE_INTERVAL_HPP

template <typename Stockage>
struct Interval
{
public:

    Interval() :
        min(0), max(0)
    {}

    Interval(Stockage a, Stockage b) :
        min(a), max(b)
    {}

    bool isTestValid()
    {
        if (min == max)
            return false;
        return true;
    }

    bool test(Stockage op) const noexcept
    {
        return (min < op) && (op < max);
    }

public:
    Stockage min;
    Stockage max;
};

#endif //LIFEISBORNE_INTERVAL_HPP
