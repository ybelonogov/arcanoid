# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/alex/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5080.54/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/alex/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5080.54/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alex/Desktop/Cplusplus/arcanoid

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alex/Desktop/Cplusplus/arcanoid/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/gemes.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/gemes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gemes.dir/flags.make

CMakeFiles/gemes.dir/main.cpp.o: CMakeFiles/gemes.dir/flags.make
CMakeFiles/gemes.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Desktop/Cplusplus/arcanoid/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gemes.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gemes.dir/main.cpp.o -c /home/alex/Desktop/Cplusplus/arcanoid/main.cpp

CMakeFiles/gemes.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gemes.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Desktop/Cplusplus/arcanoid/main.cpp > CMakeFiles/gemes.dir/main.cpp.i

CMakeFiles/gemes.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gemes.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Desktop/Cplusplus/arcanoid/main.cpp -o CMakeFiles/gemes.dir/main.cpp.s

CMakeFiles/gemes.dir/brick.cpp.o: CMakeFiles/gemes.dir/flags.make
CMakeFiles/gemes.dir/brick.cpp.o: ../brick.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Desktop/Cplusplus/arcanoid/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/gemes.dir/brick.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gemes.dir/brick.cpp.o -c /home/alex/Desktop/Cplusplus/arcanoid/brick.cpp

CMakeFiles/gemes.dir/brick.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gemes.dir/brick.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Desktop/Cplusplus/arcanoid/brick.cpp > CMakeFiles/gemes.dir/brick.cpp.i

CMakeFiles/gemes.dir/brick.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gemes.dir/brick.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Desktop/Cplusplus/arcanoid/brick.cpp -o CMakeFiles/gemes.dir/brick.cpp.s

CMakeFiles/gemes.dir/brick_types.cpp.o: CMakeFiles/gemes.dir/flags.make
CMakeFiles/gemes.dir/brick_types.cpp.o: ../brick_types.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Desktop/Cplusplus/arcanoid/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/gemes.dir/brick_types.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gemes.dir/brick_types.cpp.o -c /home/alex/Desktop/Cplusplus/arcanoid/brick_types.cpp

CMakeFiles/gemes.dir/brick_types.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gemes.dir/brick_types.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Desktop/Cplusplus/arcanoid/brick_types.cpp > CMakeFiles/gemes.dir/brick_types.cpp.i

CMakeFiles/gemes.dir/brick_types.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gemes.dir/brick_types.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Desktop/Cplusplus/arcanoid/brick_types.cpp -o CMakeFiles/gemes.dir/brick_types.cpp.s

CMakeFiles/gemes.dir/check.cpp.o: CMakeFiles/gemes.dir/flags.make
CMakeFiles/gemes.dir/check.cpp.o: ../check.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Desktop/Cplusplus/arcanoid/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/gemes.dir/check.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gemes.dir/check.cpp.o -c /home/alex/Desktop/Cplusplus/arcanoid/check.cpp

CMakeFiles/gemes.dir/check.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gemes.dir/check.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Desktop/Cplusplus/arcanoid/check.cpp > CMakeFiles/gemes.dir/check.cpp.i

CMakeFiles/gemes.dir/check.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gemes.dir/check.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Desktop/Cplusplus/arcanoid/check.cpp -o CMakeFiles/gemes.dir/check.cpp.s

# Object files for target gemes
gemes_OBJECTS = \
"CMakeFiles/gemes.dir/main.cpp.o" \
"CMakeFiles/gemes.dir/brick.cpp.o" \
"CMakeFiles/gemes.dir/brick_types.cpp.o" \
"CMakeFiles/gemes.dir/check.cpp.o"

# External object files for target gemes
gemes_EXTERNAL_OBJECTS =

gemes: CMakeFiles/gemes.dir/main.cpp.o
gemes: CMakeFiles/gemes.dir/brick.cpp.o
gemes: CMakeFiles/gemes.dir/brick_types.cpp.o
gemes: CMakeFiles/gemes.dir/check.cpp.o
gemes: CMakeFiles/gemes.dir/build.make
gemes: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
gemes: /usr/lib/x86_64-linux-gnu/libsfml-audio.so.2.5.1
gemes: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
gemes: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
gemes: CMakeFiles/gemes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alex/Desktop/Cplusplus/arcanoid/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable gemes"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gemes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gemes.dir/build: gemes
.PHONY : CMakeFiles/gemes.dir/build

CMakeFiles/gemes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gemes.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gemes.dir/clean

CMakeFiles/gemes.dir/depend:
	cd /home/alex/Desktop/Cplusplus/arcanoid/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/Desktop/Cplusplus/arcanoid /home/alex/Desktop/Cplusplus/arcanoid /home/alex/Desktop/Cplusplus/arcanoid/cmake-build-debug /home/alex/Desktop/Cplusplus/arcanoid/cmake-build-debug /home/alex/Desktop/Cplusplus/arcanoid/cmake-build-debug/CMakeFiles/gemes.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gemes.dir/depend

