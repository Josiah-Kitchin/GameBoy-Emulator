
#include "instructions/instruction_factory.h"
#include "instructions/instruction.h"
#include "utils.h"
#include "cpu.h"
#include "clock.h"
#include <iostream> 

void usage(int argc)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./gameboy <program>" << std::endl; 
        std::exit(EXIT_FAILURE);
    }
}

int main(int argc, char** argv)
{
    usage(argc);
    std::string program_name = argv[1];
    std::vector<uint8_t> program = Utils::get_program_bytes(program_name); 

    return 0; 
}