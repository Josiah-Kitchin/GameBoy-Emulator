
#include "clock.h"
#include <chrono> 
#include <thread> 

using namespace std::chrono; 

void Clock::wait_for_cycles(unsigned int num_cycles)
{
    std::this_thread::sleep_for(Clock::m_cycle_duration * num_cycles);
}

