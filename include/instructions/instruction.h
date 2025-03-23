
#pragma once

#include "cpu.h"

class Instruction
/* 
    Abstract class of instructions
    Instructions modify the state of the cpu, and are decoded via the instruction factory 

    If the number of bytes for the instruction is beyond 1, it must be 
    set in the constructor to correctly update the pc 
*/
{
public: 
    // Execute function modifies the state of the cpu 
    virtual void execute(CPU&) const = 0; 
    virtual ~Instruction() = default; 

    // Instructions can vary in bytes 
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




