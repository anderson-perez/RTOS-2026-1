#ifndef TYPES_H
#define	TYPES_H

#include <stdint.h>
#include "os_config.h"

typedef void TASK;

typedef enum {READY = 0,
              WAITING,
              RUNNING
             } state_t;

typedef void (*f_ptr)(void);

typedef struct hw_stack {
    uint8_t TOSU_REG;
    uint8_t TOSL_REG;
    uint8_t TOSH_REG;
} hw_stack_t;

typedef struct sw_stack {
    hw_stack_t stack[MAX_STACK_SIZE];
    uint8_t stack_size;
} sw_stack_t;
             
typedef struct tcb {
    uint8_t task_id;
    state_t task_state;
    f_ptr   task_ptr;
    uint8_t task_delay;
    uint8_t task_priority;
    // Registradores
    uint8_t W_REG;
    uint8_t STATUS_REG;
    uint8_t BSR_REG;
    uint8_t PRODL_REG;
    uint8_t PRODH_REG;
    // Pilha de hardware
    sw_stack_t task_stack;
} tcb_t;

// Fila de aptos
typedef struct ready_queue {
    tcb_t TASKS[MAX_USER_TASKS+1];
    tcb_t size;
    tcb_t *task_running;
} ready_queue_t;

#endif	/* TYPES_H */

