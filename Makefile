CC ?= gcc

SRCS += bones/signals/signals.c
SRCS += bones/signals/signal_router.c
SRCS += bones/util/errors.c
SRCS += bones/util/queue.c

OBJS := $(SRCS:%.c=build/%.o)
OBJDIRS := $(dir $(OBJS))

INCLUDE_DIRS += libs/bones-libc
INCLUDE_DIRS += ./

CFLAGS += -nostdinc -nostartfiles -ffreestanding -std=gnu99 -Wall -Werror
CFLAGS += $(INCLUDE_DIRS:%=-I%)

all: $(OBJDIRS) $(OBJS)
	$(CC) $(CFLAGS) -o bones-core $(OBJS)

build/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

build/%:
	mkdir -p $@
	
clean:
	rm -rf build
	rm -rf bones-core

