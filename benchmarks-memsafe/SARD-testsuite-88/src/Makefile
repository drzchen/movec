# Error number statistics:
# 283:1 285:27 287:4 289:2
# 291:1 293:1  295:1 297:28 299:2
# 301:3 303:7  305:3 307:1  309:2
# TOTAL: 83

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
