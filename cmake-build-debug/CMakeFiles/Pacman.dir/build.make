# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Pacman.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Pacman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Pacman.dir/flags.make

Debug/Pacman/Pacman.app/Contents/Resources/CinderApp.icns: /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/samples/data/CinderApp.icns
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Copying OS X content Debug/Pacman/Pacman.app/Contents/Resources/CinderApp.icns"
	$(CMAKE_COMMAND) -E copy /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/samples/data/CinderApp.icns Debug/Pacman/Pacman.app/Contents/Resources/CinderApp.icns

CMakeFiles/Pacman.dir/apps/cinder_app_main.cc.o: CMakeFiles/Pacman.dir/flags.make
CMakeFiles/Pacman.dir/apps/cinder_app_main.cc.o: ../apps/cinder_app_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Pacman.dir/apps/cinder_app_main.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pacman.dir/apps/cinder_app_main.cc.o -c /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/apps/cinder_app_main.cc

CMakeFiles/Pacman.dir/apps/cinder_app_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pacman.dir/apps/cinder_app_main.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/apps/cinder_app_main.cc > CMakeFiles/Pacman.dir/apps/cinder_app_main.cc.i

CMakeFiles/Pacman.dir/apps/cinder_app_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pacman.dir/apps/cinder_app_main.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/apps/cinder_app_main.cc -o CMakeFiles/Pacman.dir/apps/cinder_app_main.cc.s

CMakeFiles/Pacman.dir/src/my_app.cc.o: CMakeFiles/Pacman.dir/flags.make
CMakeFiles/Pacman.dir/src/my_app.cc.o: ../src/my_app.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Pacman.dir/src/my_app.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pacman.dir/src/my_app.cc.o -c /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/my_app.cc

CMakeFiles/Pacman.dir/src/my_app.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pacman.dir/src/my_app.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/my_app.cc > CMakeFiles/Pacman.dir/src/my_app.cc.i

CMakeFiles/Pacman.dir/src/my_app.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pacman.dir/src/my_app.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/my_app.cc -o CMakeFiles/Pacman.dir/src/my_app.cc.s

CMakeFiles/Pacman.dir/src/wall.cc.o: CMakeFiles/Pacman.dir/flags.make
CMakeFiles/Pacman.dir/src/wall.cc.o: ../src/wall.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Pacman.dir/src/wall.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pacman.dir/src/wall.cc.o -c /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/wall.cc

CMakeFiles/Pacman.dir/src/wall.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pacman.dir/src/wall.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/wall.cc > CMakeFiles/Pacman.dir/src/wall.cc.i

CMakeFiles/Pacman.dir/src/wall.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pacman.dir/src/wall.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/wall.cc -o CMakeFiles/Pacman.dir/src/wall.cc.s

CMakeFiles/Pacman.dir/src/snack.cc.o: CMakeFiles/Pacman.dir/flags.make
CMakeFiles/Pacman.dir/src/snack.cc.o: ../src/snack.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Pacman.dir/src/snack.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pacman.dir/src/snack.cc.o -c /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/snack.cc

CMakeFiles/Pacman.dir/src/snack.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pacman.dir/src/snack.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/snack.cc > CMakeFiles/Pacman.dir/src/snack.cc.i

CMakeFiles/Pacman.dir/src/snack.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pacman.dir/src/snack.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/snack.cc -o CMakeFiles/Pacman.dir/src/snack.cc.s

CMakeFiles/Pacman.dir/src/power_up.cc.o: CMakeFiles/Pacman.dir/flags.make
CMakeFiles/Pacman.dir/src/power_up.cc.o: ../src/power_up.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Pacman.dir/src/power_up.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pacman.dir/src/power_up.cc.o -c /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/power_up.cc

CMakeFiles/Pacman.dir/src/power_up.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pacman.dir/src/power_up.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/power_up.cc > CMakeFiles/Pacman.dir/src/power_up.cc.i

CMakeFiles/Pacman.dir/src/power_up.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pacman.dir/src/power_up.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/power_up.cc -o CMakeFiles/Pacman.dir/src/power_up.cc.s

CMakeFiles/Pacman.dir/src/map.cc.o: CMakeFiles/Pacman.dir/flags.make
CMakeFiles/Pacman.dir/src/map.cc.o: ../src/map.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Pacman.dir/src/map.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pacman.dir/src/map.cc.o -c /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/map.cc

CMakeFiles/Pacman.dir/src/map.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pacman.dir/src/map.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/map.cc > CMakeFiles/Pacman.dir/src/map.cc.i

CMakeFiles/Pacman.dir/src/map.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pacman.dir/src/map.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/map.cc -o CMakeFiles/Pacman.dir/src/map.cc.s

CMakeFiles/Pacman.dir/src/ghost.cc.o: CMakeFiles/Pacman.dir/flags.make
CMakeFiles/Pacman.dir/src/ghost.cc.o: ../src/ghost.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Pacman.dir/src/ghost.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pacman.dir/src/ghost.cc.o -c /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/ghost.cc

CMakeFiles/Pacman.dir/src/ghost.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pacman.dir/src/ghost.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/ghost.cc > CMakeFiles/Pacman.dir/src/ghost.cc.i

CMakeFiles/Pacman.dir/src/ghost.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pacman.dir/src/ghost.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/ghost.cc -o CMakeFiles/Pacman.dir/src/ghost.cc.s

CMakeFiles/Pacman.dir/src/pacman.cc.o: CMakeFiles/Pacman.dir/flags.make
CMakeFiles/Pacman.dir/src/pacman.cc.o: ../src/pacman.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Pacman.dir/src/pacman.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pacman.dir/src/pacman.cc.o -c /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/pacman.cc

