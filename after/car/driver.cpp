#include "driver.h"

Driver::Driver(std::string name)
{
    _name = name;
    _car = CarType::none;
}

std::vector<std::string> Driver::drive(Route route)
{
    std::vector<std::string> ret;
    for (Move move : route)
    {
        if (move.action == Action::start)
        {
            if (_car == CarType::audi)
            {
                ret.push_back(_audi.start());
            }
            else if (_car == CarType::benz)
            {
                ret.push_back(_benz.start());
            }
            else if (_car == CarType::bmw)
            {
                ret.push_back(_bmw.start());
            }
            else
            {
                ret.push_back("driver don't kwon how to start!");
            }
        }
        else if (move.action == Action::stop)
        {
            if (_car == CarType::audi)
            {
                ret.push_back(_audi.stop());
            }
            else if (_car == CarType::benz)
            {
                ret.push_back(_benz.stop());
            }
            else if (_car == CarType::bmw)
            {
                ret.push_back(_bmw.stop());
            }
            else
            {
                ret.push_back("driver don't kwon how to stop!");
            }
        }
        else if (move.action == Action::turn)
        {
            if (move.direction == Direction::left)
            {
                if (_car == CarType::audi)
                {
                    ret.push_back(_audi.right());
                }
                else if (_car == CarType::benz)
                {
                    ret.push_back(_benz.right());
                }
                else if (_car == CarType::bmw)
                {
                    ret.push_back(_bmw.right());
                }
                else
                {
                    ret.push_back("driver don't kwon how to turn right!");
                }
            }
            else
            {
                if (_car == CarType::audi)
                {
                    ret.push_back(_audi.left());
                }
                else if (_car == CarType::benz)
                {
                    ret.push_back(_benz.left());
                }
                else if (_car == CarType::bmw)
                {
                    ret.push_back(_bmw.left());
                }
                else
                {
                    ret.push_back("driver don't kwon how to turn left!");
                }
            }
        }
        else if (move.action == Action::straight)
        {
            int distance = move.distance;
            if (_car == CarType::audi)
            {
                ret.push_back(_audi.straight(distance));
            }
            else if (_car == CarType::benz)
            {
                ret.push_back(_benz.straight(distance));
            }
            else if (_car == CarType::bmw)
            {
                ret.push_back(_bmw.straight(distance));
            }
            else
            {
                ret.push_back("driver don't kwon how to go straight!");
            }
        }
        else if (move.action == Action::hi)
        {
            if (_car == CarType::bmw)
            {
                ret.push_back(_bmw.hiBMW());
            }
            else
            {
                ret.push_back("driver don't kwon how to say hi!");
            }
        }
        else if (move.action == Action::transform)
        {
            if (_car == CarType::benz)
            {
                ret.push_back(_benz.transform());
            }
            else
            {
                ret.push_back("driver don't kwon how to transform!");
            }
        }
    }
    return ret;
}
void Driver::setBenz(Benz benz)
{
    _car = CarType::benz;
    _benz = benz;
}
void Driver::setAudi(Audi audi)
{
    _car = CarType::audi;
    _audi = audi;
}
void Driver::setBmw(BMW bmw)
{
    _car = CarType::bmw;
    _bmw = bmw;
}