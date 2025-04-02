

#include "cpu.h"
#include "instruction.h"

#include <cassert> 

Instruction::Instruction(uint8_t num_bytes, uint8_t clock_cycles)
    :  m_num_bytes(num_bytes), m_clock_cycles(clock_cycles) 
{
    assert(num_bytes == 1 || num_bytes == 2 || num_bytes == 3); 
}

void Instruction::fetch_data(uint8_t pc, const Memory& memory)
{
    if (m_num_bytes == 2)
    {
        n = memory.read(pc + 1);
    }
    else if (m_num_bytes == 3)
    {
        uint8_t byte1 = memory.read(pc + 1);
        uint8_t byte2 = memory.read(pc + 2);
        nn = (byte2 << 8) | byte1; 
    }
}

/* ------------- Other Instructions ------------- */

void NoOp::execute(CPU& cpu) const 
{
    return; 
}

/*---------------  Load Instructions -------------- */

void LoadRR8::execute(CPU& cpu) const
{
    uint8_t reg_value = cpu.get_register(src);
    cpu.set_register(dst, reg_value); 
}


void LoadR8V::execute(CPU& cpu) const 
{
    cpu.set_register(dst, n);
}

void LoadPointerR8::execute(CPU& cpu) const
{
    cpu.bus.memory.write(cpu.get_register(pointer), cpu.get_register(src));
}

void LoadR8Pointer::execute(CPU& cpu) const
{
    uint8_t value = cpu.bus.memory.read(cpu.get_register(pointer));
    cpu.set_register(dst, value);
}

void LoadPointerV::execute(CPU& cpu) const 
{
    cpu.bus.memory.write(cpu.get_register(pointer), n);
}

void LoadR8PointerV::execute(CPU& cpu) const
{
    uint8_t value = cpu.bus.memory.read(nn);
    cpu.set_register(dst, value);
}

void LoadPointerVR8::execute(CPU& cpu) const
{
    cpu.bus.memory.write(nn, cpu.get_register(src));
}