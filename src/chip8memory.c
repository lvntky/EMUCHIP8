#include "D:\GitHub\EMUCHIP8\include\chip8memory.h" //chip8memory.h

void chip8_memory_set(struct chip8_memory* memory, int index, unsigned char val)
{
    memory->memory[index] = val;
}

unsigned char chip8_memory_get(struct chip8_memory* memory, int index)
{
    return memory->memory[index];
}