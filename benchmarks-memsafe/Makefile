# You can use one of the two following ways to init DIRS.
# 1. Search for all sub-directories.
DIRS := $(sort $(shell ls -d */))
# 2. Designate a set of sub-directories.
# DIRS := memsafe/ SARD-testsuite-81/

BUILDS := $(patsubst %/, %/build, $(DIRS))
RUNS   := $(patsubst %/, %/run,   $(DIRS))
CLEANS := $(patsubst %/, %/clean, $(DIRS))

.PHONY: build $(BUILDS) run $(RUNS) clean $(CLEANS)

build: $(BUILDS)

$(BUILDS): %/build: %/src
	@$(MAKE) -C $<

run: $(RUNS)

$(RUNS): %/run: %/src %/build
	@echo "Running" $(patsubst %/run, %, $@)
	@$(MAKE) -C $< run

clean: $(CLEANS)

$(CLEANS): %/clean: %/src
	@$(MAKE) -C $< clean

-include Makefile.inc.movec-memsafe

-include Makefile.inc.addresssanitizer

-include Makefile.inc.softboundcets

-include Makefile.inc.valgrind
