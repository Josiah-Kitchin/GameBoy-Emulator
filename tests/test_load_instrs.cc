

#include <gtest/gtest.h> 
#include "cpu.h"
#include "instruction.h"

TEST(LoadInstr, LoadRR8)
{
    // Test loading register B into register A 
    std::vector<uint8_t> memory { 0x78 }; 
    CPU cpu(memory);
    cpu.set_register(Register8::B, 8);
    std::unique_ptr<Instruction> instr = cpu.fetch_and_decode(); 

    cpu.execute(instr);
    ASSERT_EQ(cpu.get_register(Register8::A), 8);
}

TEST(LoadInstr, LoadR8V)
{
    // Test loading a value into register B 
    std::vector<uint8_t> memory { 0x06, 8 }; 
    CPU cpu(memory);

    std::unique_ptr<Instruction> instr = cpu.fetch_and_decode(); 
    cpu.execute(instr);
    ASSERT_EQ(cpu.get_register(Register8::B), 8);
}

TEST(LoadInstr, LoadR8Pointer)
{
    // Test loading a value pointed by HL in memory into register A 
    std::vector<uint8_t> memory { 0x7E, 3 };
    CPU cpu(memory);
    cpu.set_register(Register16::HL, 1);

    std::unique_ptr<Instruction> instr = cpu.fetch_and_decode(); 
    cpu.execute(instr);
    ASSERT_EQ(cpu.get_register(Register8::A), 3);
}

TEST(LoadInstr, LoadPointerR8)
{
    // Test loading a value from a register into memory pointed to by HL
    std::vector<uint8_t> memory { 0x70, 0 };
    CPU cpu(memory);
    cpu.set_register(Register8::B, 7);
    cpu.set_register(Register16::HL, 1);

    std::unique_ptr<Instruction> instr = cpu.fetch_and_decode(); 
    cpu.execute(instr);
    ASSERT_EQ(memory[1], 7);
}
