#include "D:\GitHub\EMUCHIP8\include\chip8keyboard.h" //chip8keyboard.h

int chip8_keyboard_map(const char* map, char key)
{
    for(int i = 0; i < CHIP8_TOTAL_KEYS; i++){
        if(map[i] == key){
            return i;
        }
    }

    return -1; //key not found
}