MAKDIRS := $(sort $(patsubst %/Makefile, %, $(wildcard */Makefile)))
MAKDIRS_BUILDS := $(patsubst %, %/all, $(MAKDIRS))
MAKDIRS_RUNS   := $(patsubst %, %/run, $(MAKDIRS))
MAKDIRS_CLEANS := $(patsubst %, %/clean, $(MAKDIRS))

.PHONY: build run clean $(MAKDIRS_BUILDS) $(MAKDIRS_RUNS) $(MAKDIRS_CLEANS)
# Ignore the runs that will cause errors.
.IGNORE: $(MAKDIRS_RUNS)
.SUFFIXES: # Delete the default suffixes

build: $(MAKDIRS_BUILDS)
	@echo "***Successfully built all benchmarks."

$(MAKDIRS_BUILDS): %/all: %
	@echo "Building" $<
	@$(MAKE) -C $< all --no-print-directory

run: $(MAKDIRS_RUNS)
	@echo "***Successfully ran all benchmarks."

$(MAKDIRS_RUNS): %/run: %
	@echo "Running" $<
	@$(MAKE) -C $< run --no-print-directory

clean: $(MAKDIRS_CLEANS)

$(MAKDIRS_CLEANS): %/clean: %
	@$(MAKE) -C $< clean --no-print-directory
