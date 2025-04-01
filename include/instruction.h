
#pragma once
#include "registers.h"

class CPU;

/// @brief Abstract class of instructions
class Instruction
{
  public:
    /// @brief Modifies the state of the CPU to emulate a gameboy instruction
    /// @param cpu Reference to the CPU singleton
    virtual void execute(CPU& cpu) const = 0;
    virtual ~Instruction() = default;
    Instruction(uint8_t num_bytes, uint8_t clock_cycles);

    /// @brief Fetches data needed by instruction from memory
    /// @param pc program counter of the cpu 
    /// @param memory memory used by the cpu 
    void fetch_data(uint8_t pc, const std::vector<uint8_t>& memory);

    uint8_t get_num_bytes() const { return m_num_bytes; }
    uint8_t get_clock_cycles() const { return m_clock_cycles; }

  protected: 
    uint8_t n = 0;
    uint16_t nn = 0;

  private:
    uint8_t m_num_bytes = 0;  
    uint8_t m_clock_cycles = 0;

};

/* --- Instructions --- */
class NoOp : public Instruction
{
    void execute(CPU& cpu) const override;
    NoOp() : Instruction(1, 1) {}
};

class LoadRR8 : public Instruction
// Load 8 bit register from src to dst
{
  public:
    void execute(CPU& cpu) const override;
    LoadRR8(Register8 src, Register8 dst) : Instruction(1, 4), src(src), dst(dst) {}

  private:
    Register8 src, dst;
};

class LoadVR8 : public Instruction
// Load 8 bit value into a register
{
  public:
    void execute(CPU& cpu) const override;
    LoadVR8(Register8 dst) : Instruction(2, 8), dst(dst) {}

  private:
    Register8 dst;
};

class LoadHLPointerR8 : public Instruction
// Load a byte pointed to in pointer register to a 8 bit register 
{
  public:
    void execute(CPU& cpu) const override;
    LoadHLPointerR8(Register8 dst) : Instruction(1, 4), dst(dst) {}

  private: 
    Register8 dst; 
};
