#ifndef WEEKTWO_HPP
#define WEEKTWO_HPP
#include "Week.hpp"
#include <iostream>
class WeekTwo : public Week
{
private:
    enum class Type{ Bezout, Inverse };
public:
    WeekTwo();
    ~WeekTwo();
    
    std::pair<int, int> extended_eculidean_algorithm(const int num1 ,const int num2) const;
    
    void generate_practice_sheet(const int problem_type, const bool solution_sheet = false, const int number_of_questions = 10) const override;
    
    void inverse_practice_sheet(const std::string problem_type, const bool solution_sheet = false, const int number_of_questions = 10) const;
    void inverse_practice(const std::string problem_type, const std::vector<std::pair<int, int>>& question_set) const;
    void inverse_solutions(const std::string problem_type, const std::vector<std::pair<int, int>>& question_set) const;
    
    void bezout_practice_sheet(const std::string problem_type, const bool solution_sheet = false, const int number_of_questions = 10) const;
    void bezout_practice(const std::string problem_type, const std::vector<std::pair<int, int>>& question_set) const;
    void bezout_solutions(const std::string problem_type, const std::vector<std::pair<int, int>>& question_set) const;
    
};

#endif // WEEKTWO_HPP
