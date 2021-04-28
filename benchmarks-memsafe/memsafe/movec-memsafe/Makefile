DIRS := $(patsubst %, ../src/%, c-syntax all-mem-err nptrs)

TOOLNAME := movec-memsafe
INSTRU_CC_OPTS := -D_RV_NORANDOM
SOURCES := $(sort $(wildcard $(patsubst %, %/*.c, $(DIRS))))
SOURCES_WITH_ERROR := \
       all-mem-err/1_np.c \
       all-mem-err/1_up.w.c \
       all-mem-err/3_temporal_df.c \
       all-mem-err/5_segment_id_1.w.c \
       all-mem-err/5_segment_id_2.c \
       all-mem-err/5_segment_id_exploit.c \
       all-mem-err/5_segment_if_1.c \
       all-mem-err/5_segment_if_2.c \
       all-mem-err/s3_wf_stdlib_free.c \
       all-mem-err/s3_wf_string.c \
       c-syntax/2_psk_cf.c \
       c-syntax/2_psk_vg.w.c \
       nptrs/1n_psk_vsk.w.c \
       nptrs/nn_ph_vsk.w.c
SHOWTIME := YES

ERROR_FILES = $(patsubst ../src/%.c, $(OUTPUT_DIR)/%.error.txt, $(SOURCES))

include ../../Makefile.default

$(OUTPUT_PROGRAMS): $(OUTPUT_DIR)/%: ../src/%.c
	@echo "Instrumenting" $<
	$(MOVEC) --line-filename -c $< -o $@.c
	@echo "Building" $@
	$(INSTRU_CC) $(INSTRU_CC_OPTS) $@.c -o $@

# Additional scripts for comparing with the expected outputs.
SOURCES_NO_DIFF := \
       all-mem-err/1_up.w.c \
       all-mem-err/s3_wfv_stdio_printf.c
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
