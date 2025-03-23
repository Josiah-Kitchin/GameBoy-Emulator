

#include "cpu.h"
#include "instructions/instruction.h"
#include "instructions/instruction_factory.h"

const std::unique_ptr<Instruction> CPU::fetch_and_decode(const std::vector<uint8_t>& instr_bytes)
{
    uint8_t opcode = instr_bytes[pc];
    std::unique_ptr<Instruction> instr = InstructionFactory::get_instruction(opcode);
    pc += instr->num_instr_bytes; 
    return instr; 
}


void CPU::execute(const std::unique_ptr<Instruction>& instruction)
/*
    Dynamic dispatch of instructions, each instruction modifies the state
    of the CPU 
*/
{
    instruction->execute(*this);
}


// Interface methods 

uint8_t CPU::get_register8(Register8 reg)
{
    switch (reg)
    {
        case(Register8::A):
            return a; 
        case (Register8::B): 
            return b; 
        case (Register8::C): 
            return c; 
        case (Register8::D): 
            return d; 
        case (Register8::E): 
            return e; 
        case (Register8::F): 
            return f; 
        case (Register8::H): 
            return h; 
        case (Register8::L): 
            return l; 
    }
}

uint16_t CPU::get_register16(Register16 reg) 
{ 
    uint8_t reg1, reg2; 
    switch (reg)
    {
        case (Register16::AF): 
            reg1 = a;
            reg2 = b;
            break; 
        case (Register16::BC): 
            reg1 = b;
            reg2 = c;
            break; 
        case (Register16::DE): 
            reg1 = d;
            reg2 = e;
            break; 
        case (Register16::HL): 
            reg1 = h;
            reg2 = l;
            break; 
    }
    return (reg1 << 8) | reg2; 
}

void CPU::set_register8(Register8 reg, uint8_t value)
{
    switch (reg)
    {
        case(Register8::A):
            a = value; 
            break; 
        case (Register8::B): 
            b = value; 
            break; 
        case (Register8::C): 
            c = value; 
            break; 
        case (Register8::D): 
            d = value; 
            break; 
        case (Register8::E): 
            e = value; 
            break; 
        case (Register8::F): 
            f = value; 
            break; 
        case (Register8::H): 
            h = value; 
            break; 
        case (Register8::L): 
            l = value;
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
            a = reg1_value;
            b = reg2_value;
            break; 
        case (Register16::BC): 
            b = reg1_value;
            c = reg2_value;
            break; 
        case (Register16::DE): 
            d = reg1_value;
            e = reg2_value;
            break; 
        case (Register16::HL): 
            h = reg1_value;
            l = reg2_value;
            break; 
    }
}
