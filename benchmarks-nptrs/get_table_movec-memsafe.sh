#!/bin/bash
# You may use command arguments: O1, O2, O3, clean.

# Convert an integer into a column string, e.g., 1->A, ..., 26->Z,
# 27->AA, ..., 52->AZ, 53->BA, ..., 78->BZ, 79->CA and so on.
function get_column()
{
  quotient=`expr $1 / 26`
  reminder=`expr $1 % 26`
  if [[ ${quotient} != "0" && ${reminder} == "0" ]]; then
    quotient=`expr ${quotient} - 1`
    reminder=`expr 26`
  fi;
  # Get the charactor c1
  if [ ${quotient} != "0" ]; then
    quotient=`expr ${quotient} + 64`
    c1=$(printf \\x`printf %x ${quotient}`);
  fi;
  # Get the charactor c2
  reminder=`expr ${reminder} + 64`
  c2=$(printf \\x`printf %x ${reminder}`);
  # Get the column string
  echo ${c1}${c2}
  return $?
}

## Set the file prefix
PREF=nptrs

## Set the benchmarks to run
SRCS=$(ls src/*.c)       # a list of source files
for src in ${SRCS}; do
    src=${src#src/}
    DIRS="${DIRS} ${src%.c}"
done

## Set the optimization level, e.g., OPTLVL=-O1, OPTLVL=-O2 or OPTLVL=-O3
## The default is empty, i.e., using -O0.
if [[ $* =~ "O1" ]]; then OPTLVL="-O1"; fi
if [[ $* =~ "O2" ]]; then OPTLVL="-O2"; fi
if [[ $* =~ "O3" ]]; then OPTLVL="-O3"; fi
if [ -n ${OPTLVL} ]; then
    MOVEC_OPTLVL="O=${OPTLVL}"
fi

## Set different options for Movec-memsafe
OPTIONNAME[0]="hashtable-nopmdvar"
MOVEC_OPTS[0]="--ms-hashtbl --ms-no-pmd-var"

OPTIONNAME[1]="trie-nopmdvar"
MOVEC_OPTS[1]="--ms-trie --ms-no-pmd-var"

OPTIONNAME[2]="hashtable-pmdvar"
MOVEC_OPTS[2]="--ms-hashtbl"

OPTIONNAME[3]="trie-pmdvar"
MOVEC_OPTS[3]="--ms-trie"

OPTIONNAME[4]="hashtable-pmdvar-nocheck"
MOVEC_OPTS[4]="--ms-hashtbl --ms-no-check"

OPTIONNAME[5]="trie-pmdvar-nocheck"
MOVEC_OPTS[5]="--ms-trie --ms-no-check"

## Set the table file
TABLE_FILE=$(pwd)/table_${PREF}.movec-memsafe${OPTLVL}.csv
rm -f ${TABLE_FILE}
export BENCHMARK_TABLE_FILE=${TABLE_FILE}
## Clean the output files
rm -f ${PREF}.original-O3
for(( i=0;i<${#OPTIONNAME[@]};i++ )) do
    rm -f ${PREF}.movec-memsafe-${OPTIONNAME[i]}${OPTLVL}
done
if [[ $* =~ "clean" ]]; then exit; fi

## Write table header
echo -n "Programs,Original -O3,," >> ${TABLE_FILE};
for(( i=0;i<${#OPTIONNAME[@]};i++ )) do
    echo -n "Movec ${OPTIONNAME[i]}${OPTLVL},,,,," >> ${TABLE_FILE};
done
echo "" >> ${TABLE_FILE};

echo -n ",time,mem," >> ${TABLE_FILE};
for(( i=0;i<${#OPTIONNAME[@]};i++ )) do
    echo -n "time,mem,error,T.R.,M.R.," >> ${TABLE_FILE};
done
echo "" >> ${TABLE_FILE};

## Run the original and Movec with different options on each benchmark
line=2
for dir in ${DIRS}; do
    line=`expr $line + 1`;
    echo -n "${dir}," >> ${TABLE_FILE};

    ## Run original -O3
    make ${dir}/clean ;
    make ${dir}/build ;
    make ${dir}/run >> ${PREF}.original-O3 2>&1 ;
    make ${dir}/clean ;

    ## Run Movec-memsafe
  column=3
  for(( i=0;i<${#OPTIONNAME[@]};i++ )) do
    make ${dir}/clean-movec-memsafe ;
    make ${dir}/output-movec-memsafe MOVEC_OPTS="${MOVEC_OPTS[i]}" ${MOVEC_OPTLVL} ;
    make ${dir}/run-movec-memsafe >> ${PREF}.movec-memsafe-${OPTIONNAME[i]}${OPTLVL} 2>&1 ;
    make ${dir}/clean-movec-memsafe ;
    column=`expr $column + 1`;
    column1=$(get_column $column)
    column=`expr $column + 1`;
    column2=$(get_column $column)
    column=`expr $column + 3`;
    echo -n "\"=ROUND(${column1}${line}/B${line},2)\",\"=ROUND(${column2}${line}/C${line},2)\"," >> ${TABLE_FILE};
  done

    echo "" >> ${TABLE_FILE};
done

## Write table
echo "" >> ${TABLE_FILE};
echo -n "AVERAGE,,," >> ${TABLE_FILE};
column=3
for(( i=0;i<${#OPTIONNAME[@]};i++ )) do
    column=`expr $column + 4`;
    column1=$(get_column $column)
    column=`expr $column + 1`;
    column2=$(get_column $column)
    echo -n ",,,\"=ROUND(AVERAGE(${column1}3:${column1}${line}),2)\",\"=ROUND(AVERAGE(${column2}3:${column2}${line}),2)\"," >> ${TABLE_FILE};
done
