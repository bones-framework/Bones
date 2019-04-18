CC ?= gcc

SRCS += 

OBJS := $(SRCS:build/%.o=%.c)

all: $(SRCS)
	$(CC) -o bones-core $(OBJS)	

build/%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf build

