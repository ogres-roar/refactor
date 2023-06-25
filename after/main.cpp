#include <iostream>
#include "car/driver.h"

int main()
{
    Route r = std::vector<Move>{
        {
            .action = Action::start,
        },
        {
            .action = Action::straight,
            .distance = 10,
        },
        {
            .action = Action::stop,
        }};
    Driver li("li");
    auto rt = li.drive(r);
    for (auto show : rt)
    {
        std::cout << show << std::endl;
    }
    li.setAudi(Audi());
    rt = li.drive(r);

    for (auto show : rt)
    {
        std::cout << show << std::endl;
    }
    return 0;
}