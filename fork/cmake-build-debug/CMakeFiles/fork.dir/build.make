# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\dev\III_sem\fork

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\dev\III_sem\fork\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/fork.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fork.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fork.dir/flags.make

CMakeFiles/fork.dir/main.cpp.obj: CMakeFiles/fork.dir/flags.make
CMakeFiles/fork.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\dev\III_sem\fork\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fork.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\fork.dir\main.cpp.obj -c C:\dev\III_sem\fork\main.cpp

CMakeFiles/fork.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fork.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\dev\III_sem\fork\main.cpp > CMakeFiles\fork.dir\main.cpp.i

CMakeFiles/fork.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fork.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\dev\III_sem\fork\main.cpp -o CMakeFiles\fork.dir\main.cpp.s

# Object files for target fork
fork_OBJECTS = \
"CMakeFiles/fork.dir/main.cpp.obj"

# External object files for target fork
fork_EXTERNAL_OBJECTS =

fork.exe: CMakeFiles/fork.dir/main.cpp.obj
fork.exe: CMakeFiles/fork.dir/build.make
fork.exe: CMakeFiles/fork.dir/linklibs.rsp
fork.exe: CMakeFiles/fork.dir/objects1.rsp
fork.exe: CMakeFiles/fork.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\dev\III_sem\fork\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable fork.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\fork.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fork.dir/build: fork.exe

.PHONY : CMakeFiles/fork.dir/build

CMakeFiles/fork.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\fork.dir\cmake_clean.cmake
.PHONY : CMakeFiles/fork.dir/clean

CMakeFiles/fork.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\dev\III_sem\fork C:\dev\III_sem\fork C:\dev\III_sem\fork\cmake-build-debug C:\dev\III_sem\fork\cmake-build-debug C:\dev\III_sem\fork\cmake-build-debug\CMakeFiles\fork.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fork.dir/depend
