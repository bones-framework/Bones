#ifndef BONES_QUEUE_H
#define BONES_QUEUE_H

#include <stdint.h>
#include "signal.h"
#include "errors.h"

#define QUEUE_SIZE 16

typedef signal_wrap {
    signal_id_t         id;
    void*               data;
    signal_callback_f_t callback;
} signal_wrap_t;
typedef signal_wrap_t* signal_wrap_ptr_t;

typedef size_t queue_index_t;

typedef struct queue {
    // TODO add dynamic size for profiling member
    signal_wrap_t signals[QUEUE_SIZE];
    queue_index_t head;
    queue_index_t tail;
} queue_t;

error_t push_signal(signal_wrap_t sig_wrap);
error_t pop_signal(signal_wrap_ptr_t sig_wrap_dest);
#if defined(_DEBUG)
error_t peek_signal(signal_wrap_ptr_t sig_wrap_dest);
#endif

#endif
