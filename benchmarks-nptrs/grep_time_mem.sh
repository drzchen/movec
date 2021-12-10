#!/bin/bash
# Grep the time and memory information from the files in arguments.
# Sum up the elapsed times in these files.
# Find out the maximum resident set size among them.

time=0
mrss=0
for file in $*
do
  line=$(cat ${file} | grep elapsed | grep avgtext | grep avgdata | grep maxresident)

  # Get an elapsed time in the [h:]mm:ss.mm format.
  elapsed=${line%elapsed*}
  elapsed=${elapsed##*"system "}
  # Convert to seconds.
  seconds=$(echo ${elapsed} | awk -F: '{ if (NF == 1) {print $NF} else if (NF == 2) {print $1 * 60 + $2} else if (NF==3) {print $1 * 3600 + $2 * 60 + $3} }')
  # Convert 0 second to 0.01 second due to the precision limit.
  if [ "${seconds}" = "0" ]; then seconds=0.01; fi
  # Sum up the seconds.
  time=$(echo "${time} + ${seconds}" | awk -F+ '{ print $1 + $2 }')

  # Get an maximum resident set size.
  maxresident=${line%maxresident*}
  maxresident=${maxresident##*"avgdata "}
  # Find out the maximum resident set size.
  if [ ${mrss} -lt ${maxresident} ]; then
    mrss=${maxresident}
  fi
  echo "Time:" ${elapsed} "    RSS:" ${maxresident}
done
echo "#### Elapsed (wall clock) time (seconds): ${time}"
echo "#### Maximum resident set size (kbytes): ${mrss}"

# Calculate time and mrss across multiple runs.
if [ -z "${BENCHMARK_RUN_TIMES}" ] || [ -z "${BENCHMARK_COUNT_DOWN}" ]; then
    # Write to the specified file.
    if [ -n "${BENCHMARK_TABLE_FILE}" ]; then
        echo -n "${time},${mrss}," >> ${BENCHMARK_TABLE_FILE}
    fi
else
    if [ ${BENCHMARK_COUNT_DOWN} -lt ${BENCHMARK_RUN_TIMES} ]; then # Sum up
        file_time=$(cat /tmp/benchmark_time)
        file_mrss=$(cat /tmp/benchmark_mrss)
        time=$(echo "${time} + ${file_time}" | awk -F+ '{ print $1 + $2 }')
        mrss=$(echo "${mrss} + ${file_mrss}" | awk -F+ '{ print $1 + $2 }')
    fi
    echo ${time} > /tmp/benchmark_time
    echo ${mrss} > /tmp/benchmark_mrss
    if [ ${BENCHMARK_COUNT_DOWN} -eq 1 ]; then       # After the last run
        time=$(cat /tmp/benchmark_time)              # Get the total time
        mrss=$(cat /tmp/benchmark_mrss)              # Get the total mrss
        mrss=`expr ${mrss} / ${BENCHMARK_RUN_TIMES}` # Get the average mrss
        echo "==== Total elapsed (wall clock) time (seconds): ${time}"
        echo "==== Average maximum resident set size (kbytes): ${mrss}"
        # Write to the specified file.
        if [ -n "${BENCHMARK_TABLE_FILE}" ]; then
            echo -n "${time},${mrss}," >> ${BENCHMARK_TABLE_FILE}
        fi
    fi
fi
