#include "types.h"
#include "gdt.h"

void printf(char* str){
    static uint16_t* VideoMemory = (unsigned uint16_t*)0xb8000;
    static uint8_t x, y;
    for(int i = 0; str[i] != '\0'; i++){
        switch (str[i]){
            case '\n':
                x=0;
                y++;
                break;
            default:
                    VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0xFF00) | str[i];
                    x++;
                break;
        }

        if(x >=80){
            x = 0;
            y++;
        }

        if(y >= 25){
            for(uint8_t i = 0;i <= 80; i++)
                for(uint8_t j = 0; j <= 80; j++)
                    VideoMemory[80*i+j] = (VideoMemory[80*i+j] & 0xFF00) | ' ';
            x=0;
            y=0;
        }

    }
}

extern "C" void kernelMain(void* mutiboot_structure, unsigned int magicnumber){
    printf("Hello world! ");
    printf("Hello world! \n");
    printf("Hello world! ");

    GlobalDescriptorTable gdt;
    
    while(1);
}
