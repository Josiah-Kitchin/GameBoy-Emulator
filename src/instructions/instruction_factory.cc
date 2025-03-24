

#include "instructions/instruction_factory.h"
#include <iostream> 

using std::unordered_map; 
using std::make_unique;
using std::unique_ptr; 
using std::function; 

static const unordered_map<uint8_t, function<unique_ptr<Instruction>()>> opcode_table = 
{
    { 0x78, [] { return make_unique<LoadRR8>(CPU::Register8::A, CPU::Register8::B); } },
    { 0x79, [] { return make_unique<LoadRR8>(CPU::Register8::A, CPU::Register8::C); } },
};  


const std::unique_ptr<Instruction> InstructionFactory::make_instruction(uint8_t opcode)
{
    auto it = opcode_table.find(opcode);
    if (it == opcode_table.end())
    {
        std::cerr << "Error: Unsupported Opcode " << opcode << std::endl; 
        std::exit(EXIT_FAILURE);
    }
    auto& instr_creator = it->second; 
    return instr_creator(); 
}