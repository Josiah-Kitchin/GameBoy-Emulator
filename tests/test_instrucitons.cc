

#include <gtest/gtest.h> 
#include "cpu.h"
#include "instruction.h"

TEST(instruction, loadrr8)
{
    std::vector<uint8_t> memory { 0x78 }; 
    CPU cpu(memory);
    cpu.set_register(Register8::A, 8);
    std::unique_ptr<Instruction> instr = cpu.fetch_and_decode(); 

    cpu.execute(instr);
    ASSERT_EQ(cpu.get_register(Register8::B), 8);
}

TEST(instruction, loadvr8)
{
    std::vector<uint8_t> memory { 0x06, 8 }; 
    CPU cpu(memory);

    std::unique_ptr<Instruction> instr = cpu.fetch_and_decode(); 
    cpu.execute(instr);
    ASSERT_EQ(cpu.get_register(Register8::A), 8);
}

TEST(instruction, loadpointerr8)
{
    std::vector<uint8_t> memory { 0x7E, 0 };
    CPU cpu(memory);
    cpu.set_register(Register16::HL, 1);
    cpu.set_register(Register8::A, 9);

    std::unique_ptr<Instruction> instr = cpu.fetch_and_decode(); 
    cpu.execute(instr);
    ASSERT_EQ(memory[1], 9);
}
