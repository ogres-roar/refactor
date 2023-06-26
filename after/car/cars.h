#include <string>

enum Direction
{
    right,
    left,
};

enum CarType
{
    none,
    bmw,
    audi,
    benz
};

class Car
{
public:
    virtual std::string name();
    virtual std::string start();
    virtual std::string stop();
    virtual std::string turn(Direction direction);
    virtual std::string straight(int distance);
};

class NoCar : public Car
{
public:
    std::string name();
    std::string hiBMW();
    std::string transform();
    std::string start();
    std::string stop();
    std::string turn(Direction direction);
    std::string straight(int distance);
};

class BMW : public Car
{
public:
    std::string hiBMW();
    std::string name();
};

class Audi : public Car
{
public:
    std::string name();
};

class Benz : public Car
{
public:
    std::string transform();
    std::string name();
};