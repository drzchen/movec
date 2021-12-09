DIRS := $(patsubst %, ../src/%, c-syntax all-mem-err nptrs)

TOOLNAME := softboundcets
INSTRU_CC = $(SOCETS)

ERROR_FILES = $(patsubst ../src/%.c, $(OUTPUT_DIR)/%.error.txt, \
                  $(sort $(wildcard $(patsubst %, %/*.c, $(DIRS)))))

include ../../Makefile.default
