# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\files\CGPROJECT\Bidirectional-implementation-of-Spectral-Rendering\SRC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\files\CGPROJECT\Bidirectional-implementation-of-Spectral-Rendering\SRC\cmake-build-debug-mingw

# Include any dependencies generated for this target.
include CMakeFiles/TheNextWeekend.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TheNextWeekend.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TheNextWeekend.dir/flags.make

CMakeFiles/TheNextWeekend.dir/main.cpp.obj: CMakeFiles/TheNextWeekend.dir/flags.make
CMakeFiles/TheNextWeekend.dir/main.cpp.obj: CMakeFiles/TheNextWeekend.dir/includes_CXX.rsp
CMakeFiles/TheNextWeekend.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\files\CGPROJECT\Bidirectional-implementation-of-Spectral-Rendering\SRC\cmake-build-debug-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TheNextWeekend.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\TheNextWeekend.dir\main.cpp.obj -c D:\files\CGPROJECT\Bidirectional-implementation-of-Spectral-Rendering\SRC\main.cpp

CMakeFiles/TheNextWeekend.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TheNextWeekend.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\files\CGPROJECT\Bidirectional-implementation-of-Spectral-Rendering\SRC\main.cpp > CMakeFiles\TheNextWeekend.dir\main.cpp.i

CMakeFiles/TheNextWeekend.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TheNextWeekend.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\files\CGPROJECT\Bidirectional-implementation-of-Spectral-Rendering\SRC\main.cpp -o CMakeFiles\TheNextWeekend.dir\main.cpp.s

CMakeFiles/TheNextWeekend.dir/Color.cpp.obj: CMakeFiles/TheNextWeekend.dir/flags.make
CMakeFiles/TheNextWeekend.dir/Color.cpp.obj: CMakeFiles/TheNextWeekend.dir/includes_CXX.rsp
CMakeFiles/TheNextWeekend.dir/Color.cpp.obj: ../Color.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\files\CGPROJECT\Bidirectional-implementation-of-Spectral-Rendering\SRC\cmake-build-debug-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TheNextWeekend.dir/Color.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\TheNextWeekend.dir\Color.cpp.obj -c D:\files\CGPROJECT\Bidirectional-implementation-of-Spectral-Rendering\SRC\Color.cpp

CMakeFiles/TheNextWeekend.dir/Color.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TheNextWeekend.dir/Color.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\files\CGPROJECT\Bidirectional-implementation-of-Spectral-Rendering\SRC\Color.cpp > CMakeFiles\TheNextWeekend.dir\Color.cpp.i

CMakeFiles/TheNextWeekend.dir/Color.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TheNextWeekend.dir/Color.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\files\CGPROJECT\Bidirectional-implementation-of-Spectral-Rendering\SRC\Color.cpp -o CMakeFiles\TheNextWeekend.dir\Color.cpp.s

# Object files for target TheNextWeekend
TheNextWeekend_OBJECTS = \
"CMakeFiles/TheNextWeekend.dir/main.cpp.obj" \
"CMakeFiles/TheNextWeekend.dir/Color.cpp.obj"

# External object files for target TheNextWeekend
TheNextWeekend_EXTERNAL_OBJECTS =

bin/TheNextWeekend.exe: CMakeFiles/TheNextWeekend.dir/main.cpp.obj
bin/TheNextWeekend.exe: CMakeFiles/TheNextWeekend.dir/Color.cpp.obj
bin/TheNextWeekend.exe: CMakeFiles/TheNextWeekend.dir/build.make
bin/TheNextWeekend.exe: CMakeFiles/TheNextWeekend.dir/linklibs.rsp
bin/TheNextWeekend.exe: CMakeFiles/TheNextWeekend.dir/objects1.rsp
bin/TheNextWeekend.exe: CMakeFiles/TheNextWeekend.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\files\CGPROJECT\Bidirectional-implementation-of-Spectral-Rendering\SRC\cmake-build-debug-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable bin\TheNextWeekend.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TheNextWeekend.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TheNextWeekend.dir/build: bin/TheNextWeekend.exe

.PHONY : CMakeFiles/TheNextWeekend.dir/build

CMakeFiles/TheNextWeekend.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TheNextWeekend.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TheNextWeekend.dir/clean

CMakeFiles/TheNextWeekend.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\files\CGPROJECT\Bidirectional-implementation-of-Spectral-Rendering\SRC D:\files\CGPROJECT\Bidirectional-implementation-of-Spectral-Rendering\SRC D:\files\CGPROJECT\Bidirectional-implementation-of-Spectral-Rendering\SRC\cmake-build-debug-mingw D:\files\CGPROJECT\Bidirectional-implementation-of-Spectral-Rendering\SRC\cmake-build-debug-mingw D:\files\CGPROJECT\Bidirectional-implementation-of-Spectral-Rendering\SRC\cmake-build-debug-mingw\CMakeFiles\TheNextWeekend.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TheNextWeekend.dir/depend

