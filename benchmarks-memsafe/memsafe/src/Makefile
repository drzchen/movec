DIRS := c-syntax  all-mem-err  nptrs
SOURCES := $(sort $(wildcard $(patsubst %, %/*.c, $(DIRS))))
SOURCES_WITH_ERROR := \
       all-mem-err/5_segment_id_1.w.c \
       all-mem-err/5_segment_id_2.c \
       all-mem-err/5_segment_id_exploit.c \
       all-mem-err/5_segment_if_1.c \
       all-mem-err/5_segment_if_2.c \
       all-mem-err/s3_wf_stdlib_free.c \
       all-mem-err/s3_wf_string.c \
       c-syntax/2_psk_cf.c

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
	@../../grep_time_mem.sh $<.error.txt

clean:
	@$(RM) -f $(ERRORS) $(OUTPUTS) $(PROGS) $(DEPS) $(OBJS)
