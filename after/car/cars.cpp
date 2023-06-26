#include "cars.h"

std::string Car::name()
{
    return "car";
}
std::string Car::start()
{
    return name() + " start!";
}

std::string Car::stop()
{
    return name() + " stop!";
}

std::string Car::turn(Direction direction)
{
    if (direction == Direction::left)
    {
        return name() + " turn left!";
    }
    return name() + " turn right!";
}

std::string Car::straight(int distance)
{
    return name() + " go straight " + std::to_string(distance);
}

std::string NoCar::name()
{
    return "nocar";
}

std::string NoCar::start()
{
    return "driver don't kwon how to start!";
}

std::string NoCar::stop()
{
    return "driver don't kwon how to stop!";
}

std::string NoCar::turn(Direction direction)
{
    if (direction == Direction::left)
    {
        return "driver don't kwon how to turn left!";
    }
    return "driver don't kwon how to turn right!";
}

std::string NoCar::straight(int distance)
{
    return "driver don't kwon how to go straight!";
}

std::string NoCar::hiBMW()
{
    return "driver don't kwon how to say hi!";
}

std::string NoCar::transform()
{
    return "driver don't kwon how to transform!";
}

std::string BMW::name()
{
    return "bmw";
}
std::string BMW::hiBMW()
{
    return "bmw say hi!";
}

std::string Benz::name()
{
    return "benz";
}

std::string Benz::transform()
{
    return "benz transfrom!";
}

std::string Audi::name()
{
    return "audi";
}