
#include "instructions/instruction_factory.h"
#include "instructions/instruction.h"
#include "cpu.h"

int main()
{
    CPU cpu; 
    std::unique_ptr<Instruction> instr = InstructionFactory::make_instruction(0x79);
    cpu.execute(instr);

    return 0; 
}