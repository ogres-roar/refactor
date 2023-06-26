#include <typeinfo>
#include <iostream>
#include <exception>

#include "driver.h"
#include "assert.h"

Driver::Driver(std::string name)
{
    _name = name;
    _car = new NoCar();
}

template <typename T>
T Driver::getAction(Move m)
{
    if (m.action == Action::start)
    {
        return &Driver::start;
    }

    if (m.action == Action::stop)
    {
        return &Driver::stop;
    }

    if (m.action == Action::straight)
    {
        return &Driver::straight;
    }

    if (m.action == Action::turn)
    {
        return &Driver::turn;
    }

    if (m.action == Action::hi)
    {
        return &Driver::hi;
    }

    if (m.action == Action::transform)
    {
        return &Driver::transform;
    }

    assert(false);
    return nullptr;
}

std::string Driver::start(Move m)
{
    return _car->start();
}

std::string Driver::stop(Move m)
{
    return _car->stop();
}

std::string Driver::turn(Move m)
{
    return _car->turn(m.direction);
}

std::string Driver::straight(Move m)
{
    return _car->straight(m.distance);
}

std::string Driver::hi(Move m)
{
    if (typeid(*_car) == typeid(NoCar))
    {
        return dynamic_cast<NoCar *>(_car)->hiBMW();
    }
    else if (typeid(*_car) == typeid(BMW))
    {
        return dynamic_cast<BMW *>(_car)->hiBMW();
    }
    throw(std::exception());
    return "";
}

std::string Driver::transform(Move m)
{
    if (typeid(*_car) == typeid(NoCar))
    {
        return dynamic_cast<NoCar *>(_car)->transform();
    }
    else if (typeid(*_car) == typeid(Benz))
    {
        return dynamic_cast<Benz *>(_car)->transform();
    }
    throw(std::exception());
    return "";
}

std::string Driver::move(Move m)
{
    auto next = getAction<decltype(action)>(m);
    return (this->*next)(m);
}

std::vector<std::string> Driver::drive(Route route)
{
    std::vector<std::string> ret;
    for (Move m : route)
    {
        try
        {
            ret.push_back(move(m));
        }
        catch (std::exception &e)
        {
            continue;
        }
    }
    return ret;
}

void Driver::setCar(Car *car)
{
    assert(car != nullptr);
    _car = car;
}
