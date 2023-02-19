#ifndef WEEKONE_HPP
#define WEEKONE_HPP
#include "Week.hpp"

class WeekOne : public Week
{
private:
    enum class Type{ Remainder, Divisibility, GCD };
public:
    WeekOne();
    ~WeekOne();
    
    int remainder(const int a, const int m);
    bool is_divisible(int a, int b, bool show_text = false);
    int greatest_common_divisor(const int a, const int b, const bool show_process = false, const bool show_explanation = false);
    
    void generate_practice_sheet(const int problem_type, const bool solution_sheet = false) const override;
    void remainder_practice(const std::string problem_type, const bool solution_sheet = false) const;
};

#endif // WEEKONE_HPP
