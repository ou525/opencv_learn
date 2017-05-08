# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/ou/Videos/opencv_learn

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ou/Videos/opencv_learn/build

# Include any dependencies generated for this target.
include src/CMakeFiles/60_EdgeDetection.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/60_EdgeDetection.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/60_EdgeDetection.dir/flags.make

src/CMakeFiles/60_EdgeDetection.dir/60_EdgeDetection.cpp.o: src/CMakeFiles/60_EdgeDetection.dir/flags.make
src/CMakeFiles/60_EdgeDetection.dir/60_EdgeDetection.cpp.o: ../src/60_EdgeDetection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ou/Videos/opencv_learn/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/60_EdgeDetection.dir/60_EdgeDetection.cpp.o"
	cd /home/ou/Videos/opencv_learn/build/src && g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/60_EdgeDetection.dir/60_EdgeDetection.cpp.o -c /home/ou/Videos/opencv_learn/src/60_EdgeDetection.cpp

src/CMakeFiles/60_EdgeDetection.dir/60_EdgeDetection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/60_EdgeDetection.dir/60_EdgeDetection.cpp.i"
	cd /home/ou/Videos/opencv_learn/build/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ou/Videos/opencv_learn/src/60_EdgeDetection.cpp > CMakeFiles/60_EdgeDetection.dir/60_EdgeDetection.cpp.i

src/CMakeFiles/60_EdgeDetection.dir/60_EdgeDetection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/60_EdgeDetection.dir/60_EdgeDetection.cpp.s"
	cd /home/ou/Videos/opencv_learn/build/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ou/Videos/opencv_learn/src/60_EdgeDetection.cpp -o CMakeFiles/60_EdgeDetection.dir/60_EdgeDetection.cpp.s

src/CMakeFiles/60_EdgeDetection.dir/60_EdgeDetection.cpp.o.requires:

.PHONY : src/CMakeFiles/60_EdgeDetection.dir/60_EdgeDetection.cpp.o.requires

src/CMakeFiles/60_EdgeDetection.dir/60_EdgeDetection.cpp.o.provides: src/CMakeFiles/60_EdgeDetection.dir/60_EdgeDetection.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/60_EdgeDetection.dir/build.make src/CMakeFiles/60_EdgeDetection.dir/60_EdgeDetection.cpp.o.provides.build
.PHONY : src/CMakeFiles/60_EdgeDetection.dir/60_EdgeDetection.cpp.o.provides

src/CMakeFiles/60_EdgeDetection.dir/60_EdgeDetection.cpp.o.provides.build: src/CMakeFiles/60_EdgeDetection.dir/60_EdgeDetection.cpp.o


# Object files for target 60_EdgeDetection
60_EdgeDetection_OBJECTS = \
"CMakeFiles/60_EdgeDetection.dir/60_EdgeDetection.cpp.o"

# External object files for target 60_EdgeDetection
60_EdgeDetection_EXTERNAL_OBJECTS =

../bin/60_EdgeDetection: src/CMakeFiles/60_EdgeDetection.dir/60_EdgeDetection.cpp.o
../bin/60_EdgeDetection: src/CMakeFiles/60_EdgeDetection.dir/build.make
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_stitching3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_superres3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_videostab3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_aruco3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_bgsegm3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_bioinspired3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_ccalib3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_cvv3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_datasets3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_dpm3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_face3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_fuzzy3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_hdf3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_line_descriptor3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_optflow3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_plot3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_reg3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_saliency3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_stereo3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_structured_light3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_surface_matching3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_text3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_xfeatures2d3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_ximgproc3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_xobjdetect3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_xphoto3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_shape3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_video3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_viz3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_phase_unwrapping3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_rgbd3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_calib3d3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_features2d3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_flann3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_objdetect3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_ml3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_highgui3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_photo3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_videoio3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_imgcodecs3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_imgproc3.so.3.2.0
../bin/60_EdgeDetection: /opt/ros/kinetic/lib/libopencv_core3.so.3.2.0
../bin/60_EdgeDetection: src/CMakeFiles/60_EdgeDetection.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ou/Videos/opencv_learn/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/60_EdgeDetection"
	cd /home/ou/Videos/opencv_learn/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/60_EdgeDetection.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/60_EdgeDetection.dir/build: ../bin/60_EdgeDetection

.PHONY : src/CMakeFiles/60_EdgeDetection.dir/build

src/CMakeFiles/60_EdgeDetection.dir/requires: src/CMakeFiles/60_EdgeDetection.dir/60_EdgeDetection.cpp.o.requires

.PHONY : src/CMakeFiles/60_EdgeDetection.dir/requires

src/CMakeFiles/60_EdgeDetection.dir/clean:
	cd /home/ou/Videos/opencv_learn/build/src && $(CMAKE_COMMAND) -P CMakeFiles/60_EdgeDetection.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/60_EdgeDetection.dir/clean

src/CMakeFiles/60_EdgeDetection.dir/depend:
	cd /home/ou/Videos/opencv_learn/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ou/Videos/opencv_learn /home/ou/Videos/opencv_learn/src /home/ou/Videos/opencv_learn/build /home/ou/Videos/opencv_learn/build/src /home/ou/Videos/opencv_learn/build/src/CMakeFiles/60_EdgeDetection.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/60_EdgeDetection.dir/depend

