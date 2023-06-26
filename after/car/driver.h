#include <vector>
#include <map>
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
    std::string (Driver::*action)(Move);
    template <typename T>
    T getAction(Move m);
    std::vector<std::string> drive(Route route);
    void setCar(Car *car);
    std::string move(Move m);
    std::string start(Move m);
    std::string stop(Move m);
    std::string turn(Move m);
    std::string straight(Move m);
    std::string hi(Move m);
    std::string transform(Move m);
    Driver(std::string name);

private:
    Car *_car;
    std::string _name;
};