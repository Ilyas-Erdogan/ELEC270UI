#ifndef WEEK_HPP
#define WEEK_HPP
#include "Latex.hpp"
#include <string>

class Week : public Latex
{
private:
    std::string week_name {};
public:
    Week(std::string pweek_name);
    ~Week();
    std::string get_week_name() const;
    virtual void generate_practice_sheet(const int problem_type, const bool solution_sheet = false) const = 0;
};

#endif // WEEK_HPP
