TOOLNAME := valgrind
INSTRU_BIN = $(VALGD)

ERROR_FILES = $(patsubst ../src/%.c, $(OUTPUT_DIR)/%.error.txt, \
                  $(sort $(wildcard ../src/src/*.c)))

include ../../Makefile.default
