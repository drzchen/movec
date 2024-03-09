THE MOVEC PROJECT - Artifact - README
================================================================================

Copyright (C) Zhe Chen.
All rights reserved.

Movec is a dynamic analysis tool that implements a smart-status-based monitoring algorithm (called Smatus) and a source-level instrumentation framework, a compiler (more precisely, a source-to-source transformer) that implements an aspect-oriented C programming language, called Aclang, and a runtime verification tool that implements a parallel parametric monitoring algorithm.
Movec transforms a C source file to an instrumented C source file that can be compiled by a standard C compiler such as gcc.
This document presents step-by-step instructions on how to run Movec on the associated benchmark suites.

# 1. Getting Started

This section demonstrates how to set up the artifact and validate its general functionality (e.g., based on a small example) in less than 30 min.

This artifact contains the following sub-directories:

* bin: It contains the binary executable files of Movec and the related tools for comparison, e.g., ACC, AspectC++, ASan, SoCets and Valgrind.
* examples: It contains some small examples for testing Movec.
* benchmarks-memsafe: It contains the SARD and MSBench benchmark suites.
* benchmarks-nptrs: It contains the Nptrs benchmark suite.
* benchmarks-prv: It contains the parametric runtime verification benchmark suite.
* related-tools: It contains the related tools for comparison, e.g., ACC, AspectC++, ASan, SoCets and Valgrind, possibly in the forms of pre-compiled binary (`*-bin`), source package (`*-src`) or Debian package (`*-deb`). You can use any form working on your system.

