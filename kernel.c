#include "kernel.h"

// Chamadas de sistema
void os_delay(uint8_t time)
{
    
}

void os_create_task(uint8_t id, f_ptr func, uint8_t prior)
{
    
}

void os_yield()
{
    
}


TASK idle()
{
    while (1) {
        asm("NOP");
    }
}
