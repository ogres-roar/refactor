#include "rental.h"

Rental::Rental(Movie movie, int rentalDays)
{
    _movie = movie;
    _rentalDays = rentalDays;
}

Movie Rental::movie()
{
    return _movie;
}

int Rental::rentalDays()
{
    return _rentalDays;
}