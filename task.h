#ifndef __EMTARI_TASK__
#define __EMTARI_TASK__

#include <stdlib.h>
#include <stdint.h>

#define TASK_RUNNING 0 //currently running
#define TASK_QUEUED 1 // queued to run after 
#define TASK_SLEEPING 2 // Sleeping for a period

struct task_struct {
    
    //pointer to next task
    struct task_struct *next_task;

    uint8_t task_status;

    uint8_t task_id;
   


};

#define get_next_task(tsk) tsk->next_task;
    
    struct task_struct * create_new_task();
    struct task_struct * get_task_from_id(uint8_t );
    
#endif
