#include "queue.h"

error_t enqueue(queue_t* queue, void* element) {

    CHECK_ERROR(queue->state == QUEUE_FULL,
		    ERROR_QUEUE_FULL);


    memcpy(&(queue->elements[queue->head *
		queue->element_size]),
		element,
		queue->element_size
            );

    
    (queue->head < QUEUE_SIZE - 1) ? queue->head++ : \
	                             queue->head = 0;
    
    queue->state = (queue->head == queue->tail) ? \
		   QUEUE_FULL : QUEUE_AVAIL;
    return NO_ERROR;
}

error_t dequeue(queue_t* queue, void* element_dest) {
    
    CHECK_ERROR(queue->state == QUEUE_EMPTY,
		    ERROR_QUEUE_EMPTY);

    memcpy(element_dest,
           &(queue->elements[queue->tail *
		   queue->element_size]),
	   queue->element_size);

    (queue->tail < QUEUE_SIZE - 1) ? queue->tail++ : \
	                             queue->tail = 0;

    queue->state = (queue->tail == queue->head) ? \
		   QUEUE_EMPTY : QUEUE_AVAIL;
    return NO_ERROR;
}

