# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /home/zhiiw/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/211.7142.21/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/zhiiw/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/211.7142.21/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zhiiw/CLionProjects/Covid19Graph-India

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhiiw/CLionProjects/Covid19Graph-India/cmake-build-debug

# Include any dependencies generated for this target.
include _deps/json-build/test/CMakeFiles/test-msgpack.dir/depend.make

# Include the progress variables for this target.
include _deps/json-build/test/CMakeFiles/test-msgpack.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/json-build/test/CMakeFiles/test-msgpack.dir/flags.make

_deps/json-build/test/CMakeFiles/test-msgpack.dir/src/unit-msgpack.cpp.o: _deps/json-build/test/CMakeFiles/test-msgpack.dir/flags.make
_deps/json-build/test/CMakeFiles/test-msgpack.dir/src/unit-msgpack.cpp.o: _deps/json-src/test/src/unit-msgpack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhiiw/CLionProjects/Covid19Graph-India/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/json-build/test/CMakeFiles/test-msgpack.dir/src/unit-msgpack.cpp.o"
	cd /home/zhiiw/CLionProjects/Covid19Graph-India/cmake-build-debug/_deps/json-build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test-msgpack.dir/src/unit-msgpack.cpp.o -c /home/zhiiw/CLionProjects/Covid19Graph-India/cmake-build-debug/_deps/json-src/test/src/unit-msgpack.cpp

_deps/json-build/test/CMakeFiles/test-msgpack.dir/src/unit-msgpack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-msgpack.dir/src/unit-msgpack.cpp.i"
	cd /home/zhiiw/CLionProjects/Covid19Graph-India/cmake-build-debug/_deps/json-build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhiiw/CLionProjects/Covid19Graph-India/cmake-build-debug/_deps/json-src/test/src/unit-msgpack.cpp > CMakeFiles/test-msgpack.dir/src/unit-msgpack.cpp.i

_deps/json-build/test/CMakeFiles/test-msgpack.dir/src/unit-msgpack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-msgpack.dir/src/unit-msgpack.cpp.s"
	cd /home/zhiiw/CLionProjects/Covid19Graph-India/cmake-build-debug/_deps/json-build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhiiw/CLionProjects/Covid19Graph-India/cmake-build-debug/_deps/json-src/test/src/unit-msgpack.cpp -o CMakeFiles/test-msgpack.dir/src/unit-msgpack.cpp.s

# Object files for target test-msgpack
test__msgpack_OBJECTS = \
"CMakeFiles/test-msgpack.dir/src/unit-msgpack.cpp.o"

# External object files for target test-msgpack
test__msgpack_EXTERNAL_OBJECTS = \
"/home/zhiiw/CLionProjects/Covid19Graph-India/cmake-build-debug/_deps/json-build/test/CMakeFiles/doctest_main.dir/src/unit.cpp.o"

_deps/json-build/test/test-msgpack: _deps/json-build/test/CMakeFiles/test-msgpack.dir/src/unit-msgpack.cpp.o
_deps/json-build/test/test-msgpack: _deps/json-build/test/CMakeFiles/doctest_main.dir/src/unit.cpp.o
_deps/json-build/test/test-msgpack: _deps/json-build/test/CMakeFiles/test-msgpack.dir/build.make
_deps/json-build/test/test-msgpack: _deps/json-build/test/CMakeFiles/test-msgpack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhiiw/CLionProjects/Covid19Graph-India/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-msgpack"
	cd /home/zhiiw/CLionProjects/Covid19Graph-India/cmake-build-debug/_deps/json-build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-msgpack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/json-build/test/CMakeFiles/test-msgpack.dir/build: _deps/json-build/test/test-msgpack

.PHONY : _deps/json-build/test/CMakeFiles/test-msgpack.dir/build

_deps/json-build/test/CMakeFiles/test-msgpack.dir/clean:
	cd /home/zhiiw/CLionProjects/Covid19Graph-India/cmake-build-debug/_deps/json-build/test && $(CMAKE_COMMAND) -P CMakeFiles/test-msgpack.dir/cmake_clean.cmake
.PHONY : _deps/json-build/test/CMakeFiles/test-msgpack.dir/clean

_deps/json-build/test/CMakeFiles/test-msgpack.dir/depend:
	cd /home/zhiiw/CLionProjects/Covid19Graph-India/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhiiw/CLionProjects/Covid19Graph-India /home/zhiiw/CLionProjects/Covid19Graph-India/cmake-build-debug/_deps/json-src/test /home/zhiiw/CLionProjects/Covid19Graph-India/cmake-build-debug /home/zhiiw/CLionProjects/Covid19Graph-India/cmake-build-debug/_deps/json-build/test /home/zhiiw/CLionProjects/Covid19Graph-India/cmake-build-debug/_deps/json-build/test/CMakeFiles/test-msgpack.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/json-build/test/CMakeFiles/test-msgpack.dir/depend
