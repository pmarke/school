# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mark/school/professionalCpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mark/school/professionalCpp/build

# Include any dependencies generated for this target.
include 23_MultithreadedProgramming/CMakeFiles/multiThread.dir/depend.make

# Include the progress variables for this target.
include 23_MultithreadedProgramming/CMakeFiles/multiThread.dir/progress.make

# Include the compile flags for this target's objects.
include 23_MultithreadedProgramming/CMakeFiles/multiThread.dir/flags.make

23_MultithreadedProgramming/CMakeFiles/multiThread.dir/main.cpp.o: 23_MultithreadedProgramming/CMakeFiles/multiThread.dir/flags.make
23_MultithreadedProgramming/CMakeFiles/multiThread.dir/main.cpp.o: ../23_MultithreadedProgramming/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mark/school/professionalCpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object 23_MultithreadedProgramming/CMakeFiles/multiThread.dir/main.cpp.o"
	cd /home/mark/school/professionalCpp/build/23_MultithreadedProgramming && /usr/bin/g++-11  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/multiThread.dir/main.cpp.o -c /home/mark/school/professionalCpp/23_MultithreadedProgramming/main.cpp

23_MultithreadedProgramming/CMakeFiles/multiThread.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/multiThread.dir/main.cpp.i"
	cd /home/mark/school/professionalCpp/build/23_MultithreadedProgramming && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mark/school/professionalCpp/23_MultithreadedProgramming/main.cpp > CMakeFiles/multiThread.dir/main.cpp.i

23_MultithreadedProgramming/CMakeFiles/multiThread.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/multiThread.dir/main.cpp.s"
	cd /home/mark/school/professionalCpp/build/23_MultithreadedProgramming && /usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mark/school/professionalCpp/23_MultithreadedProgramming/main.cpp -o CMakeFiles/multiThread.dir/main.cpp.s

# Object files for target multiThread
multiThread_OBJECTS = \
"CMakeFiles/multiThread.dir/main.cpp.o"

# External object files for target multiThread
multiThread_EXTERNAL_OBJECTS =

23_MultithreadedProgramming/multiThread: 23_MultithreadedProgramming/CMakeFiles/multiThread.dir/main.cpp.o
23_MultithreadedProgramming/multiThread: 23_MultithreadedProgramming/CMakeFiles/multiThread.dir/build.make
23_MultithreadedProgramming/multiThread: 23_MultithreadedProgramming/CMakeFiles/multiThread.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mark/school/professionalCpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable multiThread"
	cd /home/mark/school/professionalCpp/build/23_MultithreadedProgramming && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/multiThread.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
23_MultithreadedProgramming/CMakeFiles/multiThread.dir/build: 23_MultithreadedProgramming/multiThread

.PHONY : 23_MultithreadedProgramming/CMakeFiles/multiThread.dir/build

23_MultithreadedProgramming/CMakeFiles/multiThread.dir/clean:
	cd /home/mark/school/professionalCpp/build/23_MultithreadedProgramming && $(CMAKE_COMMAND) -P CMakeFiles/multiThread.dir/cmake_clean.cmake
.PHONY : 23_MultithreadedProgramming/CMakeFiles/multiThread.dir/clean

23_MultithreadedProgramming/CMakeFiles/multiThread.dir/depend:
	cd /home/mark/school/professionalCpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mark/school/professionalCpp /home/mark/school/professionalCpp/23_MultithreadedProgramming /home/mark/school/professionalCpp/build /home/mark/school/professionalCpp/build/23_MultithreadedProgramming /home/mark/school/professionalCpp/build/23_MultithreadedProgramming/CMakeFiles/multiThread.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 23_MultithreadedProgramming/CMakeFiles/multiThread.dir/depend