The following benchmark suites, mentioned in our papers, can be separately downloaded at [Movec-benchmarks](https://github.com/drzchen/movec-benchmarks).

* benchmarks-mibench: It contains the MiBench benchmark suite.
* benchmarks-mibench-safer: A safer version of the MiBench benchmark suite.
* benchmarks-spec-cpu-2017: It contains the SPEC CPU 2017 benchmark suite.
* benchmarks-spec-cpu-2017-safer: A safer version of the SPEC CPU 2017 benchmark suite.

You may set up the artifact with Docker or manually, explained in Sections 1.1 and 1.2 below, respectively. We recommend to set up with Docker.

## 1.1 Setting Up with Docker

You can build a Docker image for artifact evaluation by using the accompanying Dockerfile and following the commented instructions in the Dockerfile. When the image is built, you can run it to reproduce the results.
If you can successfully build and run such a Docker image, you can safely skip Section 1.2 and jump to Section 1.3.

## 1.2 Setting Up Manually

If you do not want to use Docker, you need to set up the artifact manually.
Movec is developed and extensively tested on Ubuntu 22.04 LTS 64-bit. It may also work on other compatible Linux releases (e.g., Ubuntu 20.04), but it is not guaranteed to do so.

### 1.2.1 Installing Software

Compiling the programs in the benchmark suites and evaluating tools on them require that you have several software packages installed.

1\. Unix utilities: cd, cp, find, mkdir, mv, rm, GNU time.
These utilities usually have been installed with your OS by default, except GNU time.
You can install them from the Ubuntu software repository using apt-get.
```Bash
    $ sudo apt-get install time
```

2\. Compilation utilities: cmake, gcc, g++, make.
You can install them from the Ubuntu software repository using apt-get.
```Bash
    $ sudo apt-get install cmake gcc g++ make
```

3\. Libraries: libncurses.
You can install them from the Ubuntu software repository using apt-get.
```Bash
    $ sudo apt-get install libncurses5-dev
```

4\. Bear: a tool that generates a JSON compilation database for the make command.
Movec depends on a JSON compilation database when instruments a project containing multiple source files. Thus you should install Bear. You can install Bear from the Ubuntu software repository using apt-get.
```Bash
    $ sudo apt-get install bear    [version 3.0.18 works]
```

### 1.2.2 Setting Up Movec

You only need to add the bin directory to your PATH. To ensure that Movec is in your PATH, you can use the following command to invoke Movec and print its options.
```Bash
    $ export PATH=<full-path>/bin:$PATH [or modify ~/.bashrc or /etc/profile]
    $ movec -h
```
Note that some of the listed options are not available in this version, and using them takes no effect. If you are not familiar with these user options, please learn from the following instructions.

If the command cannot be found, please check whether your PATH indeed includes the bin directory.
```Bash
    $ echo $PATH
```

Note that ACC, AspectC++, ASan, SoCets and Valgrind (Sections 1.2.3 to 1.2.7 below) are NOT required for the running/evaluation of Movec, but only used for comparison. If you only need to run/evaluate Movec, or you fail to install them on your system, you can safely skip them.

### 1.2.3 Setting Up ACC

This artifact includes ACC's source package. You can compile and install ACC from source by following the instructions in its source package.

### 1.2.4 Setting Up AspectC++

We suggest to install AspectC++ 2.3 (released on Feb 17 2021) for our experiments. You can download its source package from [AspectC++'s page](https://www.aspectc.org/Download.php).

After obtaining its source package, you can compile and install AspectC++ from source by following the instructions in its source package.

### 1.2.5 Setting Up ASan

ASan has been integrated into Clang (starting from version 3.1), GCC (starting from version 4.8) and Xcode (starting from version 7.0). This means, you only need to install Clang, GCC or Xcode to use ASan. We suggest to install Clang 14.0.6 for our experiments. You can download its source package from [Clang's page](http://clang.llvm.org/).

After obtaining its source package, you can compile and install Clang from source by following the following instructions.

* Change directory to where you want the llvm directory placed, and extract the source package llvm-project-xx.yy.zz.src.tar.xz in the directory, rename the obtained directory to llvm-project.
* Build the LLVM project.
```Bash
    $ cd llvm-project
    $ mkdir build # [in-tree build is not supported]
    $ cd build
    $ cmake -DLLVM_ENABLE_PROJECTS="clang;clang-tools-extra" -DLLVM_ENABLE_RUNTIMES="compiler-rt" -DCMAKE_BUILD_TYPE=Release -DLLVM_ENABLE_ASSERTIONS=On -G "Unix Makefiles" ../llvm
    $ make # [or make -j]
    $ sudo make install # [Optional, otherwise you should add the bin directory to PATH]
```
The 4th command above uses `../llvm/` which should be the path to the directory where the source package of the llvm sub-project is placed. The 5th command runs a serial build which will be slow. You may run a parallel build, for make, use make -j. The last command installs LLVM header files, libraries, tools, and documentation in a hierarchy under `$PREFIX`, specified with `CMAKE_INSTALL_PREFIX`, which defaults to /usr/local. If you do not want to install, add build/bin to your PATH.

### 1.2.6 Setting Up SoCets

We suggest to install SoCets 3.4 for our experiments. You can download its source package from [SoftboundCets' page](https://www.cs.rutgers.edu/~santosh.nagarakatte/softbound/).

After obtaining its source package, you can compile and install SoCets from source by following the instructions in its source package.

Note that SoCets is actually a modified Clang 3.4, thus DO NOT add its bin directory to your PATH, to avoid the conflict with your Clang.

### 1.2.7 Setting Up Valgrind

Valgrind can be installed from any GNU Unix software repositories using apt-get or yum. For example, on Debian/Ubuntu-like distributions, do
```Bash
    $ sudo apt-get install valgrind    [version 3.18.1 works]
```

If you do not have an Internet connection, you can first download its Debian package with all dependencies on another machine as follows:
```Bash
    $ mkdir where-you-put-packages
    $ cd where-you-put-packages
    $ sudo apt-get update
    $ apt-get --print-uris install valgrind | grep "^'" | sed "s/^'\([^']*\)'.*$/\1/g" > valgrind.deps
    $ for i in $(cat valgrind.deps) ; do wget -nv $i ; done
```

After obtaining these Debian packages, you can install Valgrind from these packages by following the following instructions.
```Bash
    $ cd where-you-put-packages/
    $ sudo dpkg -i *.deb
```

## 1.3 Testing Movec

1\. Instrumenting a single source file

Go to the examples directory and try Movec on a source file.

Let us detect a memory error in a C program `subobject.c` at runtime by generating, compiling and running an instrumented source file `output.c`.
```Bash
    $ cd examples/
    $ movec --check-memsafe -c subobject.c -o output.c
    $ gcc output.c
    $ ./a.out
```
The second command above invokes Movec to generate the instrumented source file `output.c` and the auxiliary header and source files in the same directory. Note that Movec also supports some key compiler options, e.g., -I and -D. Before running gcc, please ensure that these files have not been polluted, e.g., do not modify them, do not run Movec on another source file in the same directory. The last command runs the instrumented program and should detect and print an error at runtime, in the following way:
```
subobject.c: In function 'main':
subobject.c:13:5: error: dereferenced pointer 'p[1]' (val = 0x7ffc1f71d1c4, size = 4) is out of the block [0x7ffc1f71d1c0, 0x7ffc1f71d1c4). [spatial error]
1 error generated.
```

For `segment.c`, a similar list of commands, using `segment.c` instead of `subobject.c` in the second command, should detect and print an error at runtime, in the following way:
```
segment.c: In function 'main':
segment.c:18:15: error: dereferenced pointer 's[0]' (val = 0x40c6e0, size = 1) points to a function 0x40c6e0, not a data block. [segment error]
1 error generated.
```

Let us go to directory `advice-call`, and weave a C program `main.c` and an aspect file `aspect.mon` by generating, compiling and running an instrumented source file `output.c`.
```Bash
    $ cd examples/advice-call
    $ movec -c main.c -m aspect.mon -o output.c
    $ gcc output.c
    $ ./a.out
```
The second command above invokes Movec to generate the instrumented source file `output.c` and the auxiliary header and source files in the same directory. Note that Movec also supports some key compiler options, e.g., -I and -D. Before running gcc, please ensure that these files have not been polluted, e.g., do not modify them, do not run Movec on another source file in the same directory. The last command runs the instrumented program and should print the following message at runtime:
```
before 1.around 1.before 2.around 2.around 3.after 2.after 1.
```

You need to remove the generated files before you try the next example.
```Bash
    $ rm output.c _RV_* a.out [this is obligatory if you will try another example]
```

For directory `advice-get`, a similar list of commands should print the following message at runtime:
```
before 1.around 1.before 2.around 2.around 3.after 2.after 1.
before 1.around 1.before 2.around 2.around 3.after 2.after 1.
```

You need to remove the generated files before you try the next example.
```Bash
    $ rm output.c _RV_* a.out [this is obligatory if you will try another example]
```

2\. Instrumenting multiple source files

Let us try Movec on a project containing multiple source files.

The `multi-files` directory contains a project, which is actually equivalent to `segment.c`. There are several ways for instrumenting multiple files in a project. Let us try them one by one.

(1) The first way is to specify the source files in a list using `-c` and the instrumented files in another list using `-o`:
```Bash
  $ cd multi-files/
  $ movec --check-memsafe -c foo.c func.c main.c -o foo1.c func1.c main1.c
  $ gcc foo1.c func1.c main1.c
  $ ./a.out
```
The second command above invokes Movec to generate an instrumented file for each source file, e.g., `foo1.c` for `foo.c`, and the auxiliary header and source files in the same directory. Before running gcc (or make in the subsequent ways), please ensure that these files have not been polluted, e.g., do not modify them, do not run Movec on another source file in the same directory. The last command runs the instrumented program and the error should be detected and printed at runtime.

(2) One may want to put the instrumented files in another directory. The second way is to generate all the instrumented files in the directory specified by `-d`:
```Bash
  $ cd multi-files/
  $ movec --check-memsafe -c foo.c func.c main.c -d ../output
  $ cd ../output/
  $ gcc foo.c func.c main.c
  $ ./a.out
```

(3) One may want to specify the input directory instead of a list of source files when there are many source files. The third way is to specify the input directory using `-p` and the output directory using `-d`:
```Bash
  $ movec --check-memsafe -p multi-files/ -d output
  $ cd output/
  $ make
  $ ./all
```
The first command recursively traverses the input directory to find all source files with the suffix `.h` or `.c` and, for each source file, generates a corresponding instrumented file in the output directory. Thus you need to `make clean` and remove the generated files (e.g., `_RV_*` files) in the input directory before running the first command. Note that all other files in the input directory are also copied to the output directory, e.g., the Makefile.

(4) The fourth way is to specify the compilation database using `-b` and the output directory using `-d`:
```Bash
  $ cd multi-files/
  $ bear -- make     [generate a JSON compilation database]
  $ cd ..
  $ movec --check-memsafe -b multi-files/compile_commands.json -d output
  $ cd output/
  $ make
  $ ./all
```
The second command above generates a compilation database named `compile_commands.json` in the directory containing the Makefile. Do not run `bear -- make` again, otherwise the JSON file is empty. Note that this is the most convenient way when the compilation process is complex, e.g., when there are too many files to be manually listed and compiling each source file uses different compiler options.

The `advice-call-multi-files` directory contains a project, which is actually equivalent to `advice-call`. There are several ways for instrumenting multiple files in a project. Let us try them one by one.

(1) The first way is to specify the source files in a list using `-c` and the instrumented files in another list using `-o`:
```Bash
  $ cd advice-call-multi-files/
  $ movec -c func.c main.c -m aspect.mon -o func1.c main1.c
  $ gcc func1.c main1.c
  $ ./a.out
```
The second command above invokes Movec to generate an instrumented file for each source file, e.g., `func1.c` for `func.c`, and the auxiliary header and source files in the same directory. Before running gcc (or make in the subsequent ways), please ensure that these files have not been polluted, e.g., do not modify them, do not run Movec on another source file in the same directory. The last command runs the instrumented program and a message should be printed at runtime.

You need to remove the generated files before you try the next example.
```Bash
  $ rm func1.c main1.c _RV_* a.out [this is obligatory if you will try another example]
```

(2) One may want to put the instrumented files in another directory. The second way is to generate all the instrumented files in the directory specified by `-d`:
```Bash
  $ cd advice-call-multi-files/
  $ movec -c func.c main.c -m aspect.mon -d ../output
  $ cd ../output/
  $ gcc func.c main.c
  $ ./a.out
```

You need to remove the generated files before you try the next example.
```Bash
  $ cd .. && rm -rf output [this is obligatory if you will try another example]
```

(3) One may want to specify the input directory instead of a list of source files when there are many source files. The third way is to specify the input directory using `-p` and the output directory using `-d`:
```Bash
  $ movec -p advice-call-multi-files/ -m advice-call-multi-files/aspect.mon -d output
  $ cd output/
  $ make
  $ ./all
```
The first command recursively traverses the input directory to find all source files with the suffix `.h` or `.c` and, for each source file, generates a corresponding instrumented file in the output directory. Thus you need to `make clean` and remove the generated files (e.g., `_RV_*` files) in the input directory before running the first command. Note that all other files in the input directory are also copied to the output directory, e.g., the Makefile.

You need to remove the generated files before you try the next example.
```Bash
  $ cd .. && rm -rf output [this is obligatory if you will try another example]
```

(4) The fourth way is to specify the compilation database using `-b` and the output directory using `-d`:
```Bash
  $ cd advice-call-multi-files/
  $ bear -- make     [generate a JSON compilation database]
  $ cd ..
  $ movec -b advice-call-multi-files/compile_commands.json -m advice-call-multi-files/aspect.mon -d output
  $ cd output/
  $ make
  $ ./all
```
The second command above generates a compilation database named `compile_commands.json` in the directory containing the Makefile. Do not run `bear -- make` again, otherwise the JSON file is empty. Note that this is the most convenient way when the compilation process is complex, e.g., when there are too many files to be manually listed and compiling each source file uses different compiler options.

You need to remove the generated files before you try the next example.
```Bash
  $ cd .. && rm -rf output [this is obligatory if you will try another example]
  $ cd advice-call-multi-files && rm all compile_commands.json
```

# 2. Step by Step Instructions

This section describes how to validate the paper’s claims and results in detail.

## 2.1 Setting Up the Benchmark Suites

The directory of each benchmark suite (e.g., SARD+MSBench, Nptrs, MiBench, SPEC) contains several files. Please read the following files:

* Makefile.default.TOOL (or Makefile.default for SARD+MSBench and Nptrs): It contains the script for running a TOOL on a benchmark program. Note that you should correctly set the path of the TOOL's executable file at the beginning lines of this file (after comments). The default path is set for the Docker image.
* COMPILE: It explains how to compile/instrument/run all benchmarks or one selected benchmark. You should follow the instructions in this file to run the tools.

The directory of each benchmark suite (e.g., SARD+MSBench, MiBench, SPEC) contains several sub-directories. Each sub-directory contains a benchmark program (but multiple programs for SARD+MSBench). The directory of each benchmark program also contains several sub-directories:

* src: It contains the original source code of the program.
* movec-memsafe: It contains the Makefile for running Movec on the program to detect memory errors.
* movec-monitor: It contains the Makefile for running Movec on the program to weave aspects.
* The other directories contain the Makefiles for running other tools on the program.

## 2.2 Running the Original Programs

You can compile/run all the benchmarks in a suite's directory using one make command. Change directory to where you place the benchmark suite.
```Bash
    $ cd benchmarks-xxx [xxx may be memsafe, nptrs, mibench or spec-cpu-2017]
    $ make build [time: ~1, 1, 1 or 3 min, respectively]
    $ make run   [for SARD+MSBench and Nptrs, time: ~1 min]
    $ make large [for MiBench, time: ~2 sec]
    $ make test  [for SPEC, time: ~2 min]
    $ make clean [this is obligatory if you will try another tool]
```
The second command above compiles all source files. The generated executable files are in the same directory as the source files. The third, fourth and fifth commands run the executable files on different inputs for different benchmark suites. A summary of the time and memory consumption may be printed after the execution of each benchmark. The last command cleans the source directory.
Note that if your system fails on a benchmark program, then you can remove its directory (or remove its source file for a program in SARD+MSBench and Nptrs) to exclude the program from build and run.

You can compile/run one benchmark using its name (e.g., BENCHMARK) in the make command. Change directory to where you place the benchmark suite.
```Bash
    $ cd benchmarks-xxx [xxx may be memsafe, nptrs, mibench or spec-cpu-2017]
    $ make BENCHMARK/build
    $ make BENCHMARK/run   [for SARD+MSBench and Nptrs]
    $ make BENCHMARK/large [for MiBench]
    $ make BENCHMARK/test  [for SPEC]
    $ make BENCHMARK/clean [this is obligatory if you will try another tool]
```

## 2.3 Running Movec

You can instrument/compile/run all the benchmarks in a suite's directory using one make command. Change directory to where you place the benchmark suite.

To detect memory errors, run the following commands:
```Bash
    $ cd benchmarks-xxx [xxx may be memsafe, nptrs, mibench or spec-cpu-2017]
    $ make output-movec-memsafe [time: ~10, 5, 3 or 5 min, respectively]
    $ make run-movec-memsafe    [for SARD+MSBench and Nptrs, time: ~10 min]
    $ make large-movec-memsafe  [for MiBench, time: ~1 min]
    $ make test-movec-memsafe   [for SPEC, time: ~60 min]
    $ make clean-movec-memsafe  [this is obligatory if you will try another tool]
```
The second command above instruments and then compiles all source files. The instrumented source files and the generated executable files are in an output directory, i.e., the output-movec-memsafe sub-directory in each benchmark's directory. The third, fourth and fifth commands run the instrumented programs on different inputs for different benchmark suites. The detected errors (if any) are reported in the output files in the output directories. A summary of the time and memory consumption, as well as the detected errors, may be printed after the execution of each benchmark. The last command cleans the output directories.
Note that if your system fails on a benchmark program, then you can remove its directory (or remove its source file for a program in SARD+MSBench and Nptrs) to exclude the program from instrumentation, build and run.

To weave aspects, run the following commands:
```Bash
    $ cd benchmarks-xxx [xxx may be mibench or spec-cpu-2017]
    $ make output-movec-monitor [time: ~2 or 5 min, respectively]
    $ make large-movec-monitor  [for MiBench, time: ~3 sec]
    $ make test-movec-monitor   [for SPEC, time: ~60 min]
    $ make clean-movec-monitor  [this is obligatory if you will try another tool]
```
The second command above instruments and then compiles all source files. The instrumented source files and the generated executable files are in an output directory, i.e., the output-movec-monitor sub-directory in each benchmark's directory. The third and fourth commands run the instrumented programs on different inputs for different benchmark suites. The output messages (if any) are reported in the output files in the output directories. A summary of the time and memory consumption, as well as the output messages, may be printed after the execution of each benchmark. The last command cleans the output directories.
Note that if your system fails on a benchmark program, then you can remove its directory to exclude the program from instrumentation, build and run.

Note that the above instructions compile the instrumented programs with compiler optimizations turned off. If you would like to turn on a more aggressive optimization level (such as -O3) or other options, please refer to the COMPILE file.
For example, let us try the -O3 level.
To detect memory errors, run the following commands:
```Bash
    $ cd benchmarks-xxx [xxx may be memsafe, nptrs, mibench or spec-cpu-2017]
    $ make output-movec-memsafe O=-O3
    $ make run-movec-memsafe O=-O3    [for SARD+MSBench and Nptrs]
    $ make large-movec-memsafe O=-O3  [for MiBench]
    $ make test-movec-memsafe O=-O3   [for SPEC]
    $ make clean-movec-memsafe [this is obligatory if you will try another tool]
```
To weave aspects, run the following commands:
```Bash
    $ cd benchmarks-xxx [xxx may be mibench or spec-cpu-2017]
    $ make output-movec-monitor O=-O3
    $ make large-movec-monitor O=-O3  [for MiBench]
    $ make test-movec-monitor O=-O3   [for SPEC]
    $ make clean-movec-monitor [this is obligatory if you will try another tool]
```

You can instrument/compile/run one benchmark using its name (e.g., BENCHMARK) in the make command. Change directory to where you place the benchmark suite.
To detect memory errors, run the following commands:
```Bash
    $ cd benchmarks-xxx [xxx may be memsafe, nptrs, mibench or spec-cpu-2017]
    $ make BENCHMARK/output-movec-memsafe
    $ make BENCHMARK/run-movec-memsafe    [for SARD+MSBench and Nptrs]
    $ make BENCHMARK/large-movec-memsafe  [for MiBench]
    $ make BENCHMARK/test-movec-memsafe   [for SPEC]
    $ make BENCHMARK/clean-movec-memsafe  [this is obligatory if you will try another tool]
```
To weave aspects, run the following commands:
```Bash
    $ cd benchmarks-xxx [xxx may be mibench or spec-cpu-2017]
    $ make BENCHMARK/output-movec-monitor
    $ make BENCHMARK/large-movec-monitor  [for MiBench]
    $ make BENCHMARK/test-movec-monitor   [for SPEC]
    $ make BENCHMARK/clean-movec-monitor  [this is obligatory if you will try another tool]
```

Note that the above instructions compile the instrumented programs with compiler optimizations turned off. If you would like to turn on a more aggressive optimization level (such as -O3) or other options, please refer to the COMPILE file.
For example, let us try the -O3 level.

To detect memory errors, run the following commands:
```Bash
    $ cd benchmarks-xxx [xxx may be memsafe, nptrs, mibench or spec-cpu-2017]
    $ make BENCHMARK/output-movec-memsafe O=-O3
    $ make BENCHMARK/run-movec-memsafe O=-O3    [for SARD+MSBench and Nptrs]
    $ make BENCHMARK/large-movec-memsafe O=-O3  [for MiBench]
    $ make BENCHMARK/test-movec-memsafe O=-O3   [for SPEC]
    $ make BENCHMARK/clean-movec-memsafe [this is obligatory if you will try another tool]
```
For example, let us try the -O3 level on SARD-testsuite-81 of benchmarks-memsafe.
```Bash
    $ cd benchmarks-memsafe
    $ make SARD-testsuite-81/output-movec-memsafe O=-O3
    $ make SARD-testsuite-81/run-movec-memsafe O=-O3
    $ make SARD-testsuite-81/clean-movec-memsafe
```

To weave aspects, run the following commands:
```Bash
    $ cd benchmarks-xxx [xxx may be mibench or spec-cpu-2017]
    $ make BENCHMARK/output-movec-monitor O=-O3
    $ make BENCHMARK/large-movec-monitor O=-O3  [for MiBench]
    $ make BENCHMARK/test-movec-monitor O=-O3   [for SPEC]
    $ make BENCHMARK/clean-movec-monitor [this is obligatory if you will try another tool]
```
For example, let us try the -O3 level on `adpcm` of benchmarks-mibench.
```Bash
    $ cd benchmarks-mibench
    $ make adpcm/output-movec-monitor O=-O3
    $ make adpcm/large-movec-monitor O=-O3
    $ make adpcm/clean-movec-monitor
```

## 2.4 Running Other Tools

The other tools, i.e., ACC, AspectC++, ASan, SoCets and Valgrind, can be run in a similar way to that of Movec. We only need to change the suffix `-movec-memsafe` and `-movec-monitor` of the targets of the make commands to `-acc`, `-acxx`, `-addresssanitizer`, `-softboundcets` and `-valgrind`, respectively.

For example, you can instrument/compile/run all the benchmarks with AspectC++ in a suite's directory using one make command.
```Bash
    $ cd benchmarks-xxx [xxx may be mibench or spec-cpu-2017]
    $ make output-acxx
    $ make large-acxx  [for MiBench]
    $ make test-acxx   [for SPEC]
    $ make clean-acxx  [this is obligatory if you will try another tool]
```

Note that ACC fails on the `stringsearch` benchmark when you run `make output-acc`, due to unknown bugs of ACC. You need to run `make output-acc` again to skip this failure.
Note that AspectC++ may fail on some benchmarks when you run `make output-acxx`, due to the complex configuration of AspectC++. We have used our configuration of AspectC++ in `Makefile.default.acxx` (adapting the options generated by the command `ag++ --gen_config`), which may not exactly match your system. You need to run `make output-acxx` again to skip these failures.

For example, you can instrument/compile/run all the benchmarks with ASan in a suite's directory using one make command.
```Bash
    $ cd benchmarks-xxx [xxx may be memsafe, nptrs, mibench or spec-cpu-2017]
    $ make output-addresssanitizer
    $ make run-addresssanitizer    [for SARD+MSBench and Nptrs]
    $ make large-addresssanitizer  [for MiBench]
    $ make test-addresssanitizer   [for SPEC]
    $ make clean-addresssanitizer  [this is obligatory if you will try another tool]
```

## 2.5 Generating a Result Table

The shell script `get_table_memsafe.sh` can generate a result table containing all reported data in a spreadsheet named `table_*.csv`, which can be opened using Microsoft Excel or LibreOffice Calc (when open the file, do tick the box of option `Evaluate formulas`).
```Bash
    $ cd benchmarks-xxx [xxx may be memsafe, nptrs, mibench or spec-cpu-2017]
    $ ./get_table_memsafe.sh
```
The shell script `get_table_movec-memsafe.sh` can generate a result table containing all reported data in another spreadsheet for different configurations of Movec.

The shell script `get_table_monitor.sh` can generate a result table containing all reported data in a spreadsheet named `table_*.csv`, which can be opened using Microsoft Excel or LibreOffice Calc (when open the file, do tick the box of option `Evaluate formulas`).
```Bash
    $ cd benchmarks-xxx [xxx may be mibench or spec-cpu-2017]
    $ ./get_table_monitor.sh
```
Note that this shell script can take an argument to specify the prefixes of aspect files. Thus, we should use:
```Bash
    $ cd benchmarks-xxx [xxx may be mibench or spec-cpu-2017]
    $ ./get_table_monitor.sh O3 PREFIXES=spec_2_1  [time: 8 min]
    $ ./get_table_monitor.sh O3 PREFIXES=spec_2_2  [time: 8 min]
    $ ./get_table_monitor.sh O3 PREFIXES=spec_1_1  [time: 8 min]
```
The second command should reproduce Table 1 in our paper, while the third command should reproduce Table 2 in our paper. Note that running the third command will overwrite the spreadsheet generated for the second command, so you need to move the spreadsheet to another directory before that.
Note that the spreadsheet generated for the third command is larger than Table 2 in our paper, because it contains the runs without aspects being weaved, e.g., for ACC and the programs that have no get/set advices. You need to manually remove these columns (of ACC) and rows (that have an empty message cell).
The fourth command should reproduce the results of runtime verification in our paper.

Here are some notes:

* Note that if your system fails on a benchmark program, then you can remove its directory name from the directory list DIRS in `get_table_memsafe.sh` or `get_table_monitor.sh` (or remove its source file for a program in SARD+MSBench and Nptrs) to exclude the program from instrumentation, build and run.
* You can set a different compiler optimization level by passing the argument `O1`, `O2` or `O3` to the shell script, e.g., `./get_table_memsafe.sh O3` and `./get_table_monitor.sh O3`.
* You can set the Movec options using the variable `MOVEC_OPTS` in `get_table_movec-memsafe.sh`.

For SARD+MSBench, running the script costs about 100 minutes. Note that the number of false positives reported by SoCets on good programs (represented by a negative number in the table of the paper) should be subtracted from the number of the (good) programs with errors detected.

For Nptrs, running the script costs about 20 minutes.

For MiBench, running the script costs about 60 minutes for detecting memory errors and 8 minutes for weaving aspects. Note that the data of aborted runs should be manually removed from the table as using these small numbers is unfair.

For SPEC, running the script costs about 4 hours.

## 2.6 Notes

Note that when you run Movec, it occasionally produces multiple errors during the instrumentation of multiple source files, e.g., unknown type name `_RV_pmd`, unknown variable or function name, which usually has a prefix such as `_RV_`. But this is a correct behavior of Movec on these programs, as this neither affects later instrumentation, nor affects successful compilation of the instrumented code. If you can find the compiled binary in the output directory, or you can successfully compile the instrumented code, then the result should be correct.

The reason is as follows. Suppose a program consists of multiple source files, e.g., `a.c` and `b.c` where `b.c` includes `a.c`. Sometimes Movec decides to instrument `a.c` before `b.c`. When Movec instruments `a.c`, it inserts some identifiers such as type, variable or function names, which usually have a prefix such as `_RV_`. After that, when Movec instruments `b.c`, it again parses `a.c` into the AST, but this time it cannot recognize the inserted identifiers in `a.c` due to the lack of a header file, so it produces errors. But this does not affect later instrumentation, as this time Movec only instruments `b.c`. At the end of instrumentation, Movec will generate a header file that provides definitions for all these identifiers, thus the instrumented code can be successfully compiled.

# 3. Reusability

This artifact is reusable as it satisfies the following requirements.

1\. The artifact is highly automated and easy to use.

Movec is highly automated and easy to use, as a single command can finish instrumentation, as introduced in Section 1.3 (above), and the process of compiling the instrumented files is the same as that of compiling the original source files. The benchmarks are also highly automated, as a single make command can finish the evaluation of a tool and report the result, and the `get_table_memsafe.sh` and `get_table_monitor.sh` scripts can finish the evaluation of all tools and generate a result table.

2\. The README describes use case scenarios and details beyond the scope of the paper, e.g., how the artifact could be used and evaluated more generally.

We have introduced the various ways of using Movec in Section 1.3 (above). Our evaluation of Movec, described in Section 2 (above) and in the paper, exactly follows those ways. Furthermore, by following those ways, Movec could be used and evaluated more generally on arbitrary C source files beyond the benchmarks used in the paper. For example, one may modify the source files in the provided benchmarks or use entirely new source files.
