
/*
    Gameboy Emulater
*/

#include <iostream> 
#include "utils/get_instructions.h"

int main()
{
    std::vector<uint8_t> instruction_bytes = Utils::get_instructions("file");
    

    return 0; 
}