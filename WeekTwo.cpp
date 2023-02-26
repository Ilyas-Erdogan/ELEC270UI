#include "WeekTwo.hpp"


WeekTwo::WeekTwo() : Week("Week_Two")
{
}

WeekTwo::~WeekTwo()
{
}

void WeekTwo::generate_practice_sheet(const int problem_type, const bool solution_sheet, const int number_of_questions) const
{
    /**
     * @brief   Initiates the creation of a practice sheet according to the requested problem type.
     * @param   problem_type:   type of problem for practice/solution sheet
     * @param   solution_sheet: specify whether the user would lie 
     * @param   number_of_questions:    number of questions requested by the user
    */
    Type t = static_cast<Type>(problem_type);
    switch (t)
    {
        case Type::Inverse:
            inverse_practice_sheet("Inverse", solution_sheet, number_of_questions);
            break;
        default:
            break;
    }
}

void WeekTwo::inverse_practice_sheet(const std::string problem_type, const bool solution_sheet, const int number_of_questions) const
{
    /**
     * @brief   Creates requested set of number sets and calls functions for practice and solution pdf generation
     * Sheet Type:  Inverse (Linear Congruence)
     * @param   problem_type:   requested problem type for generation
     * @param   solution_sheet: flag for requesting a solution sheet (default false)
     * @param   number_of_questions:    number of questions requested by the user
    */
    
    // Setup random number generation
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> large(256,500);
    std::uniform_int_distribution<int> small(1,250);
    
    // Setup set of nums to be used in practice (and solutions if requested)
    std::vector<std::pair<int,int>> number_set;
    for (int i = 0; i < number_of_questions; i++)
    {
        number_set.emplace_back(std::make_pair(large(gen), small(gen)));
    }
    
    // Create practice sheet
    inverse_practice(problem_type, number_set);
    
    // Create solution sheet with same set of numbers upon request
    if (solution_sheet)
    {
       inverse_solutions(problem_type, number_set);
    }
}

void WeekTwo::inverse_practice(const std::string problem_type, const std::vector<std::pair<int, int>>& question_set) const
{
    /**
     * @brief   Appends appropriate text for practice sheet and generates PDF upon completion
     * Practice Type:   Inverse (Linear Congruence)
     * @param   problem_type:   requested problem type for generation (used for title)
     * @param   question_set:   set of numbers used to create questions
    */
    
    // Setup output stream for tex file
    std::stringstream to_file;
    
    // Initializes name for tex and pdf file and sets them up
    std::string file_name = get_week_name() + "_" + problem_type + "_Practice";
    setup(file_name);
    
    // Begin tex file appendages
    write_to_file(file_name, "Find the inverse for the following.\n");
    write_to_file(file_name, "In other words, look for a number $\\overline{a}$ such that \n \\(\\overline{a} \\cdot num1 \\equiv1 (mod \\: num2)\\)\n");
    write_to_file(file_name, "\\begin{enumerate}\n");
    
    for (const auto &i : question_set)
    {
        to_file << "\\item " << i.first << " mod " << i.second << "\n";
        write_to_file(file_name, to_file.str());
        to_file.str(std::string());
    }
    
    // Complete tex file
    write_to_file(file_name, "\\end{enumerate}\n");
    finalize_file(file_name);
    
    generate_pdf_file(file_name);
    open_pdf_file(file_name);
}

void WeekTwo::inverse_solutions(const std::string problem_type, const std::vector<std::pair<int, int>>& question_set) const
{
    
}
