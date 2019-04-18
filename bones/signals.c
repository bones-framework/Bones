#include "signals.h"

#include "signal_router.h"

error_t signal_queue(signal_code_t code, void* params, signal_callback_f callback, int* suid) {
    // TODO: requires queues
}

error_t signal_invoke(signal_code_t code, void* params) {
    error_t err = NO_ERROR;

    CHECK_AND_RETHROW(route_signal(code, params));
    
cleanup:
    return err;
}
