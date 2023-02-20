#include "WeekOne.hpp"
#include <iostream>
#include <sstream>
#include <random>

WeekOne::WeekOne() : Week("Week_One")
{
}

WeekOne::~WeekOne()
{
}

int WeekOne::remainder(const int a, const int m) const
{
    return a % m;
}

bool WeekOne::is_divisible(int a, int b, bool show_text) const {
    /*Checks if a | b*/
    if (b % a == 0) {
        return true;
    }
    return false;
}

int WeekOne::integer_c(const int a, const int b) const
{
    return b / a;
}

int WeekOne::greatest_common_divisor(const int a, const int b, const bool show_process, const bool show_explanation) {
    /*
    Finds greatest commond divisor between two numbers.
    If one or more paramters do not meet requirements, return -1
    */

    int r {0}, x{0}, y{0};

    if (show_explanation)
    {
        std::cout << "Let a, b \u2208 \u2124 with a \u2260 0, b \u2260 0.\n";
        std::cout << "You chose: " << "a = " << a << ", b = " << b << "\n";
    }

    if (!(a == 0 && b == 0))
    {
        if (show_explanation)
        {
            std::cout << "We will find the greatests common denominator using the Euclidean Algorithm.\n";
        }
        x = a;
        y = b;

        if (show_process)
        {
            std::cout << "Division Algorithm:\n";
        }
        while(y != 0) {
            r = remainder(x,y);
            if (show_process)
            {
                if (x != 0)
                {
                    if (r != 0)
                    {
                        std::cout << x << " = " << y << " \u22c5 " << (x/y) << " + " << r << "\n";
                    } else {
                        std::cout << x << " = " << y << " \u22c5 " << (x/y) << "\n";
                    }
                    
                }
            }
            x = y;
            y = r;
        }
        if (show_explanation)
        {
            std::cout << "gcd(" << a << ", " << b << ") = " << x << ".\n";
        }
        return x;
    } 
    else
    {
        if(show_explanation)
        {
            std::cout << "Something went wrong, please see below:\n";
            std::cout << ((a == 0 && b == 0) ? "Integers a and b cannot BOTH be zero!\n" : "");
        }
        return -1;
    }
}

void WeekOne::generate_practice_sheet(const int problem_type, const bool solution_sheet, const int number_of_questions) const
{
    /**
     * @brief   Initiates the creation of a practice sheet according to the requested problem type
     * @param   problem_type:   type of problem for practice/solution sheet
     * @param   solution_sheet: specify whether the user would lie 
     * @param   number_of_questions:    number of questions requested by the user
    */
    Type t = static_cast<Type>(problem_type);
    switch (t)
    {
        case Type::Remainder:
            remainder_practice_sheet("Remainder", solution_sheet, number_of_questions);
            break;
        case Type::Divisibility:
            divsibility_practice_sheet("Divisibility", solution_sheet, number_of_questions);
            break;
        case Type::GCD:
            //gcd_practice_sheet("GCD", solution_sheet);
            break;
        default:
            break;
    }
}

void WeekOne::remainder_practice_sheet(const std::string problem_type, const bool solution_sheet, const int number_of_questions) const
{
    /**
     * @brief   Creates requested set of number sets and calls functions for practice and solution pdf generation
     * Sheet Type:  Remainder
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
    remainder_practice(problem_type, number_set);
    
    // Create solution sheet with same set of numbers upon request
    if (solution_sheet)
    {
        remainder_solutions(problem_type, number_set);
    }
}

void WeekOne::remainder_practice(const std::string problem_type, const std::vector<std::pair<int, int>>& question_set) const
{
    /**
     * @brief   Appends appropriate text for practice sheet and generates PDF upon completion
     * Practice Type:   Remainder
     * @param   problem_type:   requested problem type for generation (used for title)
     * @param   question_set:   set of numbers used to create questions
    */
    
    // Setup output stream for tex file
    std::stringstream to_file;
    
    // Initializes name for tex and pdf file and sets them up
    std::string file_name = get_week_name() + "_" + problem_type + "_Practice";
    setup(file_name);
    
    // Begin tex file appendages
    write_to_file(file_name, "Find the remainder for the following questions:");
    write_to_file(file_name, "\\begin{enumerate}\n");
    
    for (const auto &i : question_set)
    {
        to_file << "\\item " << i.first << " mod " << i.second << "\n";
    }
    
    write_to_file(file_name, to_file.str());
    
    // Complete tex file
    write_to_file(file_name, "\\end{enumerate}\n");
    finalize_file(file_name);
    
    generate_pdf_file(file_name);
    open_pdf_file(file_name);
}

