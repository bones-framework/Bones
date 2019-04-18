#ifndef BONES_QUEUE_H
#define BONES_QUEUE_H

#include <stdint.h>
#include "signal.h"

#define QUEUE_SIZE 16

typedef queue_node {
    signal_id_t         id;
    void*               data;
    signal_callback_f_t callback;
} queue_node_t;

typedef struct queue {
    // TODO add dynamic size for profiling member
    signal_node_t signals[QUEUE_SIZE];
} queue_t;

#endif
