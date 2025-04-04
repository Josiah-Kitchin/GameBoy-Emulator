
#pragma once

#include <cstdint> 
#include <vector> 
#include <array> 
#include "instruction.h"
#include "registers.h"
#include "bus.h"


/// @brief Responsible for fetching, decoding, and executing instructions. 
/// Instructions effect the state of the CPU to perform emulated operations
class CPU 
{
public: 
    CPU(Bus& bus);
    ~CPU(); 

    /// @brief Fetches instruction from memory and updates program counter 
    /// @param bytes 
    /// @return A unqiue pointer to the base class instruction 
    const Instruction* fetch_and_decode();

    /// @brief Executes the instruction object and changes the state of the CPU 
    /// @param instruction Base class instruction pointer
    void execute(const Instruction* instruction);

    void set_zero(uint8_t bit);
    void set_subtract(uint8_t bit); 
    void set_half_carry(uint8_t bit); 
    void set_carry(uint8_t bit); 

    void set_register(Register8 reg, uint8_t value);
    void set_register(Register16 reg, uint16_t value);

    uint8_t get_register(Register8 reg);
    uint16_t get_register(Register16 reg);

    uint8_t get_pc() { return m_pc; }
    uint8_t get_sp() { return m_sp; }

    Bus& bus;  // Connection to other components of the gameboy

    
private: 
    /// @brief Returns a pointer to an instruction based on the opcode 
    /// @param opcode Byte that decides what instruction to execute
    /// @return Pointer to the base instruction class, type of derived class varies on opcode  
    const Instruction* fetch_instruction(uint8_t opcode); 

    // registers
    uint8_t m_a = 0, m_b = 0, m_c = 0, m_d = 0, m_e = 0, m_f = 0, m_h = 0, m_l = 0; 
    uint8_t m_sp = 0, m_pc = 0; 


    // For fetching and decoding 
    std::array<Instruction*, 256> m_opcode_table; 
    void init_opcode_table();
};
