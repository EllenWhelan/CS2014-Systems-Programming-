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
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 7-encodedecode/student-huff"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 7-encodedecode/student-huff/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/student_huff.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/student_huff.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/student_huff.dir/flags.make

CMakeFiles/student_huff.dir/bitfile.c.o: CMakeFiles/student_huff.dir/flags.make
CMakeFiles/student_huff.dir/bitfile.c.o: ../bitfile.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 7-encodedecode/student-huff/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/student_huff.dir/bitfile.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/student_huff.dir/bitfile.c.o   -c "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 7-encodedecode/student-huff/bitfile.c"

CMakeFiles/student_huff.dir/bitfile.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/student_huff.dir/bitfile.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 7-encodedecode/student-huff/bitfile.c" > CMakeFiles/student_huff.dir/bitfile.c.i

CMakeFiles/student_huff.dir/bitfile.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/student_huff.dir/bitfile.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 7-encodedecode/student-huff/bitfile.c" -o CMakeFiles/student_huff.dir/bitfile.c.s

CMakeFiles/student_huff.dir/huff.c.o: CMakeFiles/student_huff.dir/flags.make
CMakeFiles/student_huff.dir/huff.c.o: ../huff.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 7-encodedecode/student-huff/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/student_huff.dir/huff.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/student_huff.dir/huff.c.o   -c "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 7-encodedecode/student-huff/huff.c"

CMakeFiles/student_huff.dir/huff.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/student_huff.dir/huff.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 7-encodedecode/student-huff/huff.c" > CMakeFiles/student_huff.dir/huff.c.i

CMakeFiles/student_huff.dir/huff.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/student_huff.dir/huff.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 7-encodedecode/student-huff/huff.c" -o CMakeFiles/student_huff.dir/huff.c.s

CMakeFiles/student_huff.dir/main.c.o: CMakeFiles/student_huff.dir/flags.make
CMakeFiles/student_huff.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 7-encodedecode/student-huff/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/student_huff.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/student_huff.dir/main.c.o   -c "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 7-encodedecode/student-huff/main.c"

CMakeFiles/student_huff.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/student_huff.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 7-encodedecode/student-huff/main.c" > CMakeFiles/student_huff.dir/main.c.i

CMakeFiles/student_huff.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/student_huff.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 7-encodedecode/student-huff/main.c" -o CMakeFiles/student_huff.dir/main.c.s

# Object files for target student_huff
student_huff_OBJECTS = \
"CMakeFiles/student_huff.dir/bitfile.c.o" \
"CMakeFiles/student_huff.dir/huff.c.o" \
"CMakeFiles/student_huff.dir/main.c.o"

# External object files for target student_huff
student_huff_EXTERNAL_OBJECTS =

student_huff.exe: CMakeFiles/student_huff.dir/bitfile.c.o
student_huff.exe: CMakeFiles/student_huff.dir/huff.c.o
student_huff.exe: CMakeFiles/student_huff.dir/main.c.o
student_huff.exe: CMakeFiles/student_huff.dir/build.make
student_huff.exe: CMakeFiles/student_huff.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 7-encodedecode/student-huff/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable student_huff.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/student_huff.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/student_huff.dir/build: student_huff.exe

.PHONY : CMakeFiles/student_huff.dir/build

CMakeFiles/student_huff.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/student_huff.dir/cmake_clean.cmake
.PHONY : CMakeFiles/student_huff.dir/clean

CMakeFiles/student_huff.dir/depend:
	cd "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 7-encodedecode/student-huff/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 7-encodedecode/student-huff" "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 7-encodedecode/student-huff" "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 7-encodedecode/student-huff/cmake-build-debug" "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 7-encodedecode/student-huff/cmake-build-debug" "/cygdrive/c/Users/ellen/OneDrive/Documents/Academic/Year 2/Systems Prog/Labs/Lab 7-encodedecode/student-huff/cmake-build-debug/CMakeFiles/student_huff.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/student_huff.dir/depend

