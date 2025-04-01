

#include "cpu.h"
#include "instruction.h"

#include <cassert> 

Instruction::Instruction(uint8_t num_bytes, uint8_t clock_cycles)
    :  m_num_bytes(num_bytes), m_clock_cycles(clock_cycles) 
{
    assert(num_bytes == 1 || num_bytes == 2 || num_bytes == 3); 
}

/// @brief Fet
/// @param pc 
/// @param memory 
void Instruction::fetch_data(uint8_t pc, const std::vector<uint8_t>& memory)
{
    if (m_num_bytes == 2)
    {
        n = memory[pc + 1];
    }
    else if (m_num_bytes == 3)
    {
        uint8_t byte1 = memory[pc + 1];
        uint8_t byte2 = memory[pc + 2];
        nn = (byte2 << 8) | byte1; 
    }
}

void LoadRR8::execute(CPU& cpu) const
{
    uint8_t reg_value = cpu.get_register(src);
    cpu.set_register(dst, reg_value); 
}

void NoOp::execute(CPU& cpu) const 
{
    return; 
}

void LoadVR8::execute(CPU& cpu) const 
{
    cpu.set_register(dst, n);
}

void LoadHLPointerR8::execute(CPU& cpu) const
{
    cpu.memory[cpu.get_register(Register16::HL)] = cpu.get_register(dst);
}