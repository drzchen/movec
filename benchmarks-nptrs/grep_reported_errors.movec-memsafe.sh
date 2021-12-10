#!/bin/bash
# Grep the reported errors from the files in arguments.
# Sum up the number of the reported errors.

total_file=0;
sp_cnt=0;
tp_cnt=0;
sg_cnt=0;
ml_cnt=0;
empty_file=0;
nonex_file=0;

for file in $*; do
  total_file=$(expr ${total_file} + 1)
  if [ -s ${file} ]; then
    spatial=$(cat ${file} | grep "\[spatial error\]" | wc -l)
    temporl=$(cat ${file} | grep "\[temporal error\]" | wc -l)
    segment=$(cat ${file} | grep "\[segment error\]" | wc -l)
    memleak=$(cat ${file} | grep "error: memory leak" | wc -l)
    sp_cnt=$(expr ${sp_cnt} + ${spatial})
    tp_cnt=$(expr ${tp_cnt} + ${temporl})
    sg_cnt=$(expr ${sg_cnt} + ${segment})
    ml_cnt=$(expr ${ml_cnt} + ${memleak})
  elif [ -f ${file} ]; then
    empty_file=$(expr ${empty_file} + 1)
  else
    nonex_file=$(expr ${nonex_file} + 1)
  fi
done

if [ "${sp_cnt}" != "0" ] || [ "${tp_cnt}" != "0" ] ||
   [ "${sg_cnt}" != "0" ] || [ "${ml_cnt}" != "0" ]; then
    if [ "${sp_cnt}" != "0" ]; then msg=${msg}" SP=${sp_cnt}"; fi
    if [ "${tp_cnt}" != "0" ]; then msg=${msg}" TP=${tp_cnt}"; fi
    if [ "${sg_cnt}" != "0" ]; then msg=${msg}" SG=${sg_cnt}"; fi
    if [ "${ml_cnt}" != "0" ]; then msg=${msg}" ML=${ml_cnt}"; fi
    echo "#### Reported errors:${msg}"
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
  echo -n "${msg}," >> ${BENCHMARK_TABLE_FILE}
fi
