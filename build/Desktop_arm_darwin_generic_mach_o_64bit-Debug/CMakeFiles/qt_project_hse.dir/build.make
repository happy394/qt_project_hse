# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/c4ndlemandle/Documents/C++/qt_project_hse

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/c4ndlemandle/Documents/C++/qt_project_hse/build/Desktop_arm_darwin_generic_mach_o_64bit-Debug

# Include any dependencies generated for this target.
include CMakeFiles/qt_project_hse.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/qt_project_hse.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/qt_project_hse.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/qt_project_hse.dir/flags.make

qt_project_hse_autogen/timestamp: /opt/homebrew/share/qt/libexec/moc
qt_project_hse_autogen/timestamp: /opt/homebrew/share/qt/libexec/uic
qt_project_hse_autogen/timestamp: CMakeFiles/qt_project_hse.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/c4ndlemandle/Documents/C++/qt_project_hse/build/Desktop_arm_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target qt_project_hse"
	/Applications/CMake.app/Contents/bin/cmake -E cmake_autogen /Users/c4ndlemandle/Documents/C++/qt_project_hse/build/Desktop_arm_darwin_generic_mach_o_64bit-Debug/CMakeFiles/qt_project_hse_autogen.dir/AutogenInfo.json Debug
	/Applications/CMake.app/Contents/bin/cmake -E touch /Users/c4ndlemandle/Documents/C++/qt_project_hse/build/Desktop_arm_darwin_generic_mach_o_64bit-Debug/qt_project_hse_autogen/timestamp

CMakeFiles/qt_project_hse.dir/qt_project_hse_autogen/mocs_compilation.cpp.o: CMakeFiles/qt_project_hse.dir/flags.make
CMakeFiles/qt_project_hse.dir/qt_project_hse_autogen/mocs_compilation.cpp.o: qt_project_hse_autogen/mocs_compilation.cpp
CMakeFiles/qt_project_hse.dir/qt_project_hse_autogen/mocs_compilation.cpp.o: CMakeFiles/qt_project_hse.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/c4ndlemandle/Documents/C++/qt_project_hse/build/Desktop_arm_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/qt_project_hse.dir/qt_project_hse_autogen/mocs_compilation.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/qt_project_hse.dir/qt_project_hse_autogen/mocs_compilation.cpp.o -MF CMakeFiles/qt_project_hse.dir/qt_project_hse_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/qt_project_hse.dir/qt_project_hse_autogen/mocs_compilation.cpp.o -c /Users/c4ndlemandle/Documents/C++/qt_project_hse/build/Desktop_arm_darwin_generic_mach_o_64bit-Debug/qt_project_hse_autogen/mocs_compilation.cpp

CMakeFiles/qt_project_hse.dir/qt_project_hse_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/qt_project_hse.dir/qt_project_hse_autogen/mocs_compilation.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/c4ndlemandle/Documents/C++/qt_project_hse/build/Desktop_arm_darwin_generic_mach_o_64bit-Debug/qt_project_hse_autogen/mocs_compilation.cpp > CMakeFiles/qt_project_hse.dir/qt_project_hse_autogen/mocs_compilation.cpp.i

CMakeFiles/qt_project_hse.dir/qt_project_hse_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/qt_project_hse.dir/qt_project_hse_autogen/mocs_compilation.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/c4ndlemandle/Documents/C++/qt_project_hse/build/Desktop_arm_darwin_generic_mach_o_64bit-Debug/qt_project_hse_autogen/mocs_compilation.cpp -o CMakeFiles/qt_project_hse.dir/qt_project_hse_autogen/mocs_compilation.cpp.s

CMakeFiles/qt_project_hse.dir/main.cpp.o: CMakeFiles/qt_project_hse.dir/flags.make
CMakeFiles/qt_project_hse.dir/main.cpp.o: /Users/c4ndlemandle/Documents/C++/qt_project_hse/main.cpp
CMakeFiles/qt_project_hse.dir/main.cpp.o: CMakeFiles/qt_project_hse.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/c4ndlemandle/Documents/C++/qt_project_hse/build/Desktop_arm_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/qt_project_hse.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/qt_project_hse.dir/main.cpp.o -MF CMakeFiles/qt_project_hse.dir/main.cpp.o.d -o CMakeFiles/qt_project_hse.dir/main.cpp.o -c /Users/c4ndlemandle/Documents/C++/qt_project_hse/main.cpp

CMakeFiles/qt_project_hse.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/qt_project_hse.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/c4ndlemandle/Documents/C++/qt_project_hse/main.cpp > CMakeFiles/qt_project_hse.dir/main.cpp.i

