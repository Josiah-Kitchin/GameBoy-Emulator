
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
    /* ------------------------------- 8 BIT LOADS --------------------------------*/

    { 0x3E, [] { return make_unique<LoadR8V>(Register8::A); } },
    { 0x06, [] { return make_unique<LoadR8V>(Register8::B); } },
    { 0x0E, [] { return make_unique<LoadR8V>(Register8::C); } },
    { 0x16, [] { return make_unique<LoadR8V>(Register8::D); } },
    { 0x1E, [] { return make_unique<LoadR8V>(Register8::E); } },
    { 0x26, [] { return make_unique<LoadR8V>(Register8::H); } },
    { 0x2E, [] { return make_unique<LoadR8V>(Register8::L); } },

    { 0x7F, [] { return make_unique<LoadRR8>(Register8::A, Register8::A); } },
    { 0x78, [] { return make_unique<LoadRR8>(Register8::A, Register8::B); } },
    { 0x79, [] { return make_unique<LoadRR8>(Register8::A, Register8::C); } },
    { 0x7A, [] { return make_unique<LoadRR8>(Register8::A, Register8::D); } },
    { 0x7B, [] { return make_unique<LoadRR8>(Register8::A, Register8::E); } },
    { 0x7C, [] { return make_unique<LoadRR8>(Register8::A, Register8::H); } },
    { 0x7D, [] { return make_unique<LoadRR8>(Register8::A, Register8::L); } },
    { 0x7E, [] { return make_unique<LoadR8Pointer>(Register8::A, Register16::HL); } },
    { 0x0A, [] { return make_unique<LoadR8Pointer>(Register8::A, Register16::BC); } },
    { 0x1A, [] { return make_unique<LoadR8Pointer>(Register8::A, Register16::DE); } },
    { 0xFA, [] { return make_unique<LoadR8PointerV>(Register8::A); } },

    { 0x40, [] { return make_unique<LoadRR8>(Register8::B, Register8::B); } },
    { 0x41, [] { return make_unique<LoadRR8>(Register8::B, Register8::C); } },
    { 0x42, [] { return make_unique<LoadRR8>(Register8::B, Register8::D); } },
    { 0x43, [] { return make_unique<LoadRR8>(Register8::B, Register8::E); } },
    { 0x44, [] { return make_unique<LoadRR8>(Register8::B, Register8::H); } },
    { 0x45, [] { return make_unique<LoadRR8>(Register8::B, Register8::L); } },
    { 0x46, [] { return make_unique<LoadR8Pointer>(Register8::B, Register16::HL); } },
    { 0x47, [] { return make_unique<LoadRR8>(Register8::B, Register8::A); } },

    { 0x48, [] { return make_unique<LoadRR8>(Register8::C, Register8::B); } },
    { 0x49, [] { return make_unique<LoadRR8>(Register8::C, Register8::C); } },
    { 0x4A, [] { return make_unique<LoadRR8>(Register8::C, Register8::D); } },
    { 0x4B, [] { return make_unique<LoadRR8>(Register8::C, Register8::E); } },
    { 0x4C, [] { return make_unique<LoadRR8>(Register8::C, Register8::H); } },
    { 0x4D, [] { return make_unique<LoadRR8>(Register8::C, Register8::L); } },
    { 0x4E, [] { return make_unique<LoadR8Pointer>(Register8::C, Register16::HL); } },
    { 0x4F, [] { return make_unique<LoadRR8>(Register8::C, Register8::A); } },

    { 0x50, [] { return make_unique<LoadRR8>(Register8::D, Register8::B); } },
    { 0x51, [] { return make_unique<LoadRR8>(Register8::D, Register8::C); } },
    { 0x52, [] { return make_unique<LoadRR8>(Register8::D, Register8::D); } },
    { 0x53, [] { return make_unique<LoadRR8>(Register8::D, Register8::E); } },
    { 0x54, [] { return make_unique<LoadRR8>(Register8::D, Register8::H); } },
    { 0x55, [] { return make_unique<LoadRR8>(Register8::D, Register8::L); } },
    { 0x56, [] { return make_unique<LoadR8Pointer>(Register8::D, Register16::HL); } },
    { 0x57, [] { return make_unique<LoadRR8>(Register8::D, Register8::A); } },

    { 0x58, [] { return make_unique<LoadRR8>(Register8::E, Register8::B); } },
    { 0x59, [] { return make_unique<LoadRR8>(Register8::E, Register8::C); } },
    { 0x5A, [] { return make_unique<LoadRR8>(Register8::E, Register8::D); } },
    { 0x5B, [] { return make_unique<LoadRR8>(Register8::E, Register8::E); } },
    { 0x5C, [] { return make_unique<LoadRR8>(Register8::E, Register8::H); } },
    { 0x5D, [] { return make_unique<LoadRR8>(Register8::E, Register8::L); } },
    { 0x5E, [] { return make_unique<LoadR8Pointer>(Register8::E, Register16::HL); } },
    { 0x5F, [] { return make_unique<LoadRR8>(Register8::E, Register8::A); } },

    { 0x60, [] { return make_unique<LoadRR8>(Register8::H, Register8::B); } },
    { 0x61, [] { return make_unique<LoadRR8>(Register8::H, Register8::C); } },
    { 0x62, [] { return make_unique<LoadRR8>(Register8::H, Register8::D); } },
    { 0x63, [] { return make_unique<LoadRR8>(Register8::H, Register8::E); } },
    { 0x64, [] { return make_unique<LoadRR8>(Register8::H, Register8::H); } },
    { 0x65, [] { return make_unique<LoadRR8>(Register8::H, Register8::L); } },
    { 0x66, [] { return make_unique<LoadR8Pointer>(Register8::H, Register16::HL); } },
    { 0x67, [] { return make_unique<LoadRR8>(Register8::H, Register8::A); } },

    { 0x68, [] { return make_unique<LoadRR8>(Register8::L, Register8::B); } },
    { 0x69, [] { return make_unique<LoadRR8>(Register8::L, Register8::C); } },
    { 0x6A, [] { return make_unique<LoadRR8>(Register8::L, Register8::D); } },
    { 0x6B, [] { return make_unique<LoadRR8>(Register8::L, Register8::E); } },
    { 0x6C, [] { return make_unique<LoadRR8>(Register8::L, Register8::H); } },
    { 0x6D, [] { return make_unique<LoadRR8>(Register8::L, Register8::L); } },
    { 0x6E, [] { return make_unique<LoadR8Pointer>(Register8::L, Register16::HL); } },
    { 0x6F, [] { return make_unique<LoadRR8>(Register8::L, Register8::A); } },

    { 0x70, [] { return make_unique<LoadPointerR8>(Register16::HL, Register8::B); } },
    { 0x71, [] { return make_unique<LoadPointerR8>(Register16::HL, Register8::C); } },
    { 0x72, [] { return make_unique<LoadPointerR8>(Register16::HL, Register8::D); } },
    { 0x73, [] { return make_unique<LoadPointerR8>(Register16::HL, Register8::E); } },
    { 0x74, [] { return make_unique<LoadPointerR8>(Register16::HL, Register8::H); } },
    { 0x75, [] { return make_unique<LoadPointerR8>(Register16::HL, Register8::L); } },

    { 0x36, [] { return make_unique<LoadPointerV>(Register16::HL); } },

    { 0x02, [] { return make_unique<LoadPointerR8>(Register16::BC, Register8::A); } },
    { 0x12, [] { return make_unique<LoadPointerR8>(Register16::DE, Register8::A); } },
    { 0x77, [] { return make_unique<LoadPointerR8>(Register16::HL, Register8::A); } },
    { 0xEA, [] { return make_unique<LoadPointerVR8>(Register8::A); } },

    /* --------------------------------------------------------------------------------- */
    

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
    instr->fetch_data(m_pc, bus.memory);

    return instr; 
}