CMakeFiles/Pacman.dir/src/pacman.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pacman.dir/src/pacman.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/pacman.cc > CMakeFiles/Pacman.dir/src/pacman.cc.i

CMakeFiles/Pacman.dir/src/pacman.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pacman.dir/src/pacman.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/pacman.cc -o CMakeFiles/Pacman.dir/src/pacman.cc.s

CMakeFiles/Pacman.dir/src/pacman_engine.cc.o: CMakeFiles/Pacman.dir/flags.make
CMakeFiles/Pacman.dir/src/pacman_engine.cc.o: ../src/pacman_engine.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Pacman.dir/src/pacman_engine.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pacman.dir/src/pacman_engine.cc.o -c /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/pacman_engine.cc

CMakeFiles/Pacman.dir/src/pacman_engine.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pacman.dir/src/pacman_engine.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/pacman_engine.cc > CMakeFiles/Pacman.dir/src/pacman_engine.cc.i

CMakeFiles/Pacman.dir/src/pacman_engine.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pacman.dir/src/pacman_engine.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/pacman_engine.cc -o CMakeFiles/Pacman.dir/src/pacman_engine.cc.s

CMakeFiles/Pacman.dir/src/game_over.cc.o: CMakeFiles/Pacman.dir/flags.make
CMakeFiles/Pacman.dir/src/game_over.cc.o: ../src/game_over.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Pacman.dir/src/game_over.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pacman.dir/src/game_over.cc.o -c /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/game_over.cc

CMakeFiles/Pacman.dir/src/game_over.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pacman.dir/src/game_over.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/game_over.cc > CMakeFiles/Pacman.dir/src/game_over.cc.i

CMakeFiles/Pacman.dir/src/game_over.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pacman.dir/src/game_over.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/src/game_over.cc -o CMakeFiles/Pacman.dir/src/game_over.cc.s

# Object files for target Pacman
Pacman_OBJECTS = \
"CMakeFiles/Pacman.dir/apps/cinder_app_main.cc.o" \
"CMakeFiles/Pacman.dir/src/my_app.cc.o" \
"CMakeFiles/Pacman.dir/src/wall.cc.o" \
"CMakeFiles/Pacman.dir/src/snack.cc.o" \
"CMakeFiles/Pacman.dir/src/power_up.cc.o" \
"CMakeFiles/Pacman.dir/src/map.cc.o" \
"CMakeFiles/Pacman.dir/src/ghost.cc.o" \
"CMakeFiles/Pacman.dir/src/pacman.cc.o" \
"CMakeFiles/Pacman.dir/src/pacman_engine.cc.o" \
"CMakeFiles/Pacman.dir/src/game_over.cc.o"

# External object files for target Pacman
Pacman_EXTERNAL_OBJECTS =

Debug/Pacman/Pacman.app/Contents/MacOS/Pacman: CMakeFiles/Pacman.dir/apps/cinder_app_main.cc.o
Debug/Pacman/Pacman.app/Contents/MacOS/Pacman: CMakeFiles/Pacman.dir/src/my_app.cc.o
Debug/Pacman/Pacman.app/Contents/MacOS/Pacman: CMakeFiles/Pacman.dir/src/wall.cc.o
Debug/Pacman/Pacman.app/Contents/MacOS/Pacman: CMakeFiles/Pacman.dir/src/snack.cc.o
Debug/Pacman/Pacman.app/Contents/MacOS/Pacman: CMakeFiles/Pacman.dir/src/power_up.cc.o
Debug/Pacman/Pacman.app/Contents/MacOS/Pacman: CMakeFiles/Pacman.dir/src/map.cc.o
Debug/Pacman/Pacman.app/Contents/MacOS/Pacman: CMakeFiles/Pacman.dir/src/ghost.cc.o
Debug/Pacman/Pacman.app/Contents/MacOS/Pacman: CMakeFiles/Pacman.dir/src/pacman.cc.o
Debug/Pacman/Pacman.app/Contents/MacOS/Pacman: CMakeFiles/Pacman.dir/src/pacman_engine.cc.o
Debug/Pacman/Pacman.app/Contents/MacOS/Pacman: CMakeFiles/Pacman.dir/src/game_over.cc.o
Debug/Pacman/Pacman.app/Contents/MacOS/Pacman: CMakeFiles/Pacman.dir/build.make
Debug/Pacman/Pacman.app/Contents/MacOS/Pacman: /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/lib/macosx/Debug/libcinder.a
Debug/Pacman/Pacman.app/Contents/MacOS/Pacman: /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/lib/macosx/libboost_system.a
Debug/Pacman/Pacman.app/Contents/MacOS/Pacman: /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/lib/macosx/libboost_filesystem.a
Debug/Pacman/Pacman.app/Contents/MacOS/Pacman: CMakeFiles/Pacman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable Debug/Pacman/Pacman.app/Contents/MacOS/Pacman"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Pacman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Pacman.dir/build: Debug/Pacman/Pacman.app/Contents/MacOS/Pacman
CMakeFiles/Pacman.dir/build: Debug/Pacman/Pacman.app/Contents/Resources/CinderApp.icns

.PHONY : CMakeFiles/Pacman.dir/build

CMakeFiles/Pacman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Pacman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Pacman.dir/clean

CMakeFiles/Pacman.dir/depend:
	cd /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7 /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7 /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/cmake-build-debug /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/cmake-build-debug /Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/cmake-build-debug/CMakeFiles/Pacman.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Pacman.dir/depend

