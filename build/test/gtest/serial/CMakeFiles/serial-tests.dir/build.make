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

# Include any dependencies generated for this target.
include test/gtest/serial/CMakeFiles/serial-tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/gtest/serial/CMakeFiles/serial-tests.dir/compiler_depend.make

# Include the progress variables for this target.
include test/gtest/serial/CMakeFiles/serial-tests.dir/progress.make

# Include the compile flags for this target's objects.
include test/gtest/serial/CMakeFiles/serial-tests.dir/flags.make

test/gtest/serial/CMakeFiles/serial-tests.dir/serial-tests.cpp.o: test/gtest/serial/CMakeFiles/serial-tests.dir/flags.make
test/gtest/serial/CMakeFiles/serial-tests.dir/serial-tests.cpp.o: /nfs/site/home/nowakmat/work/distributed-ranges-sort/test/gtest/serial/serial-tests.cpp
test/gtest/serial/CMakeFiles/serial-tests.dir/serial-tests.cpp.o: test/gtest/serial/CMakeFiles/serial-tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/site/home/nowakmat/work/distributed-ranges-sort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/gtest/serial/CMakeFiles/serial-tests.dir/serial-tests.cpp.o"
	cd /nfs/site/home/nowakmat/work/distributed-ranges-sort/build/test/gtest/serial && /opt/intel/oneapi/compiler/2023.2.0/linux/bin/icpx $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/gtest/serial/CMakeFiles/serial-tests.dir/serial-tests.cpp.o -MF CMakeFiles/serial-tests.dir/serial-tests.cpp.o.d -o CMakeFiles/serial-tests.dir/serial-tests.cpp.o -c /nfs/site/home/nowakmat/work/distributed-ranges-sort/test/gtest/serial/serial-tests.cpp

test/gtest/serial/CMakeFiles/serial-tests.dir/serial-tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serial-tests.dir/serial-tests.cpp.i"
	cd /nfs/site/home/nowakmat/work/distributed-ranges-sort/build/test/gtest/serial && /opt/intel/oneapi/compiler/2023.2.0/linux/bin/icpx $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/site/home/nowakmat/work/distributed-ranges-sort/test/gtest/serial/serial-tests.cpp > CMakeFiles/serial-tests.dir/serial-tests.cpp.i

test/gtest/serial/CMakeFiles/serial-tests.dir/serial-tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serial-tests.dir/serial-tests.cpp.s"
	cd /nfs/site/home/nowakmat/work/distributed-ranges-sort/build/test/gtest/serial && /opt/intel/oneapi/compiler/2023.2.0/linux/bin/icpx $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/site/home/nowakmat/work/distributed-ranges-sort/test/gtest/serial/serial-tests.cpp -o CMakeFiles/serial-tests.dir/serial-tests.cpp.s

# Object files for target serial-tests
serial__tests_OBJECTS = \
"CMakeFiles/serial-tests.dir/serial-tests.cpp.o"

# External object files for target serial-tests
serial__tests_EXTERNAL_OBJECTS =

test/gtest/serial/serial-tests: test/gtest/serial/CMakeFiles/serial-tests.dir/serial-tests.cpp.o
test/gtest/serial/serial-tests: test/gtest/serial/CMakeFiles/serial-tests.dir/build.make
test/gtest/serial/serial-tests: lib/libgtest_main.a
test/gtest/serial/serial-tests: lib/libgtest.a
test/gtest/serial/serial-tests: test/gtest/serial/CMakeFiles/serial-tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/nfs/site/home/nowakmat/work/distributed-ranges-sort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable serial-tests"
	cd /nfs/site/home/nowakmat/work/distributed-ranges-sort/build/test/gtest/serial && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serial-tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/gtest/serial/CMakeFiles/serial-tests.dir/build: test/gtest/serial/serial-tests
.PHONY : test/gtest/serial/CMakeFiles/serial-tests.dir/build

test/gtest/serial/CMakeFiles/serial-tests.dir/clean:
	cd /nfs/site/home/nowakmat/work/distributed-ranges-sort/build/test/gtest/serial && $(CMAKE_COMMAND) -P CMakeFiles/serial-tests.dir/cmake_clean.cmake
.PHONY : test/gtest/serial/CMakeFiles/serial-tests.dir/clean

test/gtest/serial/CMakeFiles/serial-tests.dir/depend:
	cd /nfs/site/home/nowakmat/work/distributed-ranges-sort/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/site/home/nowakmat/work/distributed-ranges-sort /nfs/site/home/nowakmat/work/distributed-ranges-sort/test/gtest/serial /nfs/site/home/nowakmat/work/distributed-ranges-sort/build /nfs/site/home/nowakmat/work/distributed-ranges-sort/build/test/gtest/serial /nfs/site/home/nowakmat/work/distributed-ranges-sort/build/test/gtest/serial/CMakeFiles/serial-tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/gtest/serial/CMakeFiles/serial-tests.dir/depend