CMakeFiles/qt_project_hse.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/qt_project_hse.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/c4ndlemandle/Documents/C++/qt_project_hse/main.cpp -o CMakeFiles/qt_project_hse.dir/main.cpp.s

CMakeFiles/qt_project_hse.dir/mainwindow.cpp.o: CMakeFiles/qt_project_hse.dir/flags.make
CMakeFiles/qt_project_hse.dir/mainwindow.cpp.o: /Users/c4ndlemandle/Documents/C++/qt_project_hse/mainwindow.cpp
CMakeFiles/qt_project_hse.dir/mainwindow.cpp.o: CMakeFiles/qt_project_hse.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/c4ndlemandle/Documents/C++/qt_project_hse/build/Desktop_arm_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/qt_project_hse.dir/mainwindow.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/qt_project_hse.dir/mainwindow.cpp.o -MF CMakeFiles/qt_project_hse.dir/mainwindow.cpp.o.d -o CMakeFiles/qt_project_hse.dir/mainwindow.cpp.o -c /Users/c4ndlemandle/Documents/C++/qt_project_hse/mainwindow.cpp

CMakeFiles/qt_project_hse.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/qt_project_hse.dir/mainwindow.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/c4ndlemandle/Documents/C++/qt_project_hse/mainwindow.cpp > CMakeFiles/qt_project_hse.dir/mainwindow.cpp.i

CMakeFiles/qt_project_hse.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/qt_project_hse.dir/mainwindow.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/c4ndlemandle/Documents/C++/qt_project_hse/mainwindow.cpp -o CMakeFiles/qt_project_hse.dir/mainwindow.cpp.s

CMakeFiles/qt_project_hse.dir/offerslist.cpp.o: CMakeFiles/qt_project_hse.dir/flags.make
CMakeFiles/qt_project_hse.dir/offerslist.cpp.o: /Users/c4ndlemandle/Documents/C++/qt_project_hse/offerslist.cpp
CMakeFiles/qt_project_hse.dir/offerslist.cpp.o: CMakeFiles/qt_project_hse.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/c4ndlemandle/Documents/C++/qt_project_hse/build/Desktop_arm_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/qt_project_hse.dir/offerslist.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/qt_project_hse.dir/offerslist.cpp.o -MF CMakeFiles/qt_project_hse.dir/offerslist.cpp.o.d -o CMakeFiles/qt_project_hse.dir/offerslist.cpp.o -c /Users/c4ndlemandle/Documents/C++/qt_project_hse/offerslist.cpp

CMakeFiles/qt_project_hse.dir/offerslist.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/qt_project_hse.dir/offerslist.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/c4ndlemandle/Documents/C++/qt_project_hse/offerslist.cpp > CMakeFiles/qt_project_hse.dir/offerslist.cpp.i

CMakeFiles/qt_project_hse.dir/offerslist.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/qt_project_hse.dir/offerslist.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/c4ndlemandle/Documents/C++/qt_project_hse/offerslist.cpp -o CMakeFiles/qt_project_hse.dir/offerslist.cpp.s

CMakeFiles/qt_project_hse.dir/car.cpp.o: CMakeFiles/qt_project_hse.dir/flags.make
CMakeFiles/qt_project_hse.dir/car.cpp.o: /Users/c4ndlemandle/Documents/C++/qt_project_hse/car.cpp
CMakeFiles/qt_project_hse.dir/car.cpp.o: CMakeFiles/qt_project_hse.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/c4ndlemandle/Documents/C++/qt_project_hse/build/Desktop_arm_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/qt_project_hse.dir/car.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/qt_project_hse.dir/car.cpp.o -MF CMakeFiles/qt_project_hse.dir/car.cpp.o.d -o CMakeFiles/qt_project_hse.dir/car.cpp.o -c /Users/c4ndlemandle/Documents/C++/qt_project_hse/car.cpp

CMakeFiles/qt_project_hse.dir/car.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/qt_project_hse.dir/car.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/c4ndlemandle/Documents/C++/qt_project_hse/car.cpp > CMakeFiles/qt_project_hse.dir/car.cpp.i

CMakeFiles/qt_project_hse.dir/car.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/qt_project_hse.dir/car.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/c4ndlemandle/Documents/C++/qt_project_hse/car.cpp -o CMakeFiles/qt_project_hse.dir/car.cpp.s

