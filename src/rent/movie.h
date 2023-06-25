#include <string>
class Movie
{
public:
    // The categorys of movie
    enum category
    {
        CHILDENS,
        NEW,
        REGULAR
    };

    std::string title();
    category cate();

    Movie(std::string title, category cate);
    Movie() = default;

private:
    std::string _title;
    category _cate;
};
