

#include "cpu.h"
#include "instruction.h"
#include "clock.h"


const std::unique_ptr<Instruction> CPU::fetch_and_decode()
{
    uint8_t opcode = memory[m_pc];
    std::unique_ptr<Instruction> instr = create_instruction(opcode);
    m_pc += instr->get_num_bytes(); 
    return instr; 
}

void CPU::execute(const std::unique_ptr<Instruction>& instruction)
{
    instruction->execute(*this);
    Clock::wait_for_cycles(instruction->get_clock_cycles());
}

// Flags are the lower 4 bits of the F register

void CPU::set_zero(uint8_t bit)
{
    if (bit)
        m_f |= 0b1;
    else   
        m_f &= 0b1111110;
}

void CPU::set_subtract(uint8_t bit)
{
    if (bit)
        m_f |= 0b10;
    else   
        m_f &= 0b1111101;
}

void CPU::set_half_carry(uint8_t bit)
{
    if (bit)
        m_f |= 0b100;
    else   
        m_f &= 0b1111011;
}

void CPU::set_carry(uint8_t bit)
{
    if (bit)
        m_f |= 0b1000;
    else   
        m_f &= 0b1110111;
}


uint8_t CPU::get_register(Register8 reg)
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

uint16_t CPU::get_register(Register16 reg) 
{ 
    uint8_t reg1, reg2; 
    switch (reg)
    {
        case (Register16::AF): 
            reg1 = m_a;
            reg2 = m_f;
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

void CPU::set_register(Register8 reg, uint8_t value)
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

void CPU::set_register(Register16 reg, uint16_t value)
{
    uint8_t reg1_value = value >> 8; 
    uint8_t reg2_value = value & 0xFF; 

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
