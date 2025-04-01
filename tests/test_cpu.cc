
#include "cpu.h"
#include "registers.h"
#include "bus.h"
#include <gtest/gtest.h>

TEST(cpu, get_register16)
{
    Bus bus; 
    CPU cpu(bus);
    cpu.set_register(Register8::B, 0xCC);
    cpu.set_register(Register8::C, 0x88);
    ASSERT_EQ(cpu.get_register(Register16::BC), 0xCC88);
}

TEST(cpu, set_register16)
{
    Bus bus; 
    CPU cpu(bus);
    cpu.set_register(Register16::DE, 0x1234);
    ASSERT_EQ(cpu.get_register(Register8::D), 0x12);
    ASSERT_EQ(cpu.get_register(Register8::E), 0x34);
}

TEST(cpu, set_zero)
{
    Bus bus; 
    CPU cpu(bus);
    cpu.set_zero(1);
    ASSERT_EQ(cpu.get_register(Register16::AF), 0b1);
}

TEST(cpu, set_subtract)
{
    Bus bus; 
    CPU cpu(bus);
    cpu.set_subtract(1);
    ASSERT_EQ(cpu.get_register(Register16::AF), 0b10);
}

TEST(cpu, set_half_carry)
{
    Bus bus; 
    CPU cpu(bus);
    cpu.set_half_carry(1);
    ASSERT_EQ(cpu.get_register(Register16::AF), 0b100);
}

TEST(cpu, set_carry)
{
    Bus bus; 
    CPU cpu(bus);
    cpu.set_carry(1);
    ASSERT_EQ(cpu.get_register(Register16::AF), 0b1000);
}
