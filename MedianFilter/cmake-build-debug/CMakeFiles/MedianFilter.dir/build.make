# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Prasuna/GitHub/MedianFilter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Prasuna/GitHub/MedianFilter/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MedianFilter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MedianFilter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MedianFilter.dir/flags.make

CMakeFiles/MedianFilter.dir/medianfilter.cpp.o: CMakeFiles/MedianFilter.dir/flags.make
CMakeFiles/MedianFilter.dir/medianfilter.cpp.o: ../medianfilter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Prasuna/GitHub/MedianFilter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MedianFilter.dir/medianfilter.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MedianFilter.dir/medianfilter.cpp.o -c /Users/Prasuna/GitHub/MedianFilter/medianfilter.cpp

CMakeFiles/MedianFilter.dir/medianfilter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MedianFilter.dir/medianfilter.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Prasuna/GitHub/MedianFilter/medianfilter.cpp > CMakeFiles/MedianFilter.dir/medianfilter.cpp.i

CMakeFiles/MedianFilter.dir/medianfilter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MedianFilter.dir/medianfilter.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Prasuna/GitHub/MedianFilter/medianfilter.cpp -o CMakeFiles/MedianFilter.dir/medianfilter.cpp.s

CMakeFiles/MedianFilter.dir/medianfilter.cpp.o.requires:

.PHONY : CMakeFiles/MedianFilter.dir/medianfilter.cpp.o.requires

CMakeFiles/MedianFilter.dir/medianfilter.cpp.o.provides: CMakeFiles/MedianFilter.dir/medianfilter.cpp.o.requires
	$(MAKE) -f CMakeFiles/MedianFilter.dir/build.make CMakeFiles/MedianFilter.dir/medianfilter.cpp.o.provides.build
.PHONY : CMakeFiles/MedianFilter.dir/medianfilter.cpp.o.provides

CMakeFiles/MedianFilter.dir/medianfilter.cpp.o.provides.build: CMakeFiles/MedianFilter.dir/medianfilter.cpp.o


# Object files for target MedianFilter
MedianFilter_OBJECTS = \
"CMakeFiles/MedianFilter.dir/medianfilter.cpp.o"

# External object files for target MedianFilter
MedianFilter_EXTERNAL_OBJECTS =

MedianFilter: CMakeFiles/MedianFilter.dir/medianfilter.cpp.o
MedianFilter: CMakeFiles/MedianFilter.dir/build.make
MedianFilter: CMakeFiles/MedianFilter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Prasuna/GitHub/MedianFilter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MedianFilter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MedianFilter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MedianFilter.dir/build: MedianFilter

.PHONY : CMakeFiles/MedianFilter.dir/build

CMakeFiles/MedianFilter.dir/requires: CMakeFiles/MedianFilter.dir/medianfilter.cpp.o.requires

.PHONY : CMakeFiles/MedianFilter.dir/requires

CMakeFiles/MedianFilter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MedianFilter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MedianFilter.dir/clean

CMakeFiles/MedianFilter.dir/depend:
	cd /Users/Prasuna/GitHub/MedianFilter/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Prasuna/GitHub/MedianFilter /Users/Prasuna/GitHub/MedianFilter /Users/Prasuna/GitHub/MedianFilter/cmake-build-debug /Users/Prasuna/GitHub/MedianFilter/cmake-build-debug /Users/Prasuna/GitHub/MedianFilter/cmake-build-debug/CMakeFiles/MedianFilter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MedianFilter.dir/depend

