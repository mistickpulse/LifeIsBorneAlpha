//
// Created by zouz on 29/01/18.
//

#ifndef LIFEISBORNE_INTERVAL_HPP
#define LIFEISBORNE_INTERVAL_HPP

template <typename Stockage>
class Interval
{
public:
    friend class RangeConverter;

    Interval() :
        min(0), max(0)
    {}

    Interval(Stockage a, Stockage b) :
        min(a), max(b)
    {}

    bool isReady()
    {
        if (min == max)
            return false;
        return true;
    }

    bool test(Stockage op) const noexcept
    {
        return (min < op) && (op < max);
    }

private:
    Stockage min;
    Stockage max;
};

#endif //LIFEISBORNE_INTERVAL_HPP
