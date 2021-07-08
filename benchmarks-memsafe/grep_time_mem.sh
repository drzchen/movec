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
