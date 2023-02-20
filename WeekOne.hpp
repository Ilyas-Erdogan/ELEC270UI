#ifndef WEEKONE_HPP
#define WEEKONE_HPP
#include "Week.hpp"
#include <vector>
#include <utility>

class WeekOne : public Week
{
private:
    enum class Type{ Remainder, Divisibility, GCD };
public:
    WeekOne();
    ~WeekOne();
    
    int remainder(const int a, const int m) const;
    bool is_divisible(int a, int b, bool show_text = false) const;
    int integer_c(int a, int b) const;
    int greatest_common_divisor(const int a, const int b, const bool show_process = false, const bool show_explanation = false);
    
    void generate_practice_sheet(const int problem_type, const bool solution_sheet = false, const int number_of_questions = 10) const override;
    
    void remainder_practice_sheet(const std::string problem_type, const bool solution_sheet = false, const int number_of_questions = 10) const;
    void remainder_practice(const std::string problem_type, const std::vector<std::pair<int, int>>& question_set) const;
    void remainder_solutions(const std::string problem_type, const std::vector<std::pair<int, int>>& question_set) const;
    
    void divsibility_practice_sheet(const std::string problem_type, const bool solution_sheet = false, const int number_of_questions = 10) const;
    void divisibility_practice(const std::string problem_type, const std::vector<std::pair<int, int>>& question_set) const;
    void divisibility_solutions(const std::string problem_type, const std::vector<std::pair<int, int>>& question_set) const;
};

#endif // WEEKONE_HPP
