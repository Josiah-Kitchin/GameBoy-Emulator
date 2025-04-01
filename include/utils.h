
#pragma once

#include <vector> 
#include <string> 
#include <cstdint> 

namespace Utils
{
    /// @brief Load an instruction binary file into a vector 
    /// @param file Name of the file 
    /// @return A vector seperating the file into bytes
    std::vector<uint8_t> get_program_bytes(const std::string& file);
}
