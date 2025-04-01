
#include "cpu.h"
#include "registers.h"
#include <gtest/gtest.h>

TEST(cpu, get_register16)
{
    std::vector<uint8_t> memory; 
    CPU cpu(memory);
    cpu.set_register(Register8::B, 0xCC);
    cpu.set_register(Register8::C, 0x88);
    ASSERT_EQ(cpu.get_register(Register16::BC), 0xCC88);
}

TEST(cpu, set_register16)
{
    std::vector<uint8_t> memory; 
    CPU cpu(memory);
    cpu.set_register(Register16::DE, 0x1234);
    ASSERT_EQ(cpu.get_register(Register8::D), 0x12);
    ASSERT_EQ(cpu.get_register(Register8::E), 0x34);
}

TEST(cpu, set_zero)
{
    std::vector<uint8_t> memory; 
    CPU cpu(memory);
    cpu.set_zero(1);
    ASSERT_EQ(cpu.get_register(Register16::AF), 0b1);
}

TEST(cpu, set_subtract)
{
    std::vector<uint8_t> memory; 
    CPU cpu(memory);
    cpu.set_subtract(1);
    ASSERT_EQ(cpu.get_register(Register16::AF), 0b10);
}

TEST(cpu, set_half_carry)
{
    std::vector<uint8_t> memory; 
    CPU cpu(memory);
    cpu.set_half_carry(1);
    ASSERT_EQ(cpu.get_register(Register16::AF), 0b100);
}

TEST(cpu, set_carry)
{
    std::vector<uint8_t> memory; 
    CPU cpu(memory);
    cpu.set_carry(1);
    ASSERT_EQ(cpu.get_register(Register16::AF), 0b1000);
}
