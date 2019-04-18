CC ?= gcc

SRCS += bones/errors.c
SRCS += bones/signals.c
SRCS += bones/signal_router.c

OBJS := $(SRCS:build/%.o=%.c)

INCLUDE_DIRS += libc/bones-libc

CFLAGS += $(SRCS:-I%)

all: $(SRCS)
	$(CC) -o bones-core $(OBJS)

build/%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf build

