DIRS := $(patsubst %, ../src/%, c-syntax all-mem-err nptrs)

TOOLNAME := addresssanitizer
INSTRU_CC = $(ASAN)

ERROR_FILES = $(patsubst ../src/%.c, $(OUTPUT_DIR)/%.error.txt, \
                  $(sort $(wildcard $(patsubst %, %/*.c, $(DIRS)))))

include ../../Makefile.default
