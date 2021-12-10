SOURCES := $(sort $(wildcard *.c))
SOURCES_WITH_ERROR := # None

OBJS    := $(patsubst %.c, %.o, $(SOURCES))
DEPS    := $(patsubst %.c, %.d, $(SOURCES))
PROGS   := $(patsubst %.c, %, $(SOURCES))
OUTPUTS := $(patsubst %.c, %.output.txt, $(SOURCES))
ERRORS  := $(patsubst %.c, %.error.txt, $(SOURCES))

CLEANS  := $(patsubst %.c, %/clean, $(SOURCES))
.PHONY: build run clean $(CLEANS)
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
	@if [ -z "$${BENCHMARK_RUN_TIMES}" ]; then \
	     export BENCHMARK_COUNT_DOWN=1; \
	 else \
	     export BENCHMARK_COUNT_DOWN="$${BENCHMARK_RUN_TIMES}"; \
	     echo "==== Run $${BENCHMARK_RUN_TIMES} times ===="; \
	 fi; \
	 while [ $${BENCHMARK_COUNT_DOWN} -ge 1 ]; do \
	     /usr/bin/time ./$< > $@ 2> $<.error.txt; \
	     ../grep_time_mem.sh $<.error.txt; \
	     export BENCHMARK_COUNT_DOWN=`expr $${BENCHMARK_COUNT_DOWN} - 1`; \
	 done;

clean:
	@$(RM) -f $(ERRORS) $(OUTPUTS) $(PROGS) $(DEPS) $(OBJS)

$(CLEANS):
	@$(RM) -f $(patsubst %/clean, %.error.txt, $@)
	@$(RM) -f $(patsubst %/clean, %.output.txt, $@)
	@$(RM) -f $(patsubst %/clean, %, $@)
	@$(RM) -f $(patsubst %/clean, %.d, $@)
	@$(RM) -f $(patsubst %/clean, %.o, $@)
