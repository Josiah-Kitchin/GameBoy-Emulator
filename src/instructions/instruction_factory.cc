

#include "instructions/instruction_factory.h"

using std::make_unique;

const std::unique_ptr<Instruction> InstructionFactory::get_instruction(uint8_t opcode)
{
    switch (opcode)
    {
        case (0x78): 
            return make_unique<LoadRR8>(CPU::Register8::A, CPU::Register8::B);
        case (0x79): 
            return make_unique<LoadRR8>(CPU::Register8::A, CPU::Register8::C);
    }
}