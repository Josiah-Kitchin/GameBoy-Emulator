
#pragma once

#include <chrono> 

/// @brief Simple version, waiting for each cycle after completing the entire instruction. 
/// In the future, may swap to a version that disperses the cycles among stages for more accurate emulation 
namespace Clock
{
    void wait_for_cycles(unsigned int num_cycles); 

    constexpr static std::chrono::milliseconds m_cycle_duration(1); 
};