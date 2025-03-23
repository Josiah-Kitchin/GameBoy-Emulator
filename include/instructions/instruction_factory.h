
#pragma once
#include "instruction.h"
#include <memory> 

namespace InstructionFactory
/*
    Creates an instruction based on the opcode 
*/
{
    const std::unique_ptr<Instruction> get_instruction(uint8_t opcode);
};