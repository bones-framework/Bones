#ifndef BONES_QUEUE_C
#define BONES_QUEUE_C

#include "queue.h"

error_t push_signal(queue_ptr_t queue, signal_wrap_ptr_t signal_wrap) {
    register queue_index_t queue_head = queue->head;
    register signal_wrap_ptr sig;
    
    if (queue->state == QUEUE_FULL) {
        return ERROR_QUEUE_FULL;
    }

    (queue_head >= QUEUE_SIZE - 1) ? queue->head = 0 : \
                                     queue->head++;

    sig = &(queue->signals[queue_head]);
    sig->id = wrap_signal->id;
    sig->data = wrap_signal->data;
    sig->callback = wrap_signal_callback;

    if (queue->head == queue->tail) {
        queue->state = QUEUE_FULL;
    }

    return NO_ERROR;
}

error_t pop_signal(queue_ptr_t queue, signal_wrap_ptr_t signal_wrap_dest) {
    register queue_index_t queue_tail;
    register signal_wrap_ptr sig;

    if (queue->state == QUEUE_EMPTY) {
        return ERROR_QUEUE_EMPTY;
    }

    (queue_tail >= QUEUE_SIZE - 1) ? queue->tail = 0 : \
                                     queue->tail++;

    sig = &(queue->signals[queue_tail]);
    signal_wrap_dest->id = sig->id;
    signal_wrap_dest->data = sig->data;
    signal_wrap_dest->callback = sig->callback;

    // Shred
    sig->id = 0;
    sig->data = NULL;
    sig->callback = NULL;

    if (queue->tail == queue->head) {
        queue->state = QUEUE_EMPTY;
    }
}

#endif
