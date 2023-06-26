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
            .action = Action::transform,
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
            .action = Action::hi,
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
                                      "driver don't kwon how to transform!",
                                      "driver don't kwon how to turn left!",
                                      "driver don't kwon how to go straight!",
                                      "driver don't kwon how to say hi!",
                                      "driver don't kwon how to turn right!",
                                      "driver don't kwon how to stop!"}));
}

TEST(driver_test, bmw)
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
            .action = Action::transform,
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
            .action = Action::hi,
        },
        {
            .action = Action::turn,
            .direction = Direction::right,
        },
        {
            .action = Action::stop,
        }};
    Driver li("li");
    li.setBmw(BMW());
    auto rt = li.drive(r);
    EXPECT_THAT(rt, ElementsAreArray({"bmw start!",
                                      "bmw go straight 10",
                                      "bmw turn left!",
                                      "bmw go straight 20",
                                      "bmw say hi!",
                                      "bmw turn right!",
                                      "bmw stop!"}));
}

TEST(driver_test, benz)
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
            .action = Action::transform,
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
            .action = Action::hi,
        },
        {
            .action = Action::turn,
            .direction = Direction::right,
        },
        {
            .action = Action::stop,
        }};
    Driver li("li");
    li.setBenz(Benz());
    auto rt = li.drive(r);
    EXPECT_THAT(rt, ElementsAreArray({"benz start!",
                                      "benz go straight 10",
                                      "benz transfrom!",
                                      "benz turn left!",
                                      "benz go straight 20",
                                      "benz turn right!",
                                      "benz stop!"}));
}

TEST(driver_test, audi)
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
            .action = Action::transform,
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
            .action = Action::hi,
        },
        {
            .action = Action::turn,
            .direction = Direction::right,
        },
        {
            .action = Action::stop,
        }};
    Driver li("li");
    li.setAudi(Audi());
    auto rt = li.drive(r);
    EXPECT_THAT(rt, ElementsAreArray({"audi start!",
                                      "audi go straight 10",
                                      "audi turn left!",
                                      "audi go straight 20",
                                      "audi turn right!",
                                      "audi stop!"}));
}