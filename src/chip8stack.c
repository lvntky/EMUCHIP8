#include "D:\GitHub\EMUCHIP8\include\chip8stack.h" //chip8stack.h
#include "D:\GitHub\EMUCHIP8\include\chip8.h" //chip8.h
#include <assert.h>

// checking that the stack pointer in the bounds of stack or not
// So we cant overflow in our stack
static void chip8_stack_in_bounds(struct chip8* chip8)
{
    assert(chip8->registers.SP < sizeof(chip8->stack.stack));    
}

void chip8_stack_push(struct chip8* chip8, unsigned short val)
{
    chip8->registers.SP += 1;
    chip8_stack_in_bounds(chip8);

    chip8->stack.stack[chip8->registers.SP] = val;
}

unsigned short chip8_stack_pop(struct chip8* chip8)
{
    chip8_stack_in_bounds(chip8);
    
    unsigned short result = chip8->stack.stack[chip8->registers.SP];
    chip8->registers.SP -=1;
    return result;
}