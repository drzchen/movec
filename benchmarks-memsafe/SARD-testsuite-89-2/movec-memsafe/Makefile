DIRS := $(sort $(patsubst ../src/%/Makefile, %, $(wildcard ../src/*/*/Makefile)))
DIRS_ORDINARY_RULE := $(filter-out $(DIRS_ADHOC_RULE), $(DIRS))
OUTPUT_DIRS = $(patsubst %, $(OUTPUT_DIR)/%, $(DIRS))
OUTPUT_DIRS_ORDINARY_RULE = $(patsubst %, $(OUTPUT_DIR)/%, $(DIRS_ORDINARY_RULE))

TOOLNAME := movec-memsafe
CUSTOM_INSTRU_TARGETS = $(OUTPUT_DIRS)

ERROR_FILES = $(patsubst ../src/%.c, $(OUTPUT_DIR)/%.error.txt, \
              $(wildcard ../src/*/*/*.c))

include ../../Makefile.default

# Ordinary benchmarks.
$(OUTPUT_DIRS_ORDINARY_RULE): $(OUTPUT_DIR)/%: ../src/% $(wildcard ../src/%/*.c)
	@$(MKDIR) --parents $@
	@echo "Instrumenting" $<
	@$(MOVEC) -p $< -d $@
	@$(COPY) $(shell echo $< | sed "s/src/src_makefiles/g")/Makefile $@/Makefile
	@echo "Building" $@
	@export INSTRU_CC="$(INSTRU_CC) $(INSTRU_CC_OPTS)"; $(MAKE) -C $@
