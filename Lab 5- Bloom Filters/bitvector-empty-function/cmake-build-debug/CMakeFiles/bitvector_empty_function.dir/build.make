# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /cygdrive/c/Users/ellen/.CLion2018.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/ellen/.CLion2018.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 5- Bloom Filters/bitvector-empty-function"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 5- Bloom Filters/bitvector-empty-function/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/bitvector_empty_function.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bitvector_empty_function.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bitvector_empty_function.dir/flags.make

CMakeFiles/bitvector_empty_function.dir/bitset.c.o: CMakeFiles/bitvector_empty_function.dir/flags.make
CMakeFiles/bitvector_empty_function.dir/bitset.c.o: ../bitset.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 5- Bloom Filters/bitvector-empty-function/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/bitvector_empty_function.dir/bitset.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bitvector_empty_function.dir/bitset.c.o   -c "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 5- Bloom Filters/bitvector-empty-function/bitset.c"

CMakeFiles/bitvector_empty_function.dir/bitset.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bitvector_empty_function.dir/bitset.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 5- Bloom Filters/bitvector-empty-function/bitset.c" > CMakeFiles/bitvector_empty_function.dir/bitset.c.i

CMakeFiles/bitvector_empty_function.dir/bitset.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bitvector_empty_function.dir/bitset.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 5- Bloom Filters/bitvector-empty-function/bitset.c" -o CMakeFiles/bitvector_empty_function.dir/bitset.c.s

CMakeFiles/bitvector_empty_function.dir/bloom.c.o: CMakeFiles/bitvector_empty_function.dir/flags.make
CMakeFiles/bitvector_empty_function.dir/bloom.c.o: ../bloom.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 5- Bloom Filters/bitvector-empty-function/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/bitvector_empty_function.dir/bloom.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bitvector_empty_function.dir/bloom.c.o   -c "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 5- Bloom Filters/bitvector-empty-function/bloom.c"

CMakeFiles/bitvector_empty_function.dir/bloom.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bitvector_empty_function.dir/bloom.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 5- Bloom Filters/bitvector-empty-function/bloom.c" > CMakeFiles/bitvector_empty_function.dir/bloom.c.i

CMakeFiles/bitvector_empty_function.dir/bloom.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bitvector_empty_function.dir/bloom.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 5- Bloom Filters/bitvector-empty-function/bloom.c" -o CMakeFiles/bitvector_empty_function.dir/bloom.c.s

CMakeFiles/bitvector_empty_function.dir/main.c.o: CMakeFiles/bitvector_empty_function.dir/flags.make
CMakeFiles/bitvector_empty_function.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 5- Bloom Filters/bitvector-empty-function/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/bitvector_empty_function.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bitvector_empty_function.dir/main.c.o   -c "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 5- Bloom Filters/bitvector-empty-function/main.c"

CMakeFiles/bitvector_empty_function.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bitvector_empty_function.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 5- Bloom Filters/bitvector-empty-function/main.c" > CMakeFiles/bitvector_empty_function.dir/main.c.i

CMakeFiles/bitvector_empty_function.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bitvector_empty_function.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 5- Bloom Filters/bitvector-empty-function/main.c" -o CMakeFiles/bitvector_empty_function.dir/main.c.s

# Object files for target bitvector_empty_function
bitvector_empty_function_OBJECTS = \
"CMakeFiles/bitvector_empty_function.dir/bitset.c.o" \
"CMakeFiles/bitvector_empty_function.dir/bloom.c.o" \
"CMakeFiles/bitvector_empty_function.dir/main.c.o"

# External object files for target bitvector_empty_function
bitvector_empty_function_EXTERNAL_OBJECTS =

bitvector_empty_function.exe: CMakeFiles/bitvector_empty_function.dir/bitset.c.o
bitvector_empty_function.exe: CMakeFiles/bitvector_empty_function.dir/bloom.c.o
bitvector_empty_function.exe: CMakeFiles/bitvector_empty_function.dir/main.c.o
bitvector_empty_function.exe: CMakeFiles/bitvector_empty_function.dir/build.make
bitvector_empty_function.exe: CMakeFiles/bitvector_empty_function.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 5- Bloom Filters/bitvector-empty-function/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable bitvector_empty_function.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bitvector_empty_function.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bitvector_empty_function.dir/build: bitvector_empty_function.exe

.PHONY : CMakeFiles/bitvector_empty_function.dir/build

CMakeFiles/bitvector_empty_function.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bitvector_empty_function.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bitvector_empty_function.dir/clean

CMakeFiles/bitvector_empty_function.dir/depend:
	cd "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 5- Bloom Filters/bitvector-empty-function/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 5- Bloom Filters/bitvector-empty-function" "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 5- Bloom Filters/bitvector-empty-function" "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 5- Bloom Filters/bitvector-empty-function/cmake-build-debug" "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 5- Bloom Filters/bitvector-empty-function/cmake-build-debug" "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 5- Bloom Filters/bitvector-empty-function/cmake-build-debug/CMakeFiles/bitvector_empty_function.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/bitvector_empty_function.dir/depend

