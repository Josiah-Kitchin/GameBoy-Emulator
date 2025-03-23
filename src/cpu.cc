

#include "cpu.h"
#include "instructions/instruction.h"

void CPU::execute(const Instruction& instruction)
/*
    Dynamic dispatch of instructions, each instruction modifies the state
    of the CPU 
*/
{
    instruction.execute(*this);
}

uint16_t CPU::Registers::af() { return (a << 8) | f; }

uint16_t CPU::Registers::bc() { return (b << 8) | c; }

uint16_t CPU::Registers::de() { return (d << 8) | e; }

uint16_t CPU::Registers::hl() { return (h << 8) | l; }