CMakeFiles/qt_project_hse.dir/offerwindow.cpp.o: CMakeFiles/qt_project_hse.dir/flags.make
CMakeFiles/qt_project_hse.dir/offerwindow.cpp.o: /Users/c4ndlemandle/Documents/C++/qt_project_hse/offerwindow.cpp
CMakeFiles/qt_project_hse.dir/offerwindow.cpp.o: CMakeFiles/qt_project_hse.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/c4ndlemandle/Documents/C++/qt_project_hse/build/Desktop_arm_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/qt_project_hse.dir/offerwindow.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/qt_project_hse.dir/offerwindow.cpp.o -MF CMakeFiles/qt_project_hse.dir/offerwindow.cpp.o.d -o CMakeFiles/qt_project_hse.dir/offerwindow.cpp.o -c /Users/c4ndlemandle/Documents/C++/qt_project_hse/offerwindow.cpp

CMakeFiles/qt_project_hse.dir/offerwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/qt_project_hse.dir/offerwindow.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/c4ndlemandle/Documents/C++/qt_project_hse/offerwindow.cpp > CMakeFiles/qt_project_hse.dir/offerwindow.cpp.i

CMakeFiles/qt_project_hse.dir/offerwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/qt_project_hse.dir/offerwindow.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/c4ndlemandle/Documents/C++/qt_project_hse/offerwindow.cpp -o CMakeFiles/qt_project_hse.dir/offerwindow.cpp.s

# Object files for target qt_project_hse
qt_project_hse_OBJECTS = \
"CMakeFiles/qt_project_hse.dir/qt_project_hse_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/qt_project_hse.dir/main.cpp.o" \
"CMakeFiles/qt_project_hse.dir/mainwindow.cpp.o" \
"CMakeFiles/qt_project_hse.dir/offerslist.cpp.o" \
"CMakeFiles/qt_project_hse.dir/car.cpp.o" \
"CMakeFiles/qt_project_hse.dir/offerwindow.cpp.o"

# External object files for target qt_project_hse
qt_project_hse_EXTERNAL_OBJECTS =

qt_project_hse.app/Contents/MacOS/qt_project_hse: CMakeFiles/qt_project_hse.dir/qt_project_hse_autogen/mocs_compilation.cpp.o
qt_project_hse.app/Contents/MacOS/qt_project_hse: CMakeFiles/qt_project_hse.dir/main.cpp.o
qt_project_hse.app/Contents/MacOS/qt_project_hse: CMakeFiles/qt_project_hse.dir/mainwindow.cpp.o
qt_project_hse.app/Contents/MacOS/qt_project_hse: CMakeFiles/qt_project_hse.dir/offerslist.cpp.o
qt_project_hse.app/Contents/MacOS/qt_project_hse: CMakeFiles/qt_project_hse.dir/car.cpp.o
qt_project_hse.app/Contents/MacOS/qt_project_hse: CMakeFiles/qt_project_hse.dir/offerwindow.cpp.o
qt_project_hse.app/Contents/MacOS/qt_project_hse: CMakeFiles/qt_project_hse.dir/build.make
qt_project_hse.app/Contents/MacOS/qt_project_hse: /opt/homebrew/lib/QtWidgets.framework/Versions/A/QtWidgets
qt_project_hse.app/Contents/MacOS/qt_project_hse: /opt/homebrew/lib/QtGui.framework/Versions/A/QtGui
qt_project_hse.app/Contents/MacOS/qt_project_hse: /opt/homebrew/lib/QtCore.framework/Versions/A/QtCore
qt_project_hse.app/Contents/MacOS/qt_project_hse: CMakeFiles/qt_project_hse.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/c4ndlemandle/Documents/C++/qt_project_hse/build/Desktop_arm_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable qt_project_hse.app/Contents/MacOS/qt_project_hse"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/qt_project_hse.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/qt_project_hse.dir/build: qt_project_hse.app/Contents/MacOS/qt_project_hse
.PHONY : CMakeFiles/qt_project_hse.dir/build

CMakeFiles/qt_project_hse.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/qt_project_hse.dir/cmake_clean.cmake
.PHONY : CMakeFiles/qt_project_hse.dir/clean

CMakeFiles/qt_project_hse.dir/depend: qt_project_hse_autogen/timestamp
	cd /Users/c4ndlemandle/Documents/C++/qt_project_hse/build/Desktop_arm_darwin_generic_mach_o_64bit-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/c4ndlemandle/Documents/C++/qt_project_hse /Users/c4ndlemandle/Documents/C++/qt_project_hse /Users/c4ndlemandle/Documents/C++/qt_project_hse/build/Desktop_arm_darwin_generic_mach_o_64bit-Debug /Users/c4ndlemandle/Documents/C++/qt_project_hse/build/Desktop_arm_darwin_generic_mach_o_64bit-Debug /Users/c4ndlemandle/Documents/C++/qt_project_hse/build/Desktop_arm_darwin_generic_mach_o_64bit-Debug/CMakeFiles/qt_project_hse.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/qt_project_hse.dir/depend

