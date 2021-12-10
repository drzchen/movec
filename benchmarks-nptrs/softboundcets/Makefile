TOOLNAME := softboundcets
INSTRU_CC = $(SOCETS)

SOURCES := $(sort $(wildcard ../src/*.c))
SHOWTIME := YES

include ../Makefile.default

$(OUTPUT_PROGRAMS): $(OUTPUT_DIR)/%: ../src/%.c $(OUTPUT_DIR)
	@echo "Instrumenting and Building" $@
	$(INSTRU_CC) $(INSTRU_CC_OPTS) $< -o $@
