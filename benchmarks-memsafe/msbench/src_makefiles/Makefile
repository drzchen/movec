DIRS := c-syntax  all-mem-err  nptrs
SOURCES := $(sort $(wildcard $(patsubst %, %/*.c, $(DIRS))))

OBJS    := $(patsubst %.c, %.o, $(SOURCES))
DEPS    := $(patsubst %.c, %.d, $(SOURCES))
PROGS   := $(patsubst %.c, %, $(SOURCES))
OUTPUTS := $(patsubst %.c, %.output.txt, $(SOURCES))
ERRORS  := $(patsubst %.c, %.error.txt, $(SOURCES))

# Softboundcets crashes on instrumenting some programs.
SOCETS_CRASHES := \
	c-syntax/5_fc_s_3fpc.c \
	c-syntax/5_fpc_p_s_1v.c \
	c-syntax/5_fpc_p_s_3fc.c \
	c-syntax/5_fpc_p_s_4va.c \
	c-syntax/5_fpc_p_s_5ce.c \
	c-syntax/5_fpc_p_s_7r.c

.PHONY: build run clean
# Ignore the runs that will cause errors.
.IGNORE: $(patsubst %.c, %, $(SOCETS_CRASHES)) \
	 $(patsubst %.c, %.output.txt, $(SOURCES))
.SUFFIXES: # Delete the default suffixes

CC := gcc -O3
RM := rm

build: $(PROGS)
	@echo "***Successfully built all benchmarks."

$(PROGS): %: %.c
	@echo "Building" $@
	$(INSTRU_CC) $< -o $@

run: $(OUTPUTS)
	@echo "***Successfully ran all benchmarks."

$(OUTPUTS): %.output.txt: %
	@echo "Running" $<
	@/usr/bin/time $(INSTRU_BIN) $< > $@ 2> $<.error.txt
	@../../grep_time_mem.sh $<.error.txt

clean:
	@$(RM) -f $(ERRORS) $(OUTPUTS) $(PROGS) $(DEPS) $(OBJS)
