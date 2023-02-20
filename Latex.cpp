#include "Latex.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

Latex::Latex()
{

}

Latex::~Latex()
{

}

void Latex::create_empty_file(const std::string file_name) const
{
    /**
     * @brief   Creates tex file based on given file name.
     * @param   file_name:  name of file to be created
    */
    std::ofstream outf{file_name + ".tex"};
    if (!outf)
    {
        std::cerr << "ERROR: Could not open " << file_name << ".tex for writing!\n";
    }
}

void Latex::generate_pdf_file(const std::string file_name) const
{   
    /**
     * @brief   Generates pdf file from give tex file
     * @param   file_name:  name of file to be converted
    */
    std::string cmd = "pdflatex " + file_name + ".tex";
    system(cmd.c_str());
    
}

void Latex::open_pdf_file(const std::string file_name) const
{
    /**
     * @brief   Opens specified pdf file
     * @param   file_name:  name of pdf file to be opened
    */
    std::string cmd = "xdg-open " + file_name + ".pdf";
    system(cmd.c_str());
}

void Latex::initialize_file(const std::string file_name) const
{  
    /**
     * @brief   Initializes specified tex document
     * @param   file_name:    name of tex file to be initialized
    */
    std::fstream tex_file;
    tex_file.open(file_name + ".tex", std::ios::out);
    if (!tex_file)
    {
        std::cerr << "The file: "  << file_name << " does not exist!" << std::endl;
    }
    else
    {
        tex_file << "\\documentclass{article}\n";
        tex_file << "\\title{" << reformat_title(file_name) << "}\n";
        tex_file << "\\author{}\n\\date{}\n";
        tex_file << "\\usepackage[utf8]{inputenc}\n\\usepackage{amssymb}\n\\begin{document}\n\\maketitle\n";
        tex_file.close();
    }
}

std::string Latex::reformat_title(std::string file_name) const
{
    std::replace(file_name.begin(), file_name.end(), '_', ' ');
    return file_name;
}

void Latex::write_to_file(const std::string file_name, const std::string content) const
{
    /**
     * @brief   Writes to specified tex file
     * @param   file_name:  name of tex file to be written to
     * @param   content:    to write to tex file
    */
    std::fstream tex_file;
    tex_file.open(file_name + ".tex", std::ios::app);
    if (!tex_file)
    {
        std::cerr << "The file: "  << file_name << " does not exist!" << std::endl;
    }
    else
    {
        tex_file << content;
        tex_file.close();
    }
}

void Latex::finalize_file(const std::string file_name) const
{  
    /**
     * @brief   Finalizes specified tex document
     * @param   file_name:  name of tex file to be finalized
    */
    std::fstream tex_file;
    tex_file.open(file_name + ".tex", std::ios::app);
    if (!tex_file)
    {
        std::cerr << "The file: "  << file_name << " does not exist!" << std::endl;
    }
    else
    {
        tex_file << "\\end{document}\n";
        tex_file.close();
    }
}

void Latex::setup(const std::string file_name) const
{
    /**
     * @brief   Creates and intializes a tex file with specifed.
     * DOES NOT finalize. File must be finalized using finalize_file()
     * @param   file_name:  name of tex file to be setup
    */
    create_empty_file(file_name);
    initialize_file(file_name);
}