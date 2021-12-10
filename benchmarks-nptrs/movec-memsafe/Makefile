TOOLNAME := movec-memsafe

SOURCES := $(sort $(wildcard ../src/*.c))
SHOWTIME := YES

include ../Makefile.default

$(OUTPUT_PROGRAMS): $(OUTPUT_DIR)/%: ../src/%.c $(OUTPUT_DIR)
	@echo "Instrumenting" $<
	$(MOVEC) --line-filename -c $< -o $@.c
	@echo "Building" $@
	$(INSTRU_CC) $(INSTRU_CC_OPTS) $@.c -o $@
