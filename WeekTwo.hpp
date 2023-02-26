#ifndef WEEKTWO_HPP
#define WEEKTWO_HPP
#include "Week.hpp"

class WeekTwo : public Week
{
private:
    enum class Type{ Inverse };
public:
    WeekTwo();
    ~WeekTwo();
    
    void generate_practice_sheet(const int problem_type, const bool solution_sheet = false, const int number_of_questions = 10) const override;
    
    void inverse_practice_sheet(const std::string problem_type, const bool solution_sheet = false, const int number_of_questions = 10) const;
    void inverse_practice(const std::string problem_type, const std::vector<std::pair<int, int>>& question_set) const;
    void inverse_solutions(const std::string problem_type, const std::vector<std::pair<int, int>>& question_set) const;
};

#endif // WEEKTWO_HPP
