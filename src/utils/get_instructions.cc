
#include "utils/get_instructions.h"

#include <fstream> 
#include <iostream> 

std::vector<uint8_t> Utils::get_instructions(const std::string& file_name)
{
    std::ifstream file(file_name, std::ios::binary);
    if (!file)
    {
        std::cerr << "No program \"" << file_name << "\" found\n";
        std::exit(EXIT_FAILURE);
    }

    std::vector<uint8_t> bytes; 

    uint8_t byte; 
    while (file.read(reinterpret_cast<char*>(&byte), sizeof(byte))) 
    {
        bytes.push_back(byte);
    }
    file.close(); 
    return bytes; 
}

