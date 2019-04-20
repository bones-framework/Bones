#ifndef BONES_ERROR_H
#define BONES_ERROR_H

#include <stdint.h>

#ifndef BONES_ERROR_MAX_FRAMES
  #define BONES_ERROR_MAX_FRAMES 128
#endif

#if BONES_ERROR_MAX_FRAMES >= 0xffff || BONES_ERROR_MAX_FRAMES < 0
    #error BONES_ERROR_MAX_FRAMES must be a positive 16bit value 
#endif

#ifdef BONES_DEBUG
    typedef struct error_frame {
        const char* file;
        const char* function;
        int line;
    } error_frame_t;
    
    #define ERROR_PUSH_FRAME() \
        do { \
            if(((err >> 16) & 0xFFFF) < BONES_ERROR_MAX_FRAMES) { \
                error_frames[(err >> 16) & 0xFFFF] = (error_frame_t){ __FILE__, __FUNCTION__, __LINE__ }; \
                err = ((((err >> 16) & 0xFFFF) + 1) << 16) | (err & 0xFFFF); \
            } \
        } while(0)
#else
    typedef void* error_frame_t;
    
    #define ERROR_PUSH_FRAME() \
        do { \
            if(((err >> 16) & 0xFFFF) < BONES_ERROR_MAX_FRAMES) { \
                error_frames[(err >> 16) & 0xFFFF] = __builtin_return_address(0); \
                err = ((((err >> 16) & 0xFFFF) + 1) << 16) | (err & 0xFFFF); \
            } \
        } while(0)
#endif

typedef uint32_t error_t;
        
extern error_frame_t error_frames[BONES_ERROR_MAX_FRAMES];

#define NO_ERROR            ((error_t)0)
#define ERROR_CHECK_FAILED  ((error_t)1)
#define ERROR_QUEUE_EMPTY   ((error_t)2)
#define ERROR_QUEUE_FULL    ((error_t)3)

#define CHECK_ERROR(condition, error) \
    do { \
        if(!(condition)) { \
            err = (error); \
            ERROR_PUSH_FRAME(); \
            goto cleanup; \
        } \
    } while(0)

#define CHECK(condition) CHECK_ERROR(condition, ERROR_CHECK_FAILED)
    
#define CHECK_AND_RETHROW(error)  \
    do { \
        err = (error); \
        if(err != NO_ERROR) { \
            ERROR_PUSH_FRAME(); \
            goto cleanup; \
        } \
    } while(0)
    
#endif
