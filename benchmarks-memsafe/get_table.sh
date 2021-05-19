#!/bin/bash

## Set the table file
TABLE_FILE=$(pwd)/table.csv
rm -f ${TABLE_FILE}
export BENCHMARK_TABLE_FILE=${TABLE_FILE}

## Set the benchmarks to run
DIRS="SARD-testsuite-81  SARD-testsuite-88  SARD-testsuite-89
      SARD-testsuite-89-2  memsafe"

## Set the optimization level, e.g., OPTLVL=-O1, OPTLVL=-O2 or OPTLVL=-O3
## The default is empty, i.e., using -O0.
OPTLVL=
if [ -n ${OPTLVL} ]; then
    ASAN_OPTS="ASAN_OPTS=${OPTLVL}"
    SOCETS_OPTS="SOCETS_OPTS=${OPTLVL}"
    VALGRIND_OPTS="O=${OPTLVL}"
    MOVEC_OPTS="O=${OPTLVL}"
fi

## Write table header
echo "Suite,Programs,,,ASan ${OPTLVL},,,,SoCets ${OPTLVL},,,,Valgrind ${OPTLVL},,,,Movec ${OPTLVL},,,," >> ${TABLE_FILE};
echo "Name,T,B,G,E,G,N,G,E,G,N,G,E,G,N,G,E,G,N,G," >> ${TABLE_FILE};

## Run the original and the tools on each benchmark
line=2
for dir in ${DIRS}; do
    line=`expr $line + 1`;
    echo -n "${dir}," >> ${TABLE_FILE};

    ## Run AddressSanitizer
    make ${dir}/clean-addresssanitizer ;
    make ${dir}/output-addresssanitizer ${ASAN_OPTS} ;
    make ${dir}/run-addresssanitizer ;
    make ${dir}/clean-addresssanitizer ;

    ## Run Softbound-CETS
    make ${dir}/clean-softboundcets ;
    make ${dir}/output-softboundcets ${SOCETS_OPTS} ;
    make ${dir}/run-softboundcets ;
    make ${dir}/clean-softboundcets ;

    ## Run Valgrind
    make ${dir}/clean-valgrind ;
    make ${dir}/output-valgrind ${VALGRIND_OPTS} ;
    make ${dir}/run-valgrind ;
    make ${dir}/clean-valgrind ;

    ## Run Movec-memsafe
    make ${dir}/clean-movec-memsafe ;
    make ${dir}/output-movec-memsafe ${MOVEC_OPTS} ;
    make ${dir}/run-movec-memsafe ;
    make ${dir}/clean-movec-memsafe ;

    echo "" >> ${TABLE_FILE};
done

## Write table
echo "" >> ${TABLE_FILE};
echo "Total,=SUM(B3:B${line}),=SUM(C3:C${line}),=SUM(D3:D${line}),=SUM(E3:E${line}),=SUM(F3:F${line}),=SUM(G3:G${line}),=SUM(H3:H${line}),=SUM(I3:I${line}),=SUM(J3:J${line}),=SUM(K3:K${line}),=SUM(L3:L${line}),=SUM(M3:M${line}),=SUM(N3:N${line}),=SUM(O3:O${line}),=SUM(P3:P${line}),=SUM(Q3:Q${line}),=SUM(R3:R${line}),=SUM(S3:S${line}),=SUM(T3:T${line})," >> ${TABLE_FILE};
