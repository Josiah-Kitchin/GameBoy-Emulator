

#include "cpu.h"
#include "instructions/instruction.h"
#include "instructions/instruction_factory.h"

const std::unique_ptr<Instruction> CPU::fetch_and_decode(const std::vector<uint8_t>& instr_bytes)
{
    uint8_t opcode = instr_bytes[m_pc];
    std::unique_ptr<Instruction> instr = InstructionFactory::make_instruction(opcode);
    m_pc += instr->num_instr_bytes; 
    return instr; 
}


void CPU::execute(const std::unique_ptr<Instruction>& instruction)
{
    instruction->execute(*this);
}


uint8_t CPU::get_register8(Register8 reg)
{
    switch (reg)
    {
        case(Register8::A):
            return m_a; 
        case (Register8::B): 
            return m_b; 
        case (Register8::C): 
            return m_c; 
        case (Register8::D): 
            return m_d; 
        case (Register8::E): 
            return m_e; 
        case (Register8::F): 
            return m_f; 
        case (Register8::H): 
            return m_h; 
        case (Register8::L): 
            return m_l; 
    }
}

uint16_t CPU::get_register16(Register16 reg) 
{ 
    uint8_t reg1, reg2; 
    switch (reg)
    {
        case (Register16::AF): 
            reg1 = m_a;
            reg2 = m_b;
            break; 
        case (Register16::BC): 
            reg1 = m_b;
            reg2 = m_c;
            break; 
        case (Register16::DE): 
            reg1 = m_d;
            reg2 = m_e;
            break; 
        case (Register16::HL): 
            reg1 = m_h;
            reg2 = m_l;
            break; 
    }
    return (reg1 << 8) | reg2; 
}

void CPU::set_register8(Register8 reg, uint8_t value)
{
    switch (reg)
    {
        case(Register8::A):
            m_a = value; 
            break; 
        case (Register8::B): 
            m_b = value; 
            break; 
        case (Register8::C): 
            m_c = value; 
            break; 
        case (Register8::D): 
            m_d = value; 
            break; 
        case (Register8::E): 
            m_e = value; 
            break; 
        case (Register8::F): 
            m_f = value; 
            break; 
        case (Register8::H): 
            m_h = value; 
            break; 
        case (Register8::L): 
            m_l = value;
            break; 
    }
}

void CPU::set_register16(Register16 reg, uint16_t value)
{
    uint8_t reg1_value = value >> 8; 
    uint8_t reg2_value = value & 0xF; 

    switch (reg)
    {
        case (Register16::AF): 
            m_a = reg1_value;
            m_b = reg2_value;
            break; 
        case (Register16::BC): 
            m_b = reg1_value;
            m_c = reg2_value;
            break; 
        case (Register16::DE): 
            m_d = reg1_value;
            m_e = reg2_value;
            break; 
        case (Register16::HL): 
            m_h = reg1_value;
            m_l = reg2_value;
            break; 
    }
}
