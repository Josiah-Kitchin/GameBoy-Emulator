

#include "memory.h"

uint8_t Memory::read(uint16_t address) const
{
    return m_memory[address];
}

void Memory::write(uint16_t address, uint8_t byte)
{
    m_memory[address] = byte; 
}

void Memory::load(const std::vector<uint8_t>& bytes)
{
    for (uint8_t byte : bytes)
        m_memory.push_back(byte);
}
