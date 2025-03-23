
#pragma once

#include <cstdint> 
#include <vector> 
#include <array> 

class Instruction; 

class CPU 
/* 
    Responsible for executing instructions 
*/
{
public: 
    void execute(const Instruction& instruction);

    struct Flags
    // Represent a single flag register, each flag being one bit 
    {
        uint8_t zero; 
        uint8_t subtract; 
        uint8_t half_carry; 
        uint8_t carry; 
    };

    struct Registers
    {
        // General registers 
        uint8_t a, b, c, d, e, f, h, l; 
        // Stack Pointer and Program Counter register 
        uint8_t sp, pc; 
        // Get the bytes combined in general registers
        uint16_t af();
        uint16_t bc();
        uint16_t de();
        uint16_t hl();
    };

    Flags flags; 
    Registers registers; 
};