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
CMAKE_SOURCE_DIR = /home/yourusername/lynx/LynxEv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yourusername/lynx/LynxEv/build

# Include any dependencies generated for this target.
include CMakeFiles/lynx_app_main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lynx_app_main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lynx_app_main.dir/flags.make

CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_message.cpp.o: CMakeFiles/lynx_app_main.dir/flags.make
CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_message.cpp.o: ../01_event_driven_kernel/lynx_ev_message.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yourusername/lynx/LynxEv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_message.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_message.cpp.o -c /home/yourusername/lynx/LynxEv/01_event_driven_kernel/lynx_ev_message.cpp

CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_message.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_message.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yourusername/lynx/LynxEv/01_event_driven_kernel/lynx_ev_message.cpp > CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_message.cpp.i

CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_message.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_message.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yourusername/lynx/LynxEv/01_event_driven_kernel/lynx_ev_message.cpp -o CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_message.cpp.s

CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_task.cpp.o: CMakeFiles/lynx_app_main.dir/flags.make
CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_task.cpp.o: ../01_event_driven_kernel/lynx_ev_task.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yourusername/lynx/LynxEv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_task.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_task.cpp.o -c /home/yourusername/lynx/LynxEv/01_event_driven_kernel/lynx_ev_task.cpp

CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_task.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_task.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yourusername/lynx/LynxEv/01_event_driven_kernel/lynx_ev_task.cpp > CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_task.cpp.i

CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_task.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_task.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yourusername/lynx/LynxEv/01_event_driven_kernel/lynx_ev_task.cpp -o CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_task.cpp.s

CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_timer.cpp.o: CMakeFiles/lynx_app_main.dir/flags.make
CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_timer.cpp.o: ../01_event_driven_kernel/lynx_ev_timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yourusername/lynx/LynxEv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_timer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_timer.cpp.o -c /home/yourusername/lynx/LynxEv/01_event_driven_kernel/lynx_ev_timer.cpp

CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_timer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yourusername/lynx/LynxEv/01_event_driven_kernel/lynx_ev_timer.cpp > CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_timer.cpp.i

CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_timer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yourusername/lynx/LynxEv/01_event_driven_kernel/lynx_ev_timer.cpp -o CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_timer.cpp.s

CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/system_debug.cpp.o: CMakeFiles/lynx_app_main.dir/flags.make
CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/system_debug.cpp.o: ../01_event_driven_kernel/system_debug.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yourusername/lynx/LynxEv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/system_debug.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/system_debug.cpp.o -c /home/yourusername/lynx/LynxEv/01_event_driven_kernel/system_debug.cpp

CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/system_debug.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/system_debug.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yourusername/lynx/LynxEv/01_event_driven_kernel/system_debug.cpp > CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/system_debug.cpp.i

CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/system_debug.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/system_debug.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yourusername/lynx/LynxEv/01_event_driven_kernel/system_debug.cpp -o CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/system_debug.cpp.s

# Object files for target lynx_app_main
lynx_app_main_OBJECTS = \
"CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_message.cpp.o" \
"CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_task.cpp.o" \
"CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_timer.cpp.o" \
"CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/system_debug.cpp.o"

# External object files for target lynx_app_main
lynx_app_main_EXTERNAL_OBJECTS =

lynx_app_main: CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_message.cpp.o
lynx_app_main: CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_task.cpp.o
lynx_app_main: CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/lynx_ev_timer.cpp.o
lynx_app_main: CMakeFiles/lynx_app_main.dir/01_event_driven_kernel/system_debug.cpp.o
lynx_app_main: CMakeFiles/lynx_app_main.dir/build.make
lynx_app_main: CMakeFiles/lynx_app_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yourusername/lynx/LynxEv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable lynx_app_main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lynx_app_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lynx_app_main.dir/build: lynx_app_main

.PHONY : CMakeFiles/lynx_app_main.dir/build

CMakeFiles/lynx_app_main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lynx_app_main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lynx_app_main.dir/clean

CMakeFiles/lynx_app_main.dir/depend:
	cd /home/yourusername/lynx/LynxEv/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yourusername/lynx/LynxEv /home/yourusername/lynx/LynxEv /home/yourusername/lynx/LynxEv/build /home/yourusername/lynx/LynxEv/build /home/yourusername/lynx/LynxEv/build/CMakeFiles/lynx_app_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lynx_app_main.dir/depend

