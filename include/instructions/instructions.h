

#pragma once

#include <cstdint> 

class Instruction
{
public: 
    virtual void execute() = 0; 
    virtual ~Instruction() = default; 
}; 









