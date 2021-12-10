#!/bin/bash
# Grep the reported errors from the files in arguments.
# Sum up the number of the reported errors.

total_file=0;
error_cnt=0;
empty_file=0;
nonex_file=0;

for file in $*; do
  total_file=$(expr ${total_file} + 1)
  if [ -s ${file} ]; then
    error=$(cat ${file} | grep "Softboundcets: " | wc -l)
    error_cnt=$(expr ${error_cnt} + ${error})
  elif [ -f ${file} ]; then
    empty_file=$(expr ${empty_file} + 1)
  else
    nonex_file=$(expr ${nonex_file} + 1)
  fi
done

if [ "${error_cnt}" != "0" ]; then
    echo "#### Reported errors: ${error_cnt}"
elif [ "${empty_file}" != "0" ]; then
    echo "#### No error is recorded."
    echo "#### You need to manually check"\
         "as ${empty_file}/${total_file} output files are empty."
else
    echo "#### No error is reported."
fi
if [ "${nonex_file}" != "0" ]; then
    echo "#### ${nonex_file}/${total_file} output files do not exist."
fi

# Write to the specified file.
if [ -n "${BENCHMARK_TABLE_FILE}" ]; then
  if [ "${error_cnt}" = "0" ]; then error_cnt=""; fi
  echo -n "${error_cnt}," >> ${BENCHMARK_TABLE_FILE}
fi
