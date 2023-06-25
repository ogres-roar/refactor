#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "driver.h"

using ::testing::ElementsAreArray;

TEST(driver_test, nocar)
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
            .action = Action::turn,
            .direction = Direction::left,
        },
        {
            .action = Action::straight,
            .distance = 20,
        },
        {
            .action = Action::turn,
            .direction = Direction::right,
        },
        {
            .action = Action::stop,
        }};
    Driver li("li");
    auto rt = li.drive(r);
    EXPECT_THAT(rt, ElementsAreArray({"driver don't kwon how to start!",
                                      "driver don't kwon how to go straight!",
                                      "driver don't kwon how to turn right!",
                                      "driver don't kwon how to go straight!",
                                      "driver don't kwon how to turn left!",
                                      "driver don't kwon how to stop!"}));
}

TEST(driver_test, bmw)
{
}

TEST(driver_test, benz)
{
}

TEST(driver_test, audi)
{
}