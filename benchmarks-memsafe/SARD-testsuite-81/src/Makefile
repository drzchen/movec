SOURCES := $(sort $(wildcard src/*.c))
SOURCES_WITH_ERROR := \
	src/basic-00045-min.c \
	src/basic-00182-min.c

OBJS    := $(patsubst %.c, %.o, $(SOURCES))
DEPS    := $(patsubst %.c, %.d, $(SOURCES))
PROGS   := $(patsubst %.c, %, $(SOURCES))
OUTPUTS := $(patsubst %.c, %.output.txt, $(SOURCES))
ERRORS  := $(patsubst %.c, %.error.txt, $(SOURCES))

.PHONY: build run clean
# Ignore the runs that will cause errors.
.IGNORE: $(patsubst %.c, %.output.txt, $(SOURCES_WITH_ERROR))
.SUFFIXES: # Delete the default suffixes

CC := gcc -O3
RM := rm

build: $(PROGS)
	@echo "***Successfully built all benchmarks."

$(PROGS): %: %.c
	@echo "Building" $@
	$(CC) $< -o $@

run: $(OUTPUTS)
	@echo "***Successfully ran all benchmarks."

$(OUTPUTS): %.output.txt: %
	@echo "Running" $<
	@/usr/bin/time $< > $@ 2> $<.error.txt

clean:
	@$(RM) -f $(ERRORS) $(OUTPUTS) $(PROGS) $(DEPS) $(OBJS)
