
#pragma once
#include "registers.h"
#include "memory.h"

class CPU;

/// @brief Abstract class of instructions
/// Naming Convention for derived classes: 
///     The destination is the first operand, the src is the second 
class Instruction
{
  public:
    /// @brief Modifies the state of the CPU to emulate a gameboy instruction
    /// @param cpu Reference to the CPU singleton
    virtual void execute(CPU& cpu) const = 0;
    virtual ~Instruction() = default;
    Instruction(uint8_t num_bytes, uint8_t clock_cycles);

    /// @brief Fetch byte n or bytes nn if the instruction is a multybyte instruction
    /// @param pc program counter of the cpu 
    /// @param memory memory used by the cpu 
    void fetch_data(uint8_t pc, const Memory& memory);

    uint8_t get_num_bytes() const { return m_num_bytes; }
    uint8_t get_clock_cycles() const { return m_clock_cycles; }

  protected: 
    // Set by fetch_data method 
    uint8_t n = 0;
    uint16_t nn = 0;

  private:
    // Initialized by each derived class 
    const uint8_t m_num_bytes = 0;  
    const uint8_t m_clock_cycles = 0;

};

/* ---------- Other Instructions --------- */

class NoOp : public Instruction
{
    void execute(CPU& cpu) const override;
    NoOp() : Instruction(1, 4) {}
};

/* ---------- Load Instructions --------- */

class LoadRR8 : public Instruction
// Load 8 bit register from src to dst
{
  public:
    void execute(CPU& cpu) const override;
    LoadRR8(Register8 dst, Register8 src) : Instruction(1, 4), dst(dst), src(src) {}

  private:
    Register8 dst, src;
};

class LoadR8V : public Instruction
// Load 8 bit value into a register
{
  public:
    void execute(CPU& cpu) const override;
    LoadR8V(Register8 dst) : Instruction(2, 8), dst(dst) {}

  private:
    Register8 dst;
};

class LoadPointerR8 : public Instruction
// Load the value in a register into memory pointed to by register HL 
{
  public:
    void execute(CPU& cpu) const override;
    LoadPointerR8(Register16 pointer, Register8 src) : Instruction(1, 8), pointer(pointer), src(src) {}

  private: 
    Register16 pointer;
    Register8 src; 
};

class LoadR8Pointer : public Instruction
// Load a byte pointed to in pointer register to a 8 bit register 
{
  public:
    void execute(CPU& cpu) const override;
    LoadR8Pointer(Register8 dst, Register16 pointer) : Instruction(1, 8), pointer(pointer), dst(dst) {}

  private: 
    Register16 pointer; 
    Register8 dst; 
};

class LoadPointerV : public Instruction
// Load a value into memory pointed to by register HL 
{
  public:
    void execute(CPU& cpu) const override;
    LoadPointerV(Register16 pointer) : Instruction(2, 12), pointer(pointer) {}

  private: 
    Register16 pointer; 
};