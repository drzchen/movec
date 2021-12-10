# You can use one of the two following ways to init SOURCES.
# 1. Search for all source files.
SOURCES := $(sort $(shell ls src/*.c))      # a list of source files
SOURCES := $(patsubst src/%, %, $(SOURCES)) # in the form *.c
# 2. Designate a set of source files.
# SOURCES := 11_psk_vg.c  11_psk_vst.c

BUILDS  := $(patsubst %.c, %/build, $(SOURCES))
RUNS    := $(patsubst %.c, %/run,   $(SOURCES))
CLEANS  := $(patsubst %.c, %/clean, $(SOURCES))
PROGRMS := $(patsubst %.c, src/%, $(SOURCES))
OUTTXTS := $(patsubst %.c, src/%.output.txt, $(SOURCES))

.PHONY: build $(BUILDS) run $(RUNS) clean $(CLEANS)
.SUFFIXES: # Delete the default suffixes

build: $(BUILDS)
	@echo "***Successfully built all benchmarks."

$(BUILDS): %/build: src/%

$(PROGRMS): src/%: src/%.c
	@$(MAKE) -C src $(patsubst src/%, %, $@) --no-print-directory

run: $(RUNS)
	@echo "***Successfully ran all benchmarks."

$(RUNS): %/run: src/%.output.txt

$(OUTTXTS): src/%.output.txt: src/%
	@$(MAKE) -C src $(patsubst src/%, %, $@) --no-print-directory

clean:
	@$(MAKE) -C src clean

$(CLEANS):
	@$(MAKE) -C src $@ --no-print-directory

-include Makefile.inc.movec-memsafe

-include Makefile.inc.addresssanitizer

-include Makefile.inc.softboundcets

-include Makefile.inc.valgrind
