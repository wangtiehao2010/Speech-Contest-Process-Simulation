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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/david/CLionProjects/Speech contest process"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/david/CLionProjects/Speech contest process/build"

# Include any dependencies generated for this target.
include CMakeFiles/Speech_contest_process.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Speech_contest_process.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Speech_contest_process.dir/flags.make

CMakeFiles/Speech_contest_process.dir/Speech_contest_process_management_system.cpp.o: CMakeFiles/Speech_contest_process.dir/flags.make
CMakeFiles/Speech_contest_process.dir/Speech_contest_process_management_system.cpp.o: ../Speech\ contest\ process\ management\ system.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/david/CLionProjects/Speech contest process/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Speech_contest_process.dir/Speech_contest_process_management_system.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Speech_contest_process.dir/Speech_contest_process_management_system.cpp.o -c "/home/david/CLionProjects/Speech contest process/Speech contest process management system.cpp"

CMakeFiles/Speech_contest_process.dir/Speech_contest_process_management_system.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Speech_contest_process.dir/Speech_contest_process_management_system.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/david/CLionProjects/Speech contest process/Speech contest process management system.cpp" > CMakeFiles/Speech_contest_process.dir/Speech_contest_process_management_system.cpp.i

CMakeFiles/Speech_contest_process.dir/Speech_contest_process_management_system.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Speech_contest_process.dir/Speech_contest_process_management_system.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/david/CLionProjects/Speech contest process/Speech contest process management system.cpp" -o CMakeFiles/Speech_contest_process.dir/Speech_contest_process_management_system.cpp.s

CMakeFiles/Speech_contest_process.dir/SpeechManager.cpp.o: CMakeFiles/Speech_contest_process.dir/flags.make
CMakeFiles/Speech_contest_process.dir/SpeechManager.cpp.o: ../SpeechManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/david/CLionProjects/Speech contest process/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Speech_contest_process.dir/SpeechManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Speech_contest_process.dir/SpeechManager.cpp.o -c "/home/david/CLionProjects/Speech contest process/SpeechManager.cpp"

CMakeFiles/Speech_contest_process.dir/SpeechManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Speech_contest_process.dir/SpeechManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/david/CLionProjects/Speech contest process/SpeechManager.cpp" > CMakeFiles/Speech_contest_process.dir/SpeechManager.cpp.i

CMakeFiles/Speech_contest_process.dir/SpeechManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Speech_contest_process.dir/SpeechManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/david/CLionProjects/Speech contest process/SpeechManager.cpp" -o CMakeFiles/Speech_contest_process.dir/SpeechManager.cpp.s

# Object files for target Speech_contest_process
Speech_contest_process_OBJECTS = \
"CMakeFiles/Speech_contest_process.dir/Speech_contest_process_management_system.cpp.o" \
"CMakeFiles/Speech_contest_process.dir/SpeechManager.cpp.o"

# External object files for target Speech_contest_process
Speech_contest_process_EXTERNAL_OBJECTS =

Speech_contest_process: CMakeFiles/Speech_contest_process.dir/Speech_contest_process_management_system.cpp.o
Speech_contest_process: CMakeFiles/Speech_contest_process.dir/SpeechManager.cpp.o
Speech_contest_process: CMakeFiles/Speech_contest_process.dir/build.make
Speech_contest_process: CMakeFiles/Speech_contest_process.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/david/CLionProjects/Speech contest process/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Speech_contest_process"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Speech_contest_process.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Speech_contest_process.dir/build: Speech_contest_process

.PHONY : CMakeFiles/Speech_contest_process.dir/build

CMakeFiles/Speech_contest_process.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Speech_contest_process.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Speech_contest_process.dir/clean

CMakeFiles/Speech_contest_process.dir/depend:
	cd "/home/david/CLionProjects/Speech contest process/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/david/CLionProjects/Speech contest process" "/home/david/CLionProjects/Speech contest process" "/home/david/CLionProjects/Speech contest process/build" "/home/david/CLionProjects/Speech contest process/build" "/home/david/CLionProjects/Speech contest process/build/CMakeFiles/Speech_contest_process.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Speech_contest_process.dir/depend

