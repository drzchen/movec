TOOLNAME := addresssanitizer
INSTRU_CC = $(ASAN)

DIRS := $(sort $(patsubst ../src/%/Makefile, %, $(wildcard ../src/*/*/Makefile)))
COPY_MORE_MAKEFILES = \
for dir in $(DIRS); do \
  if [ -d ../src_makefiles/$${dir} ]; then \
    cp ../src_makefiles/$${dir}/Makefile $(OUTPUT_DIR)/$${dir}/Makefile; \
  fi; \
done

ERROR_FILES = $(patsubst ../src/%.c, $(OUTPUT_DIR)/%.error.txt, \
              $(wildcard ../src/*/*/*.c))

include ../../Makefile.default
