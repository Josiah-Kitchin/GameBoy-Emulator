
#include "cpu.h"
#include "instruction.h"
#include <iostream> 


const Instruction* CPU::fetch_instruction(uint8_t opcode)
{
    Instruction* instr = m_opcode_table[opcode];
    if (instr == nullptr)
    {
        std::cerr << "INVALID OPCODE: EXITING" << std::endl; 
        std::exit(EXIT_FAILURE);
    }
    instr->fetch_data(m_pc, bus.memory);
    return instr; 
}


/// @brief The opcode table holds allocated instructions that 
/// will call execute on the cpu. Instructions dealllocated in CPU deconstructor  
void CPU::init_opcode_table() 
{
    std::fill(m_opcode_table.begin(), m_opcode_table.end(), nullptr); 

    // 8-bit LOAD instructions
    m_opcode_table[0x3E] = new LoadR8V(Register8::A);
    m_opcode_table[0x06] = new LoadR8V(Register8::B);
    m_opcode_table[0x0E] = new LoadR8V(Register8::C);
    m_opcode_table[0x16] = new LoadR8V(Register8::D);
    m_opcode_table[0x1E] = new LoadR8V(Register8::E);
    m_opcode_table[0x26] = new LoadR8V(Register8::H);
    m_opcode_table[0x2E] = new LoadR8V(Register8::L);

    m_opcode_table[0x7F] = new LoadRR8(Register8::A, Register8::A);
    m_opcode_table[0x78] = new LoadRR8(Register8::A, Register8::B);
    m_opcode_table[0x79] = new LoadRR8(Register8::A, Register8::C);
    m_opcode_table[0x7A] = new LoadRR8(Register8::A, Register8::D);
    m_opcode_table[0x7B] = new LoadRR8(Register8::A, Register8::E);
    m_opcode_table[0x7C] = new LoadRR8(Register8::A, Register8::H);
    m_opcode_table[0x7D] = new LoadRR8(Register8::A, Register8::L);
    m_opcode_table[0x7E] = new LoadR8Pointer(Register8::A, Register16::HL);
    m_opcode_table[0x0A] = new LoadR8Pointer(Register8::A, Register16::BC);
    m_opcode_table[0x1A] = new LoadR8Pointer(Register8::A, Register16::DE);
    m_opcode_table[0xFA] = new LoadR8PointerV(Register8::A);

    m_opcode_table[0x40] = new LoadRR8(Register8::B, Register8::B);
    m_opcode_table[0x41] = new LoadRR8(Register8::B, Register8::C);
    m_opcode_table[0x42] = new LoadRR8(Register8::B, Register8::D);
    m_opcode_table[0x43] = new LoadRR8(Register8::B, Register8::E);
    m_opcode_table[0x44] = new LoadRR8(Register8::B, Register8::H);
    m_opcode_table[0x45] = new LoadRR8(Register8::B, Register8::L);
    m_opcode_table[0x46] = new LoadR8Pointer(Register8::B, Register16::HL);
    m_opcode_table[0x47] = new LoadRR8(Register8::B, Register8::A);

    m_opcode_table[0x48] = new LoadRR8(Register8::C, Register8::B);
    m_opcode_table[0x49] = new LoadRR8(Register8::C, Register8::C);
    m_opcode_table[0x4A] = new LoadRR8(Register8::C, Register8::D);
    m_opcode_table[0x4B] = new LoadRR8(Register8::C, Register8::E);
    m_opcode_table[0x4C] = new LoadRR8(Register8::C, Register8::H);
    m_opcode_table[0x4D] = new LoadRR8(Register8::C, Register8::L);
    m_opcode_table[0x4E] = new LoadR8Pointer(Register8::C, Register16::HL);
    m_opcode_table[0x4F] = new LoadRR8(Register8::C, Register8::A);

    m_opcode_table[0x50] = new LoadRR8(Register8::D, Register8::B);
    m_opcode_table[0x51] = new LoadRR8(Register8::D, Register8::C);
    m_opcode_table[0x52] = new LoadRR8(Register8::D, Register8::D);
    m_opcode_table[0x53] = new LoadRR8(Register8::D, Register8::E);
    m_opcode_table[0x54] = new LoadRR8(Register8::D, Register8::H);
    m_opcode_table[0x55] = new LoadRR8(Register8::D, Register8::L);
    m_opcode_table[0x56] = new LoadR8Pointer(Register8::D, Register16::HL);
    m_opcode_table[0x57] = new LoadRR8(Register8::D, Register8::A);

    m_opcode_table[0x58] = new LoadRR8(Register8::E, Register8::B);
    m_opcode_table[0x59] = new LoadRR8(Register8::E, Register8::C);
    m_opcode_table[0x5A] = new LoadRR8(Register8::E, Register8::D);
    m_opcode_table[0x5B] = new LoadRR8(Register8::E, Register8::E);
    m_opcode_table[0x5C] = new LoadRR8(Register8::E, Register8::H);
    m_opcode_table[0x5D] = new LoadRR8(Register8::E, Register8::L);
    m_opcode_table[0x5E] = new LoadR8Pointer(Register8::E, Register16::HL);
    m_opcode_table[0x5F] = new LoadRR8(Register8::E, Register8::A);

    m_opcode_table[0x60] = new LoadRR8(Register8::H, Register8::B);
    m_opcode_table[0x61] = new LoadRR8(Register8::H, Register8::C);
    m_opcode_table[0x62] = new LoadRR8(Register8::H, Register8::D);
    m_opcode_table[0x63] = new LoadRR8(Register8::H, Register8::E);
    m_opcode_table[0x64] = new LoadRR8(Register8::H, Register8::H);
    m_opcode_table[0x65] = new LoadRR8(Register8::H, Register8::L);
    m_opcode_table[0x66] = new LoadR8Pointer(Register8::H, Register16::HL);
    m_opcode_table[0x67] = new LoadRR8(Register8::H, Register8::A);

    m_opcode_table[0x68] = new LoadRR8(Register8::L, Register8::B);
    m_opcode_table[0x69] = new LoadRR8(Register8::L, Register8::C);
    m_opcode_table[0x6A] = new LoadRR8(Register8::L, Register8::D);
    m_opcode_table[0x6B] = new LoadRR8(Register8::L, Register8::E);
    m_opcode_table[0x6C] = new LoadRR8(Register8::L, Register8::H);
    m_opcode_table[0x6D] = new LoadRR8(Register8::L, Register8::L);
    m_opcode_table[0x6E] = new LoadR8Pointer(Register8::L, Register16::HL);
    m_opcode_table[0x6F] = new LoadRR8(Register8::L, Register8::A);

    m_opcode_table[0x70] = new LoadPointerR8(Register16::HL, Register8::B);
    m_opcode_table[0x71] = new LoadPointerR8(Register16::HL, Register8::C);
    m_opcode_table[0x72] = new LoadPointerR8(Register16::HL, Register8::D);
    m_opcode_table[0x73] = new LoadPointerR8(Register16::HL, Register8::E);
    m_opcode_table[0x74] = new LoadPointerR8(Register16::HL, Register8::H);
    m_opcode_table[0x75] = new LoadPointerR8(Register16::HL, Register8::L);

    m_opcode_table[0x36] = new LoadPointerV(Register16::HL);
    m_opcode_table[0x02] = new LoadPointerR8(Register16::BC, Register8::A);
    m_opcode_table[0x12] = new LoadPointerR8(Register16::DE, Register8::A);
    m_opcode_table[0x77] = new LoadPointerR8(Register16::HL, Register8::A);
    m_opcode_table[0xEA] = new LoadPointerVR8(Register8::A);
}


