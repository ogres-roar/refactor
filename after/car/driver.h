#include <vector>

#include "cars.h"

enum Action
{
    start,
    stop,
    turn,
    straight,
    hi,
    transform,
};

enum Direction
{
    right,
    left,
};

struct Move
{
    Action action;
    Direction direction;
    int distance;
};

using Route = std::vector<Move>;

class Driver
{
public:
    std::vector<std::string> drive(Route route);
    void setBenz(Benz benz);
    void setAudi(Audi audi);
    void setBmw(BMW bmz);
    Driver(std::string name);

private:
    CarType _car;
    std::string _name;
    Benz _benz;
    Audi _audi;
    BMW _bmw;
};