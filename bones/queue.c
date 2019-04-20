#include "queue.h"

error_t enqueue(queue_t* queue, void* element) {
    error_t err = NO_ERROR;

    CHECK_ERROR(queue->state == QUEUE_FULL,
		    ERROR_QUEUE_FULL);


    memcpy(&(((char*)queue->elements)[queue->head *
		queue->element_size]),
		element,
		queue->element_size
            );

    
    if (queue->head < queue->size - 1) {
        queue->head++;
    } else {
	queue->head = 0;
    }
    
    queue->state = (queue->head == queue->tail) ? \
		   QUEUE_FULL : QUEUE_AVAIL;

cleanup:
    return err;
}

error_t dequeue(queue_t* queue, void* element_dest) {
    error_t err = NO_ERROR;

    CHECK_ERROR(queue->state == QUEUE_EMPTY,
		    ERROR_QUEUE_EMPTY);

    memcpy(element_dest,
           &(((char*)queue->elements)[queue->tail *
		   queue->element_size]),
	   queue->element_size);

    if (queue->tail < queue->size - 1) {
	    queue->tail++;
    } else {
	    queue->tail = 0;
    }

    queue->state = (queue->tail == queue->head) ? \
		   QUEUE_EMPTY : QUEUE_AVAIL;
    
cleanup:
    return err;
}

