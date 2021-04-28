TOOLNAME := movec-memsafe
INSTRU_CC_OPTS := -pthread
SOURCES := $(sort $(shell find ../src -name *.c))
SOURCES_WITH_ERROR := $(patsubst ../src/%.c, %.c, $(SOURCES))

ERROR_FILES = $(patsubst ../src/%.c, $(OUTPUT_DIR)/%.error.txt, $(SOURCES))

include ../../Makefile.default

$(OUTPUT_PROGRAMS): $(OUTPUT_DIR)/%: ../src/%.c
	@echo "Instrumenting" $<
	$(MOVEC) -c $< -o $@.c
	@echo "Building" $@
	$(INSTRU_CC) $(INSTRU_CC_OPTS) $@.c -o $@
