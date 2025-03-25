
#include <gtest/gtest.h> 
#include "cpu.h"

TEST(cpu, get_register16)
{
    CPU cpu; 
    cpu.set_register8(CPU::Register8::B, 0xCC);
    cpu.set_register8(CPU::Register8::C, 0x88);
    ASSERT_EQ(cpu.get_register16(CPU::Register16::BC), 0xCC88);
}

TEST(cpu, set_register16)
{
    CPU cpu; 
    cpu.set_register16(CPU::Register16::DE, 0x1234);
    ASSERT_EQ(cpu.get_register8(CPU::Register8::D), 0x12);
    ASSERT_EQ(cpu.get_register8(CPU::Register8::E), 0x34);
}

TEST(cpu, set_zero)
{
    CPU cpu; 
    cpu.set_zero(1);
    ASSERT_EQ(cpu.get_register16(CPU::Register16::AF), 0b1);
}

TEST(cpu, set_subtract)
{
    CPU cpu; 
    cpu.set_subtract(1);
    ASSERT_EQ(cpu.get_register16(CPU::Register16::AF), 0b10);
}

TEST(cpu, set_half_carry)
{
    CPU cpu; 
    cpu.set_half_carry(1);
    ASSERT_EQ(cpu.get_register16(CPU::Register16::AF), 0b100);
}

TEST(cpu, set_carry)
{
    CPU cpu; 
    cpu.set_carry(1);
    ASSERT_EQ(cpu.get_register16(CPU::Register16::AF), 0b1000);
}