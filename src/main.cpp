#include <iostream>

#include "rent/customer.h"

int main()
{
    Customer c("小王");
    Movie rm("<<寻龙诀>>", Movie::category::REGULAR);
    Movie nm("<<闪电侠>>", Movie::category::NEW);
    Movie cm("<<冰雪奇缘>>", Movie::category::CHILDENS);

    Rental rrm(rm, 5);
    Rental rnm(nm, 8);
    Rental rcm(cm, 2);

    c.addRental(rrm);
    c.addRental(rnm);
    c.addRental(rcm);

    std::cout << c.statement() << std::endl;
    return 0;
}