
#pragma once
#include <vector> 
#include <cstdint> 


/// @brief Stores all forms of memory
class Memory
{
    Memory();
    uint8_t read(uint16_t address);
    void write(uint16_t address, uint8_t byte);

    uint16_t rom_bank00_start = 0x0000; 
    uint16_t rom_bank01_start = 0x4000; 
    uint16_t video_ram_start = 0x8000; 
    uint16_t external_ram_start = 0xA000; 
    uint16_t work_ram_start = 0xC000; 
    uint16_t echo_ram_start = 0xE000; 
    uint16_t object_attribute_start = 0xFE00; 
    uint16_t io_registers_start = 0xFF00; 
    uint16_t high_ram_start = 0xFF80; 
    uint16_t interupt_enable_register = 0xFFFF; 

private: 
    std::vector<uint8_t> m_memory; 
};
