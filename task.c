#include "task.h"


static uint8_t number_of_tasks =0;

static struct task_struct * task_head;

void __add_task_to_list(struct task_struct * tsk)
{
    if(!number_of_tasks)
    {
	tsk->next_task = tsk;
	task_head = tsk;
	return;
    }
    else
    {
	tsk->next_task = task_head->next_task;
	task_head->next_task = tsk;
    }
    
}

struct task_struct * create_new_task()
{
    struct task_struct * tsk = malloc(sizeof(struct task_struct));
    tsk->task_id = number_of_tasks++;
    tsk->task_status = TASK_QUEUED;
    __add_task_to_list(tsk);
}


struct task_struct * get_task_from_id(uint8_t id)
{
    struct task_struct * tsk = task_head;
    while(1)
    {
	if(tsk->task_id == id)
	    return tsk;

	if(tsk->next_task == task_head)
	    return 0;

	tsk = tsk->next_task;

    }

}
