#ifndef BONES_QUEUE_H
#define BONES_QUEUE_H

#include <stdint.h>
#include <string.h>
#include "signals.h"
#include "errors.h"

#define QUEUE_SIZE 512

typedef struct signal_wrap {
    int               id;
    void*             data;
    signal_callback_f callback;
} signal_wrap_t;

typedef enum queue_state {
    QUEUE_EMPTY = 0,
    QUEUE_FULL  = 1,
    QUEUE_AVAIL = 2,
} queue_state_t;

// TODO add dynamic queue size member for profiling

typedef struct queue {
    size_t head;
    size_t tail;
    size_t state;
    size_t element_size;
    void*  elements;
} queue_t;

error_t enqueue(queue_t* queue, void* elem);
error_t dequeue(queue_t* queue, void* elem_dest);

#endif
