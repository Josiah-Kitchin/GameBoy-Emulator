
#pragma once

#include "cpu.h"

/// @brief Abstract class of instructions
/// Instructions modify the state of the cpu, and are decoded via the instruction factory 
/// If the number of bytes for the instruction is beyond 1, it must be 
/// set in the constructor to correctly update the pc 
class Instruction
{
public: 
    /// @brief Modifies the state of the CPU to emulate a gameboy instruction
    /// @param cpu Reference to the CPU singleton 
    virtual void execute(CPU& cpu) const = 0; 
    virtual ~Instruction() = default; 

    unsigned int num_instr_bytes = 1;   
};

class LoadRR8 : public Instruction
{
public: 
    void execute(CPU&) const override; 
    LoadRR8(CPU::Register8 src, CPU::Register8 dst) : src(src), dst(dst) {}

private: 
    CPU::Register8 src, dst; 
};





