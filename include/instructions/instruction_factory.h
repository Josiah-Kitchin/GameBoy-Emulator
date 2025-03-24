
#pragma once
#include "instruction.h"
#include <memory> 
#include <unordered_map> 
#include <functional> 

namespace InstructionFactory
{
    /// @brief Returns a pointer to an instruction based on the opcode 
    /// @param opcode Byte that decides what instruction to execute
    /// @return Pointer to the base instruction class, type of derived class varies on opcode  
    const std::unique_ptr<Instruction> make_instruction(uint8_t opcode);
}