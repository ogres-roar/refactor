#include <string>

enum CarType
{
    none,
    bmw,
    audi,
    benz
};

class BMW
{
public:
    std::string start();
    std::string stop();
    std::string right();
    std::string left();
    std::string straight(int distance);
    std::string hiBMW();
};

class Audi
{
public:
    std::string start();
    std::string stop();
    std::string right();
    std::string straight(int distance);
    std::string left();
};

class Benz
{
public:
    std::string start();
    std::string stop();
    std::string right();
    std::string left();
    std::string straight(int distance);
    std::string transform();
};