#include "Week.hpp"

Week::Week(std::string pweek_name) : week_name {pweek_name}
{
}

Week::~Week()
{
}

std::string Week::get_week_name() const
{
    return week_name;
}