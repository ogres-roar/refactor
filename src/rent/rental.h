#include "movie.h"

class Rental
{
public:
    Rental(Movie movie, int rentalDays);
    Movie movie();
    int rentalDays();

private:
    Movie _movie;
    int _rentalDays;
};