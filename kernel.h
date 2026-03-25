#ifndef KERNEL_H
#define	KERNEL_H

#include "types.h"
#include <xc.h>

// Chamadas de sistema
void os_delay(uint8_t time);
void os_create_task(uint8_t id, f_ptr func, uint8_t prior);
void os_yield();
void os_config();
void os_start();

TASK idle();

#define SAVE_CONTEXT(state) { \
do { \
\
while (0); \

#define RESTORE_CONTEXT() { \
do { \
\
while (0); \


#endif	/* KERNEL_H */