void WeekOne::remainder_solutions(const std::string problem_type, const std::vector<std::pair<int, int>>& question_set) const
{
    /**
     * @brief   Appends appropriate text for solution sheet and generates PDF upon completion
     * Solution Type:   Remainder
     * @param   problem_type:   requested problem type for generation (used for title)
     * @param   question_set:   set of numbers used to create answers
    */
     // Setup output stream for tex file
    std::stringstream to_file;
    
    // Initializes name for tex and pdf file and sets them up
    std::string file_name = get_week_name() + "_" + problem_type + "_Solutions";
    setup(file_name);
    
    // Begin tex file appendages
    write_to_file(file_name, "\\begin{enumerate}\n");
    
    for (const auto &i : question_set)
    {
        to_file << "\\item " << remainder(i.first, i.second) << "\n";
    }
    
    write_to_file(file_name, to_file.str());
    
    // Complete tex file
    write_to_file(file_name, "\\end{enumerate}\n");
    finalize_file(file_name);
    
    generate_pdf_file(file_name);
    open_pdf_file(file_name);
}

void WeekOne::divsibility_practice_sheet(const std::string problem_type, const bool solution_sheet, const int number_of_questions) const
{
    /**
     * @brief   Creates requested set of number sets and calls functions for practice and solution pdf generation
     * Sheet Type:  Divisibility
     * @param   problem_type:   requested problem type for generation
     * @param   solution_sheet: flag for requesting a solution sheet (default false)
     * @param   number_of_questions:    number of questions requested by the user
    */
    
    // Setup random number generation
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> large(1,20);
    std::uniform_int_distribution<int> small(500,1000);
    
    // Setup set of nums to be used in practice (and solutions if requested)
    std::vector<std::pair<int,int>> number_set;
    for (int i = 0; i < number_of_questions; i++)
    {
        number_set.emplace_back(std::make_pair(large(gen), small(gen)));
    }
    
    // Create practice sheet
    divisibility_practice(problem_type, number_set);
    
    // Create solution sheet with same set of numbers upon request
    if (solution_sheet)
    {
        divisibility_solutions(problem_type, number_set);
    }

}

void WeekOne::divisibility_practice(const std::string problem_type, const std::vector<std::pair<int, int>>& question_set) const
{
    /**
     * @brief   Appends appropriate text for practice sheet and generates PDF upon completion
     * Practice Type:   Divisibility
     * @param   problem_type:   requested problem type for generation (used for title)
     * @param   question_set:   set of numbers used to create questions
    */
    
    // Setup output stream for tex file
    std::stringstream to_file;
    
    // Initializes name for tex and pdf file and sets them up
    std::string file_name = get_week_name() + "_" + problem_type + "_Practice";
    setup(file_name);
    
    // Begin tex file appendages
    write_to_file(file_name, "Please indicate whether the following statements are True or False:");
    write_to_file(file_name, "\\begin{enumerate}\n");
    
    for (const auto &i : question_set)
    {
        to_file << "\\item " << "\\("<< i.first << " \\mid " << i.second << "\\)"<< "\n";
    }
    
    write_to_file(file_name, to_file.str());
    
    // Complete tex file
    write_to_file(file_name, "\\end{enumerate}\n");
    finalize_file(file_name);
    
    generate_pdf_file(file_name);
    open_pdf_file(file_name);
}
void WeekOne::divisibility_solutions(const std::string problem_type, const std::vector<std::pair<int, int>>& question_set) const
{
    /**
     * @brief   Appends appropriate text for practice sheet and generates PDF upon completion
     * Solution Type:   Divisibility
     * @param   problem_type:   requested problem type for generation (used for title)
     * @param   question_set:   set of numbers used to create questions
    */
    
    // Setup output stream for tex file
    std::stringstream to_file;
    
    // Initializes name for tex and pdf file and sets them up
    std::string file_name = get_week_name() + "_" + problem_type + "_Solutions";
    setup(file_name);
    
    // Begin tex file appendages
    write_to_file(file_name, "\\begin{enumerate}\n");
    
    for (const auto &i : question_set)
    {
        to_file << "\\item ";
        const bool check_condition = is_divisible(i.first, i.second, false);
        (check_condition) ? (to_file << " True \\\\") : (to_file << " False \\\\");
        to_file << "Let $a, b \\in \\mathbb{Z}$ where $a = " << i.first << ", b = " << i.second << "$.\\\\ ";
        to_file << "$a \\mid b$ if and only if $\\exists$ an integer such that $ac=b$.\\\\";
        (check_condition) ? (to_file << "Since $\\exists$ an integer $c = " <<  integer_c(i.first, i.second) << "$, ") : (to_file << "There is no integer c that meets the conditions.");
        (check_condition) ? (to_file << i.first << "$\\mid$" << i.second << "\n") : (to_file << "\n");
        write_to_file(file_name, to_file.str());
        // Clear string to avoid large string size
        to_file.str(std::string());
    }
    
    // Complete tex file
    write_to_file(file_name, "\\end{enumerate}\n");
    finalize_file(file_name);
    
    generate_pdf_file(file_name);
    open_pdf_file(file_name);
}