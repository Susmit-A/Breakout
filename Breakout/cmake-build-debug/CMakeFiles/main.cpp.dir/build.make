# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/susmit/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/191.7141.37/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/susmit/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/191.7141.37/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/susmit/gitprojects/Breakout/Breakout

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/susmit/gitprojects/Breakout/Breakout/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/main.cpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.cpp.dir/flags.make

CMakeFiles/main.cpp.dir/ball.cpp.o: CMakeFiles/main.cpp.dir/flags.make
CMakeFiles/main.cpp.dir/ball.cpp.o: ../ball.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/susmit/gitprojects/Breakout/Breakout/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.cpp.dir/ball.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.cpp.dir/ball.cpp.o -c /home/susmit/gitprojects/Breakout/Breakout/ball.cpp

CMakeFiles/main.cpp.dir/ball.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.cpp.dir/ball.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/susmit/gitprojects/Breakout/Breakout/ball.cpp > CMakeFiles/main.cpp.dir/ball.cpp.i

CMakeFiles/main.cpp.dir/ball.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.cpp.dir/ball.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/susmit/gitprojects/Breakout/Breakout/ball.cpp -o CMakeFiles/main.cpp.dir/ball.cpp.s

CMakeFiles/main.cpp.dir/block.cpp.o: CMakeFiles/main.cpp.dir/flags.make
CMakeFiles/main.cpp.dir/block.cpp.o: ../block.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/susmit/gitprojects/Breakout/Breakout/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.cpp.dir/block.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.cpp.dir/block.cpp.o -c /home/susmit/gitprojects/Breakout/Breakout/block.cpp

CMakeFiles/main.cpp.dir/block.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.cpp.dir/block.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/susmit/gitprojects/Breakout/Breakout/block.cpp > CMakeFiles/main.cpp.dir/block.cpp.i

CMakeFiles/main.cpp.dir/block.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.cpp.dir/block.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/susmit/gitprojects/Breakout/Breakout/block.cpp -o CMakeFiles/main.cpp.dir/block.cpp.s

CMakeFiles/main.cpp.dir/collider.cpp.o: CMakeFiles/main.cpp.dir/flags.make
CMakeFiles/main.cpp.dir/collider.cpp.o: ../collider.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/susmit/gitprojects/Breakout/Breakout/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.cpp.dir/collider.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.cpp.dir/collider.cpp.o -c /home/susmit/gitprojects/Breakout/Breakout/collider.cpp

CMakeFiles/main.cpp.dir/collider.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.cpp.dir/collider.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/susmit/gitprojects/Breakout/Breakout/collider.cpp > CMakeFiles/main.cpp.dir/collider.cpp.i

CMakeFiles/main.cpp.dir/collider.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.cpp.dir/collider.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/susmit/gitprojects/Breakout/Breakout/collider.cpp -o CMakeFiles/main.cpp.dir/collider.cpp.s

CMakeFiles/main.cpp.dir/main.cpp.o: CMakeFiles/main.cpp.dir/flags.make
CMakeFiles/main.cpp.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/susmit/gitprojects/Breakout/Breakout/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.cpp.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.cpp.dir/main.cpp.o -c /home/susmit/gitprojects/Breakout/Breakout/main.cpp

CMakeFiles/main.cpp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.cpp.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/susmit/gitprojects/Breakout/Breakout/main.cpp > CMakeFiles/main.cpp.dir/main.cpp.i

CMakeFiles/main.cpp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.cpp.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/susmit/gitprojects/Breakout/Breakout/main.cpp -o CMakeFiles/main.cpp.dir/main.cpp.s

CMakeFiles/main.cpp.dir/paddle.cpp.o: CMakeFiles/main.cpp.dir/flags.make
CMakeFiles/main.cpp.dir/paddle.cpp.o: ../paddle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/susmit/gitprojects/Breakout/Breakout/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.cpp.dir/paddle.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.cpp.dir/paddle.cpp.o -c /home/susmit/gitprojects/Breakout/Breakout/paddle.cpp

CMakeFiles/main.cpp.dir/paddle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.cpp.dir/paddle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/susmit/gitprojects/Breakout/Breakout/paddle.cpp > CMakeFiles/main.cpp.dir/paddle.cpp.i

CMakeFiles/main.cpp.dir/paddle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.cpp.dir/paddle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/susmit/gitprojects/Breakout/Breakout/paddle.cpp -o CMakeFiles/main.cpp.dir/paddle.cpp.s

# Object files for target main.cpp
main_cpp_OBJECTS = \
"CMakeFiles/main.cpp.dir/ball.cpp.o" \
"CMakeFiles/main.cpp.dir/block.cpp.o" \
"CMakeFiles/main.cpp.dir/collider.cpp.o" \
"CMakeFiles/main.cpp.dir/main.cpp.o" \
"CMakeFiles/main.cpp.dir/paddle.cpp.o"

# External object files for target main.cpp
main_cpp_EXTERNAL_OBJECTS =

main.cpp: CMakeFiles/main.cpp.dir/ball.cpp.o
main.cpp: CMakeFiles/main.cpp.dir/block.cpp.o
main.cpp: CMakeFiles/main.cpp.dir/collider.cpp.o
main.cpp: CMakeFiles/main.cpp.dir/main.cpp.o
main.cpp: CMakeFiles/main.cpp.dir/paddle.cpp.o
main.cpp: CMakeFiles/main.cpp.dir/build.make
main.cpp: /usr/lib/x86_64-linux-gnu/libOpenGL.so
main.cpp: /usr/lib/x86_64-linux-gnu/libGLX.so
main.cpp: /usr/lib/x86_64-linux-gnu/libGLU.so
main.cpp: /usr/lib/x86_64-linux-gnu/libglut.so
main.cpp: /usr/lib/x86_64-linux-gnu/libXmu.so
main.cpp: /usr/lib/x86_64-linux-gnu/libXi.so
main.cpp: CMakeFiles/main.cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/susmit/gitprojects/Breakout/Breakout/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable main.cpp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.cpp.dir/build: main.cpp

.PHONY : CMakeFiles/main.cpp.dir/build

CMakeFiles/main.cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.cpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.cpp.dir/clean

CMakeFiles/main.cpp.dir/depend:
	cd /home/susmit/gitprojects/Breakout/Breakout/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/susmit/gitprojects/Breakout/Breakout /home/susmit/gitprojects/Breakout/Breakout /home/susmit/gitprojects/Breakout/Breakout/cmake-build-debug /home/susmit/gitprojects/Breakout/Breakout/cmake-build-debug /home/susmit/gitprojects/Breakout/Breakout/cmake-build-debug/CMakeFiles/main.cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.cpp.dir/depend

