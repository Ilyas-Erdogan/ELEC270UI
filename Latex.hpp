#include <string>
class Latex {
public:
    // Constructors
    Latex();
    ~Latex();
    
    // Methods
    void create_empty_file(const std::string file_name) const;
    void generate_pdf_file(const std::string file_name) const;
    void open_pdf_file(const std::string file_name) const;
    void initialize_file(const std::string file_name) const;
    std::string reformat_title(std::string file_name) const;
    void write_to_file(const std::string file_name, const std::string content) const;
    void finalize_file(const std::string file_name) const;
    void setup(const std::string file_name) const;
};