
#pragma once 

#include <vector> 
#include <string> 
#include <cstdint> 

namespace Utils
{
    std::vector<uint8_t> get_instructions(const std::string& file);
}