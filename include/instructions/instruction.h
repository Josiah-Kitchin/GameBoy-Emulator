
#pragma once

#include "cpu.h"

class Instruction
/* 
    Abstract class of instructions
    Instructions modify the state of the cpu, and are decoded via the instruction factory 
*/
{
public: 
    // Execute function modifies the state of the cpu 
    virtual void execute(CPU&) const = 0; 
    virtual ~Instruction() = default; 
};

