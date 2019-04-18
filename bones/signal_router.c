#include "signal_router.h"

signal_router_t signal_router = {0};
static int last_suid = 0;

error_t route_signal(signal_code_t code, void* params, int* suid) {
    error_t err = NO_ERROR;
    
    for(signal_handler_t* handler = signal_router.handlers; handler < signal_router.handlers + BONES_SIGNAL_ROUTER_HANDLER_COUNT; handler++) {
        if(handler && handler->code == code) {
            CHECK_AND_RETHROW(handler(handler, last_suid, params));
        }
    }

cleanup:
    *suid = last_suid;
    last_suid++;    
    
    return err;
}
