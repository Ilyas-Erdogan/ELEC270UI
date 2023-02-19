#include "WeekOne.hpp"
#include <iostream>
#include <random>
#include <sstream>

WeekOne::WeekOne() : Week("Week_One")
{
}

WeekOne::~WeekOne()
{
}

int WeekOne::remainder(const int a, const int m)
{
    return a % m;
}

bool WeekOne::is_divisible(int a, int b, bool show_text) {
    /*Checks if a | b*/
    if (show_text)
    {
        std::cout << "Let a,b\u2208\u2124 where a = " << a << ", b = " << b << "\n";
        std::cout << "a\u2223b if and only if \u2203 an integer c such that\n";
        std::cout << "ac=b\n";
    }
    
    if (b % a == 0) {
        if (show_text)
        {
            int c = b / a;
            std::cout << "Since \u2203 an integer c=" << c << ",\n";
            std::cout << a << "\u2223"<< b << ".\n";
        }
        return true;
    }
    if (show_text)
    {
        std::cout << a << "\u2223\u0338" << b << '\n';
    }
    return false;
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

void WeekOne::generate_practice_sheet(const int problem_type, const bool solution_sheet) const
{
    /**
     * @brief   Initiates the creation of a practice sheet according to the requested problem type
     * @param   problem_type:   type of problem for practice/solution sheet
    */
    Type t = static_cast<Type>(problem_type);
    switch (t)
    {
        case Type::Remainder:
            remainder_practice("Remainder", solution_sheet);
            break;
        case Type::Divisibility:
            //divsibility_practice("Divisibility", solution_sheet);
            break;
        case Type::GCD:
            //gcd_practice("GCD", solution_sheet);
            break;
        default:
            break;
    }
}

void WeekOne::remainder_practice(const std::string problem_type, const bool solution_sheet) const {
    /**
     * @brief   Appends appropriate text for latex file and generates PDF upon completion
     * @param   problem_type:   requested problem type for generation
     * @param   solution_sheet: flag for requesting a solution sheet (default false)
    */
    
    // Initializes name for tex and pdf file and sets them up
    std::string file_name = get_week_name() + "_" + problem_type + "_Practice";
    setup(file_name);
    
    // Setup random number generation
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> large(256,500);
    std::uniform_int_distribution<int> small(1,250);
    
    std::stringstream to_file;
    
    // Begin tex file appendages
    write_to_file(file_name, "\\begin{enumerate}\n");
    for (int i = 0; i < 10; i++)
    {
        to_file << "\\item " << large(gen) << " mod " << small(gen) << "\n";
    }
    write_to_file(file_name, to_file.str());
    
    // Complete tex file
    write_to_file(file_name, "\\end{enumerate}\n");
    finalize_file(file_name);
    
    generate_pdf_file(file_name);
    open_pdf_file(file_name);
}