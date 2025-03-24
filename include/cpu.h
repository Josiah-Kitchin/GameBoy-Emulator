
#pragma once

#include <cstdint> 
#include <vector> 
#include <array> 
#include <memory> 

class Instruction; 

/// @brief Responsible for fetching, decoding, and executing instructions. 
/// Instructions effect the state of the CPU to perform emulated operations
class CPU 
{
public: 
    /// @brief Fetches instruction from memory and updates program counter 
    /// @param bytes 
    /// @return A unqiue pointer to the base class instruction 
    const std::unique_ptr<Instruction> fetch_and_decode(const std::vector<uint8_t>& bytes);

    /// @brief Executes the instruction object and changes the state of the CPU 
    /// @param instruction Base class instruction pointer
    void execute(const std::unique_ptr<Instruction>& instruction);

    struct Flags
    {
    public:     
        void set_zero(uint8_t bit) { m_zero = bit };
        void set_subtract(uint8_t bit) { m_subtract = bit }; 
        void set_half_carry(uint8_t bit) { m_half_carry = bit }; 
        void set_carry(uint8_t bit) { m_carry = bit }; 
        uint8_t get_zero() { return m_zero }; 
        uint8_t get_subtract() { return m_subtract }; 
        uint8_t get_half_carry() { return m_half_carry }; 
        uint8_t get_carry() { return m_carry }; 

    private: 
        uint8_t m_zero; 
        uint8_t m_subtract; 
        uint8_t m_half_carry; 
        uint8_t m_carry; 
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
    uint8_t m_a, m_b, m_c, m_d, m_e, m_f, m_h, m_l; 
    uint8_t m_sp, m_pc; 
};