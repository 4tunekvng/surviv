# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\kingsurviv\final_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\kingsurviv\final_project\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/surviv.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/surviv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/surviv.dir/flags.make

CMakeFiles/surviv.dir/src/game_object.cxx.obj: CMakeFiles/surviv.dir/flags.make
CMakeFiles/surviv.dir/src/game_object.cxx.obj: CMakeFiles/surviv.dir/includes_CXX.rsp
CMakeFiles/surviv.dir/src/game_object.cxx.obj: ../src/game_object.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\kingsurviv\final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/surviv.dir/src/game_object.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\surviv.dir\src\game_object.cxx.obj -c C:\kingsurviv\final_project\src\game_object.cxx

CMakeFiles/surviv.dir/src/game_object.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/surviv.dir/src/game_object.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\kingsurviv\final_project\src\game_object.cxx > CMakeFiles\surviv.dir\src\game_object.cxx.i

CMakeFiles/surviv.dir/src/game_object.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/surviv.dir/src/game_object.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\kingsurviv\final_project\src\game_object.cxx -o CMakeFiles\surviv.dir\src\game_object.cxx.s

CMakeFiles/surviv.dir/src/model.cxx.obj: CMakeFiles/surviv.dir/flags.make
CMakeFiles/surviv.dir/src/model.cxx.obj: CMakeFiles/surviv.dir/includes_CXX.rsp
CMakeFiles/surviv.dir/src/model.cxx.obj: ../src/model.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\kingsurviv\final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/surviv.dir/src/model.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\surviv.dir\src\model.cxx.obj -c C:\kingsurviv\final_project\src\model.cxx

CMakeFiles/surviv.dir/src/model.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/surviv.dir/src/model.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\kingsurviv\final_project\src\model.cxx > CMakeFiles\surviv.dir\src\model.cxx.i

CMakeFiles/surviv.dir/src/model.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/surviv.dir/src/model.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\kingsurviv\final_project\src\model.cxx -o CMakeFiles\surviv.dir\src\model.cxx.s

CMakeFiles/surviv.dir/src/view.cxx.obj: CMakeFiles/surviv.dir/flags.make
CMakeFiles/surviv.dir/src/view.cxx.obj: CMakeFiles/surviv.dir/includes_CXX.rsp
CMakeFiles/surviv.dir/src/view.cxx.obj: ../src/view.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\kingsurviv\final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/surviv.dir/src/view.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\surviv.dir\src\view.cxx.obj -c C:\kingsurviv\final_project\src\view.cxx

CMakeFiles/surviv.dir/src/view.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/surviv.dir/src/view.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\kingsurviv\final_project\src\view.cxx > CMakeFiles\surviv.dir\src\view.cxx.i

CMakeFiles/surviv.dir/src/view.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/surviv.dir/src/view.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\kingsurviv\final_project\src\view.cxx -o CMakeFiles\surviv.dir\src\view.cxx.s

CMakeFiles/surviv.dir/src/controller.cxx.obj: CMakeFiles/surviv.dir/flags.make
CMakeFiles/surviv.dir/src/controller.cxx.obj: CMakeFiles/surviv.dir/includes_CXX.rsp
CMakeFiles/surviv.dir/src/controller.cxx.obj: ../src/controller.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\kingsurviv\final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/surviv.dir/src/controller.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\surviv.dir\src\controller.cxx.obj -c C:\kingsurviv\final_project\src\controller.cxx

CMakeFiles/surviv.dir/src/controller.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/surviv.dir/src/controller.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\kingsurviv\final_project\src\controller.cxx > CMakeFiles\surviv.dir\src\controller.cxx.i

CMakeFiles/surviv.dir/src/controller.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/surviv.dir/src/controller.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\kingsurviv\final_project\src\controller.cxx -o CMakeFiles\surviv.dir\src\controller.cxx.s

CMakeFiles/surviv.dir/src/main.cxx.obj: CMakeFiles/surviv.dir/flags.make
CMakeFiles/surviv.dir/src/main.cxx.obj: CMakeFiles/surviv.dir/includes_CXX.rsp
CMakeFiles/surviv.dir/src/main.cxx.obj: ../src/main.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\kingsurviv\final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/surviv.dir/src/main.cxx.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\surviv.dir\src\main.cxx.obj -c C:\kingsurviv\final_project\src\main.cxx

CMakeFiles/surviv.dir/src/main.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/surviv.dir/src/main.cxx.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\kingsurviv\final_project\src\main.cxx > CMakeFiles\surviv.dir\src\main.cxx.i

CMakeFiles/surviv.dir/src/main.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/surviv.dir/src/main.cxx.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\kingsurviv\final_project\src\main.cxx -o CMakeFiles\surviv.dir\src\main.cxx.s

# Object files for target surviv
surviv_OBJECTS = \
"CMakeFiles/surviv.dir/src/game_object.cxx.obj" \
"CMakeFiles/surviv.dir/src/model.cxx.obj" \
"CMakeFiles/surviv.dir/src/view.cxx.obj" \
"CMakeFiles/surviv.dir/src/controller.cxx.obj" \
"CMakeFiles/surviv.dir/src/main.cxx.obj"

# External object files for target surviv
surviv_EXTERNAL_OBJECTS =

surviv.exe: CMakeFiles/surviv.dir/src/game_object.cxx.obj
surviv.exe: CMakeFiles/surviv.dir/src/model.cxx.obj
surviv.exe: CMakeFiles/surviv.dir/src/view.cxx.obj
surviv.exe: CMakeFiles/surviv.dir/src/controller.cxx.obj
surviv.exe: CMakeFiles/surviv.dir/src/main.cxx.obj
surviv.exe: CMakeFiles/surviv.dir/build.make
surviv.exe: .cs211/lib/ge211/src/libge211.a
surviv.exe: C:/MinGW/lib/libSDL2.dll.a
surviv.exe: C:/MinGW/lib/libSDL2_image.dll.a
surviv.exe: C:/MinGW/lib/libSDL2_mixer.dll.a
surviv.exe: C:/MinGW/lib/libSDL2_ttf.dll.a
surviv.exe: CMakeFiles/surviv.dir/linklibs.rsp
surviv.exe: CMakeFiles/surviv.dir/objects1.rsp
surviv.exe: CMakeFiles/surviv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\kingsurviv\final_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable surviv.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\surviv.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/surviv.dir/build: surviv.exe
.PHONY : CMakeFiles/surviv.dir/build

CMakeFiles/surviv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\surviv.dir\cmake_clean.cmake
.PHONY : CMakeFiles/surviv.dir/clean

CMakeFiles/surviv.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\kingsurviv\final_project C:\kingsurviv\final_project C:\kingsurviv\final_project\cmake-build-debug C:\kingsurviv\final_project\cmake-build-debug C:\kingsurviv\final_project\cmake-build-debug\CMakeFiles\surviv.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/surviv.dir/depend

