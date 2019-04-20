#ifndef BONES_QUEUE_H
#define BONES_QUEUE_H

#include <stdint.h>
#include <string.h>
#include <bones/signals/signals.h>
#include "errors.h"

#define QUEUE_FROM_ARRAY(arr) \
    (queue_t){  \
        .size = sizeof(arr) / sizeof(*arr), \
        .element_size = sizeof(*arr), \
        .elements = arr, \
    }

#define STATIC_QUEUE(name, type, size) \
    static type __##name##_queue_buffer[size] = {0}; \
    static queue_t name = QUEUE_FROM_ARRAY(__##name##_queue_buffer);

#define QUEUE(name, type, size) \
    type __##name##_queue_buffer[size] = {0}; \
    queue_t name = QUEUE_FROM_ARRAY(__##name##_queue_buffer);

typedef enum queue_state {
    QUEUE_EMPTY = 0,
    QUEUE_FULL  = 1,
    QUEUE_AVAIL = 2,
} queue_state_t;

// TODO add dynamic queue size member for profiling

typedef struct queue {
    size_t head;
    size_t tail;
    queue_state_t state;
    size_t size;
    size_t element_size;
    void*  elements;
} queue_t;

error_t enqueue(queue_t* queue, void* elem);
error_t dequeue(queue_t* queue, void* elem_dest);

#endif
