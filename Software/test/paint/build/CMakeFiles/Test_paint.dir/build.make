# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/pi/Perfect-Colour/Software/test/paint

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/Perfect-Colour/Software/test/paint/build

# Include any dependencies generated for this target.
include CMakeFiles/Test_paint.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Test_paint.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Test_paint.dir/flags.make

CMakeFiles/Test_paint.dir/test_paint.cpp.o: CMakeFiles/Test_paint.dir/flags.make
CMakeFiles/Test_paint.dir/test_paint.cpp.o: ../test_paint.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Perfect-Colour/Software/test/paint/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Test_paint.dir/test_paint.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test_paint.dir/test_paint.cpp.o -c /home/pi/Perfect-Colour/Software/test/paint/test_paint.cpp

CMakeFiles/Test_paint.dir/test_paint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test_paint.dir/test_paint.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Perfect-Colour/Software/test/paint/test_paint.cpp > CMakeFiles/Test_paint.dir/test_paint.cpp.i

CMakeFiles/Test_paint.dir/test_paint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test_paint.dir/test_paint.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Perfect-Colour/Software/test/paint/test_paint.cpp -o CMakeFiles/Test_paint.dir/test_paint.cpp.s

CMakeFiles/Test_paint.dir/test_paint.cpp.o.requires:

.PHONY : CMakeFiles/Test_paint.dir/test_paint.cpp.o.requires

CMakeFiles/Test_paint.dir/test_paint.cpp.o.provides: CMakeFiles/Test_paint.dir/test_paint.cpp.o.requires
	$(MAKE) -f CMakeFiles/Test_paint.dir/build.make CMakeFiles/Test_paint.dir/test_paint.cpp.o.provides.build
.PHONY : CMakeFiles/Test_paint.dir/test_paint.cpp.o.provides

CMakeFiles/Test_paint.dir/test_paint.cpp.o.provides.build: CMakeFiles/Test_paint.dir/test_paint.cpp.o


# Object files for target Test_paint
Test_paint_OBJECTS = \
"CMakeFiles/Test_paint.dir/test_paint.cpp.o"

# External object files for target Test_paint
Test_paint_EXTERNAL_OBJECTS =

Test_paint: CMakeFiles/Test_paint.dir/test_paint.cpp.o
Test_paint: CMakeFiles/Test_paint.dir/build.make
Test_paint: CMakeFiles/Test_paint.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/Perfect-Colour/Software/test/paint/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Test_paint"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test_paint.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Test_paint.dir/build: Test_paint

.PHONY : CMakeFiles/Test_paint.dir/build

CMakeFiles/Test_paint.dir/requires: CMakeFiles/Test_paint.dir/test_paint.cpp.o.requires

.PHONY : CMakeFiles/Test_paint.dir/requires

CMakeFiles/Test_paint.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Test_paint.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Test_paint.dir/clean

CMakeFiles/Test_paint.dir/depend:
	cd /home/pi/Perfect-Colour/Software/test/paint/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Perfect-Colour/Software/test/paint /home/pi/Perfect-Colour/Software/test/paint /home/pi/Perfect-Colour/Software/test/paint/build /home/pi/Perfect-Colour/Software/test/paint/build /home/pi/Perfect-Colour/Software/test/paint/build/CMakeFiles/Test_paint.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Test_paint.dir/depend
