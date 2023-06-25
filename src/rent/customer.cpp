#include "customer.h"

Customer::Customer(std::string name)
{
    _name = name;
}

void Customer::addRental(Rental rental)
{
    _rentals.emplace_back(rental);
}

std::string Customer::statement()
{
    float total = 0;
    int points = 0;
    std::string result = _name + "的租赁账单:\n";

    for (Rental rental : _rentals)
    {
        float itemPrice = 0;
        switch (rental.movie().cate())
        {
        case Movie::category::REGULAR:
            itemPrice += 2;
            if (rental.rentalDays() > 2)
            {
                itemPrice += (rental.rentalDays() - 2) * 1.5;
            }
            break;
        case Movie::category::NEW:
            itemPrice += rental.rentalDays() * 3;
            break;
        case Movie::category::CHILDENS:
            itemPrice += 1.5;
            if (rental.rentalDays() > 3)
            {
                itemPrice += (rental.rentalDays() - 3) * 1.5;
            }
            break;
        default:
            break;
        }

        points++;
        if (rental.movie().cate() == Movie::category::NEW && rental.rentalDays() > 1)
        {
            points++;
        }

        result += "\t" + rental.movie().title() + ": " + std::to_string(itemPrice) + "\n";
        total += itemPrice;
    }

    result += "总金额: " + std::to_string(total) + "\n";
    result += "你本次借出获取的积分为: " + std::to_string(points) + "\n";
    return result;
}