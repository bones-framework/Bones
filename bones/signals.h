#ifndef BONES_SIGNALS_H
#define BONES_SIGNALS_H

#include "errors.h"

#ifndef BONES_SIGNALS_LIST
    #error No signals have been declared!
#endif

typedef enum signal_code {
    // TODO: how users define signals

    SIGNAL_CODE_LAST
} signal_code_t;

typedef error_t (*signal_handler_f)(signal_handler_t* context, int suid, void* params);

typedef error_t (*signal_callback_f)(void* params, int suid);

typedef struct signal_handler {
    signal_code_t code;
    signal_handler_f handler;
} signal_handler_t;

error_t signal_queue(signal_code_t code, void* params, signal_callback_f callback, int* suid);

error_t signal_invoke(signal_code_t code, void* params);

#endif
