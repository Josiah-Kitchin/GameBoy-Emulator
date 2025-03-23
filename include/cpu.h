
#pragma once

#include <cstdint> 
#include <vector> 
#include <array> 
#include <memory> 

class Instruction; 

class CPU 
/* 
    Responsible for executing instructions 
*/
{
public: 
    // Fetches the instruction from memory and returns an instruction
    // object. Updates the pc 
    const std::unique_ptr<Instruction> fetch_and_decode(const std::vector<uint8_t>& bytes);

    void execute(const std::unique_ptr<Instruction>& instruction);

    struct Flags
    // Represent a single flag register, each flag being one bit 
    {
        
    public:     
        uint8_t zero; 
        uint8_t subtract; 
        uint8_t half_carry; 
        uint8_t carry; 
    };
    Flags flags; 

    enum class Register8 { A, B, C, D, E, F, H, L };
    enum class Register16 { AF, BC, DE, HL };

    void set_register8(Register8 reg, uint8_t value);
    void set_register16(Register16 reg, uint16_t value);

    uint8_t get_register8(Register8 reg);
    uint16_t get_register16(Register16 reg);
    
private: 
    // registers
    uint8_t a, b, c, d, e, f, h, l; 
    uint8_t sp, pc; 
};