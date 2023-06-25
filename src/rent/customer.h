#include <string>
#include <vector>

#include "rental.h"

class Customer
{
private:
    std::string _name;
    std::vector<Rental> _rentals = {};

public:
    Customer() = default;
    Customer(std::string name);

    void addRental(Rental rental);
    std::string statement();
};