
#include <gtest/gtest.h> 
#include "instructions/instruction.h"
#include "cpu.h"
#include <memory.h> 

TEST(Instruction, LoadRR8)
{
    CPU cpu; 
    cpu.set_register8(CPU::Register8::A, 3);
    cpu.set_register8(CPU::Register8::B, 9);
    const std::unique_ptr<Instruction> instr = std::make_unique<LoadRR8>(CPU::Register8::A, CPU::Register8::B);
    cpu.execute(instr);
    ASSERT_EQ(3, cpu.get_register8(CPU::Register8::B));
}