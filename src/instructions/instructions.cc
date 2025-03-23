

#include "instructions/instruction.h"

void LoadRR8::execute(CPU& cpu) const
{
    uint8_t reg_value = cpu.get_register8(src);
    cpu.set_register8(dst, reg_value); 
}