#include "movie.h"

Movie::Movie(std::string title, Movie::category cate)
{
    _title = title;
    _cate = cate;
}

Movie::category Movie::cate()
{
    return _cate;
}

std::string Movie::title()
{
    return _title;
}