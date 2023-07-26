# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/hpc_software/tools/cmake/3.26.0/bin/cmake

# The command to remove a file.
RM = /opt/hpc_software/tools/cmake/3.26.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /nfs/site/home/nowakmat/work/distributed-ranges-sort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /nfs/site/home/nowakmat/work/distributed-ranges-sort/build

# Utility rule file for bench.

# Include any custom commands dependencies for this target.
include benchmarks/gbench/mhp/CMakeFiles/bench.dir/compiler_depend.make

# Include the progress variables for this target.
include benchmarks/gbench/mhp/CMakeFiles/bench.dir/progress.make

benchmarks/gbench/mhp/CMakeFiles/bench: benchmarks/gbench/mhp/bench-results

benchmarks/gbench/mhp/bench-results: benchmarks/gbench/mhp/mhp-bench
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/nfs/site/home/nowakmat/work/distributed-ranges-sort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating bench-results"
	cd /nfs/site/home/nowakmat/work/distributed-ranges-sort/build/benchmarks/gbench/mhp && python /nfs/site/home/nowakmat/work/distributed-ranges-sort/scripts/dr-bench.py mhp --fork

bench: benchmarks/gbench/mhp/CMakeFiles/bench
bench: benchmarks/gbench/mhp/bench-results
bench: benchmarks/gbench/mhp/CMakeFiles/bench.dir/build.make
.PHONY : bench

# Rule to build all files generated by this target.
benchmarks/gbench/mhp/CMakeFiles/bench.dir/build: bench
.PHONY : benchmarks/gbench/mhp/CMakeFiles/bench.dir/build

benchmarks/gbench/mhp/CMakeFiles/bench.dir/clean:
	cd /nfs/site/home/nowakmat/work/distributed-ranges-sort/build/benchmarks/gbench/mhp && $(CMAKE_COMMAND) -P CMakeFiles/bench.dir/cmake_clean.cmake
.PHONY : benchmarks/gbench/mhp/CMakeFiles/bench.dir/clean

benchmarks/gbench/mhp/CMakeFiles/bench.dir/depend:
	cd /nfs/site/home/nowakmat/work/distributed-ranges-sort/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/site/home/nowakmat/work/distributed-ranges-sort /nfs/site/home/nowakmat/work/distributed-ranges-sort/benchmarks/gbench/mhp /nfs/site/home/nowakmat/work/distributed-ranges-sort/build /nfs/site/home/nowakmat/work/distributed-ranges-sort/build/benchmarks/gbench/mhp /nfs/site/home/nowakmat/work/distributed-ranges-sort/build/benchmarks/gbench/mhp/CMakeFiles/bench.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : benchmarks/gbench/mhp/CMakeFiles/bench.dir/depend
