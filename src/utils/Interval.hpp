//
// Created by zouz on 29/01/18.
//

#ifndef LIFEISBORNE_INTERVAL_HPP
#define LIFEISBORNE_INTERVAL_HPP

template <typename Stockage>
class Interval
{
public:
    Interval(Stockage a, Stockage b) :
        min(a), max(b)
    {}

    bool test(Stockage op) const noexcept
    {
        return (min < op) && (op < max);
    }

private:
    Stockage min;
    Stockage max;
};

#endif //LIFEISBORNE_INTERVAL_HPP
