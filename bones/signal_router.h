#ifndef BONES_SIGNAL_ROUTER_H
#define BONES_SIGNAL_ROUTER_H

#include "signals.h"

#ifndef BONES_SIGNAL_ROUTER_HANDLER_COUNT
    #define BONES_SIGNAL_ROUTER_HANDLER_COUNT SIGNAL_CODE_LAST
#endif

typedef struct signal_router {
    signal_handler_t handlers[BONES_SIGNAL_ROUTER_HANDLER_COUNT];
} signal_router_t;

extern signal_router_t signal_router;

/**
 * Will route a signal to the correct handlers
 * 
 * TODO: allow to either route to all or just to the first one found
 */
error_t route_signal(signal_code_t code, void* params,int* suid);

#endif
