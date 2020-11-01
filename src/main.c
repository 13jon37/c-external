#include <stdio.h>

#include "include/getwind.h"
#include "include/glow.h"

// NOTE(1337): 
// uintptr_t is an unsigned integer type
// stores llx = unsigned long long int

int main()
{
    Window* window = init("Counter-Strike: Global Offensive");
    
    uintptr_t module_base = get_module(window, "client.dll"); 
    uintptr_t engine_base = get_module(window,"engine.dll");
    
    printf("Module base: %llx\n", module_base);
    printf("Engine base: %llx\n", engine_base);
    
    bool running = true;
    
    while (running)
    {
        // Features
        
        
        Sleep(1);
    }
    
    clean_up(window);
    
    return 0;
}