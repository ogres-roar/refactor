#include "cars.h"

std::string BMW::start()
{
    return "bmw start!";
}

std::string BMW::stop()
{
    return "bmw stop!";
}

std::string BMW::straight(int distance)
{
    return "bmw go straight " + std::to_string(distance);
}

std::string BMW::right()
{
    return "bmw turn right!";
}

std::string BMW::left()
{
    return "bmw turn left!";
}

std::string BMW::hiBMW()
{
    return "bmw say hi!";
}

std::string Audi::start()
{
    return "audi start!";
}

std::string Audi::stop()
{
    return "audi stop!";
}

std::string Audi::straight(int distance)
{
    return "audi go straight " + std::to_string(distance);
}

std::string Audi::right()
{
    return "audi turn right!";
}

std::string Audi::left()
{
    return "audi turn left!";
}

std::string Benz::start()
{
    return "benz start!";
}

std::string Benz::stop()
{
    return "benz stop!";
}

std::string Benz::straight(int distance)
{
    return "benz go straight " + std::to_string(distance);
}

std::string Benz::right()
{
    return "benz turn right!";
}

std::string Benz::left()
{
    return "benz turn left!";
}

std::string Benz::transform()
{
    return "benz transfrom!";
}