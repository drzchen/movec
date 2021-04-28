TOOLNAME := movec-memsafe
INSTRU_CC_OPTS := -D_RV_NORANDOM
SOURCES := $(sort $(wildcard ../src/src/*.c))
SOURCES_WITH_ERROR := $(patsubst ../src/%.c, %.c, $(SOURCES))

ERROR_FILES = $(patsubst ../src/%.c, $(OUTPUT_DIR)/%.error.txt, $(SOURCES))

include ../../Makefile.default

$(OUTPUT_PROGRAMS): $(OUTPUT_DIR)/%: ../src/%.c
	@echo "Instrumenting" $<
	$(MOVEC) --line-filename -c $< -o $@.c
	@echo "Building" $@
	$(INSTRU_CC) $(INSTRU_CC_OPTS) $@.c -o $@

# Additional scripts for comparing with the expected outputs.
SOURCES_NO_DIFF := NONE.c
DIFFS := $(patsubst ../src/%.c, $(OUTPUT_DIR)/%.diff, $(SOURCES))

.PHONY: diff $(DIFFS)
# Ignore the runs that will cause errors.
.IGNORE: $(patsubst %.c, $(OUTPUT_DIR)/%.diff, $(SOURCES_NO_DIFF))

diff: $(DIFFS)
	@echo "***Successfully compared all outputs."

$(DIFFS): $(OUTPUT_DIR)/%.diff: $(OUTPUT_DIR)/%.output.txt expected_outputs/%.output.txt $(OUTPUT_DIR)/%.error.txt expected_outputs/%.error.txt
	@echo "Comparing" $(word 1, $^) $(word 2, $^)
	@diff $(word 1, $^) $(word 2, $^)
	@diff $(word 3, $^) $(word 4, $^)
