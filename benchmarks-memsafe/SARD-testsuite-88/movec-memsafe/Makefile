DIRS := $(sort $(patsubst ../src/%/Makefile, %, $(wildcard ../src/*/Makefile)))
DIRS_WITH_ERROR := 285 287 289 291 293 295 297 299 303 305 307 309
DIRS_ADHOC_RULE := 289 290 291 292 293 294 307 308 309 310
DIRS_ORDINARY_RULE := $(filter-out $(DIRS_ADHOC_RULE), $(DIRS))
OUTPUT_DIRS = $(patsubst %, $(OUTPUT_DIR)/%, $(DIRS))
OUTPUT_DIRS_ORDINARY_RULE = $(patsubst %, $(OUTPUT_DIR)/%, $(DIRS_ORDINARY_RULE))

TOOLNAME := movec-memsafe
CUSTOM_INSTRU_TARGETS = $(OUTPUT_DIRS)

ERROR_FILES = $(patsubst ../src/%.c, $(OUTPUT_DIR)/%.error.txt, \
              $(wildcard ../src/*/*-ok.c) $(wildcard ../src/*/*-bad.c))

include ../../Makefile.default

# Ordinary benchmarks.
$(OUTPUT_DIRS_ORDINARY_RULE): $(OUTPUT_DIR)/%: ../src/% $(wildcard ../src/%/*.c)
	@$(MKDIR) --parents $@
	@echo "Instrumenting" $<
	@$(MOVEC) -p $< -d $@
	@$(COPY) $(shell echo $< | sed "s/src/src_makefiles/g")/Makefile $@/Makefile
	@echo "Building" $@
	@export INSTRU_CC="$(INSTRU_CC) $(INSTRU_CC_OPTS)"; $(MAKE) -C $@

# Benchmark 289.
$(OUTPUT_DIR)/289: ../src/289  $(wildcard ../src/289/*.c)
	@$(MKDIR) --parents $@
	@$(COPY) -r $< $@/..
	@echo "Instrumenting" $<
	@$(MOVEC) -c $</ns-lookup-bad.c -o $@/ns-lookup-bad.c
	@$(COPY) $(shell echo $< | sed "s/src/src_makefiles/g")/Makefile $@/Makefile
	@echo "Building" $@
	@export INSTRU_CC="$(INSTRU_CC) $(INSTRU_CC_OPTS)"; $(MAKE) -C $@

# Benchmark 290.
$(OUTPUT_DIR)/290: ../src/290  $(wildcard ../src/290/*.c)
	@$(MKDIR) --parents $@
	@$(COPY) -r $< $@/..
	@echo "Instrumenting" $<
	@$(MOVEC) -c $</ns-lookup-ok.c -o $@/ns-lookup-ok.c
	@$(COPY) $(shell echo $< | sed "s/src/src_makefiles/g")/Makefile $@/Makefile
	@echo "Building" $@
	@export INSTRU_CC="$(INSTRU_CC) $(INSTRU_CC_OPTS)"; $(MAKE) -C $@

# Benchmark 291.
$(OUTPUT_DIR)/291: ../src/291  $(wildcard ../src/291/*.c)
	@$(MKDIR) --parents $@
	@$(COPY) -r $< $@/..
	@echo "Instrumenting" $<
	@$(MOVEC) -c $</sig-bad.c -o $@/sig-bad.c
	@$(COPY) $(shell echo $< | sed "s/src/src_makefiles/g")/Makefile $@/Makefile
	@echo "Building" $@
	@export INSTRU_CC="$(INSTRU_CC) $(INSTRU_CC_OPTS)"; $(MAKE) -C $@

# Benchmark 292.
$(OUTPUT_DIR)/292: ../src/292  $(wildcard ../src/292/*.c)
	@$(MKDIR) --parents $@
	@$(COPY) -r $< $@/..
	@echo "Instrumenting" $<
	@$(MOVEC) -c $</sig-ok.c -o $@/sig-ok.c
	@$(COPY) $(shell echo $< | sed "s/src/src_makefiles/g")/Makefile $@/Makefile
	@echo "Building" $@
	@export INSTRU_CC="$(INSTRU_CC) $(INSTRU_CC_OPTS)"; $(MAKE) -C $@

# Benchmark 293.
$(OUTPUT_DIR)/293: ../src/293  $(wildcard ../src/293/*.c)
	@$(MKDIR) --parents $@
	@$(COPY) -r $< $@/..
	@echo "Instrumenting" $<
	@$(MOVEC) -c $</nxt-bad.c -o $@/nxt-bad.c
	@$(COPY) $(shell echo $< | sed "s/src/src_makefiles/g")/Makefile $@/Makefile
	@echo "Building" $@
	@export INSTRU_CC="$(INSTRU_CC) $(INSTRU_CC_OPTS)"; $(MAKE) -C $@

# Benchmark 294.
$(OUTPUT_DIR)/294: ../src/294  $(wildcard ../src/294/*.c)
	@$(MKDIR) --parents $@
	@$(COPY) -r $< $@/..
	@echo "Instrumenting" $<
	@$(MOVEC) -c $</nxt-ok.c -o $@/nxt-ok.c
	@$(COPY) $(shell echo $< | sed "s/src/src_makefiles/g")/Makefile $@/Makefile
	@echo "Building" $@
	@export INSTRU_CC="$(INSTRU_CC) $(INSTRU_CC_OPTS)"; $(MAKE) -C $@

# Benchmark 307 308.
$(OUTPUT_DIR)/307 $(OUTPUT_DIR)/308: $(OUTPUT_DIR)/%: ../src/%  $(wildcard ../src/%/*.c)
	@$(MKDIR) --parents $@
	@echo "Instrumenting" $<
	@$(MOVEC) -p $< -d $@ --included $</sendmail.h
	@$(COPY) $(shell echo $< | sed "s/src/src_makefiles/g")/Makefile $@/Makefile
	@echo "Building" $@
	@export INSTRU_CC="$(INSTRU_CC) $(INSTRU_CC_OPTS)"; $(MAKE) -C $@

# Benchmark 309 310.
$(OUTPUT_DIR)/309 $(OUTPUT_DIR)/310: $(OUTPUT_DIR)/%: ../src/% $(wildcard ../src/%/*.c)
	@$(MKDIR) --parents $@
	@echo "Instrumenting" $<
	@$(MOVEC) -p $< -d $@ --included $</txt-dns.h
	@$(COPY) $(shell echo $< | sed "s/src/src_makefiles/g")/Makefile $@/Makefile
	@echo "Building" $@
	@export INSTRU_CC="$(INSTRU_CC) $(INSTRU_CC_OPTS)"; $(MAKE) -C $@
