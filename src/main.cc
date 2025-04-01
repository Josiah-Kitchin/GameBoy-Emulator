
#include "utils.h"
#include "cpu.h"
#include "clock.h"
#include "bus.h"
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
    Bus bus; 
    std::vector<uint8_t> program { 0x06, 7, 0x78 };
    bus.memory.load(program);

    CPU cpu(bus); 

    for (int i = 0; i < 2; i++)
    {
        std::unique_ptr<Instruction> instr = cpu.fetch_and_decode();
        cpu.execute(instr);
    }

    std::cout << int(cpu.get_register(Register8::B)) << std::endl;

    return 0; 
}

