
#include "cpu.h"
#include "instruction.h"
#include <iostream> 
#include <unordered_map> 
#include <memory> 
#include <functional> 

using std::unordered_map; 
using std::make_unique;
using std::unique_ptr; 
using std::function; 

static const unordered_map<uint8_t, function<unique_ptr<Instruction>()>> opcode_table = 
{
    // LoadVR8
    { 0x06, [] { return make_unique<LoadVR8>(Register8::A); } },
    { 0x0E, [] { return make_unique<LoadVR8>(Register8::C); } },
    { 0x16, [] { return make_unique<LoadVR8>(Register8::D); } },
    { 0x1E, [] { return make_unique<LoadVR8>(Register8::E); } },
    { 0x26, [] { return make_unique<LoadVR8>(Register8::H); } },
    { 0x2E, [] { return make_unique<LoadVR8>(Register8::L); } },

    // LoardRR8 
    { 0x7F, [] { return make_unique<LoadRR8>(Register8::A, Register8::A); } },
    { 0x78, [] { return make_unique<LoadRR8>(Register8::A, Register8::B); } },
    { 0x79, [] { return make_unique<LoadRR8>(Register8::A, Register8::C); } },
    { 0x7A, [] { return make_unique<LoadRR8>(Register8::A, Register8::D); } },
    { 0x7B, [] { return make_unique<LoadRR8>(Register8::A, Register8::E); } },
    { 0x7C, [] { return make_unique<LoadRR8>(Register8::A, Register8::H); } },
    { 0x7D, [] { return make_unique<LoadRR8>(Register8::A, Register8::L); } },

    { 0x7E, [] { return make_unique<LoadHLPointerR8>(Register8::A); } },

    { 0x40, [] { return make_unique<LoadRR8>(Register8::B, Register8::B); } },
    { 0x41, [] { return make_unique<LoadRR8>(Register8::B, Register8::C); } },
    { 0x42, [] { return make_unique<LoadRR8>(Register8::B, Register8::D); } },
    { 0x43, [] { return make_unique<LoadRR8>(Register8::B, Register8::E); } },
    { 0x44, [] { return make_unique<LoadRR8>(Register8::B, Register8::H); } },
    { 0x45, [] { return make_unique<LoadRR8>(Register8::B, Register8::L); } },

    { 0x46, [] { return make_unique<LoadHLPointerR8>(Register8::B); } },

    { 0x48, [] { return make_unique<LoadRR8>(Register8::C, Register8::B); } },
    { 0x49, [] { return make_unique<LoadRR8>(Register8::C, Register8::C); } },


};  

const std::unique_ptr<Instruction> CPU::create_instruction(uint8_t opcode)
{
    auto it = opcode_table.find(opcode);
    if (it == opcode_table.end())
    {
        std::cerr << "Error: Unsupported Opcode " << opcode << std::endl; 
        std::exit(EXIT_FAILURE);
    }
    auto& instr_creator = it->second; 
    std::unique_ptr<Instruction> instr = instr_creator(); 
    instr->fetch_data(m_pc, memory);

    return instr; 
}
