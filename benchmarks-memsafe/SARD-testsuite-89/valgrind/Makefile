TOOLNAME := valgrind
INSTRU_BIN = $(VALGD)

ERROR_FILES = $(patsubst ../src/%.c, $(OUTPUT_DIR)/%.error.txt, \
                  $(sort $(wildcard ../src/*/*/*/*.c)))

include ../../Makefile.default
