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
include src/CMakeFiles/30_Read_XML_and_YAML_File.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/30_Read_XML_and_YAML_File.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/30_Read_XML_and_YAML_File.dir/flags.make

src/CMakeFiles/30_Read_XML_and_YAML_File.dir/30_Read_XML_and_YAML_File.cpp.o: src/CMakeFiles/30_Read_XML_and_YAML_File.dir/flags.make
src/CMakeFiles/30_Read_XML_and_YAML_File.dir/30_Read_XML_and_YAML_File.cpp.o: ../src/30_Read_XML_and_YAML_File.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ou/Videos/opencv_learn/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/30_Read_XML_and_YAML_File.dir/30_Read_XML_and_YAML_File.cpp.o"
	cd /home/ou/Videos/opencv_learn/build/src && g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/30_Read_XML_and_YAML_File.dir/30_Read_XML_and_YAML_File.cpp.o -c /home/ou/Videos/opencv_learn/src/30_Read_XML_and_YAML_File.cpp

src/CMakeFiles/30_Read_XML_and_YAML_File.dir/30_Read_XML_and_YAML_File.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/30_Read_XML_and_YAML_File.dir/30_Read_XML_and_YAML_File.cpp.i"
	cd /home/ou/Videos/opencv_learn/build/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ou/Videos/opencv_learn/src/30_Read_XML_and_YAML_File.cpp > CMakeFiles/30_Read_XML_and_YAML_File.dir/30_Read_XML_and_YAML_File.cpp.i

src/CMakeFiles/30_Read_XML_and_YAML_File.dir/30_Read_XML_and_YAML_File.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/30_Read_XML_and_YAML_File.dir/30_Read_XML_and_YAML_File.cpp.s"
	cd /home/ou/Videos/opencv_learn/build/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ou/Videos/opencv_learn/src/30_Read_XML_and_YAML_File.cpp -o CMakeFiles/30_Read_XML_and_YAML_File.dir/30_Read_XML_and_YAML_File.cpp.s

src/CMakeFiles/30_Read_XML_and_YAML_File.dir/30_Read_XML_and_YAML_File.cpp.o.requires:

.PHONY : src/CMakeFiles/30_Read_XML_and_YAML_File.dir/30_Read_XML_and_YAML_File.cpp.o.requires

src/CMakeFiles/30_Read_XML_and_YAML_File.dir/30_Read_XML_and_YAML_File.cpp.o.provides: src/CMakeFiles/30_Read_XML_and_YAML_File.dir/30_Read_XML_and_YAML_File.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/30_Read_XML_and_YAML_File.dir/build.make src/CMakeFiles/30_Read_XML_and_YAML_File.dir/30_Read_XML_and_YAML_File.cpp.o.provides.build
.PHONY : src/CMakeFiles/30_Read_XML_and_YAML_File.dir/30_Read_XML_and_YAML_File.cpp.o.provides

src/CMakeFiles/30_Read_XML_and_YAML_File.dir/30_Read_XML_and_YAML_File.cpp.o.provides.build: src/CMakeFiles/30_Read_XML_and_YAML_File.dir/30_Read_XML_and_YAML_File.cpp.o


# Object files for target 30_Read_XML_and_YAML_File
30_Read_XML_and_YAML_File_OBJECTS = \
"CMakeFiles/30_Read_XML_and_YAML_File.dir/30_Read_XML_and_YAML_File.cpp.o"

# External object files for target 30_Read_XML_and_YAML_File
30_Read_XML_and_YAML_File_EXTERNAL_OBJECTS =

../bin/30_Read_XML_and_YAML_File: src/CMakeFiles/30_Read_XML_and_YAML_File.dir/30_Read_XML_and_YAML_File.cpp.o
../bin/30_Read_XML_and_YAML_File: src/CMakeFiles/30_Read_XML_and_YAML_File.dir/build.make
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_stitching3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_superres3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_videostab3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_aruco3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_bgsegm3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_bioinspired3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_ccalib3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_cvv3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_datasets3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_dpm3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_face3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_fuzzy3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_hdf3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_line_descriptor3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_optflow3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_plot3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_reg3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_saliency3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_stereo3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_structured_light3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_surface_matching3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_text3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_xfeatures2d3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_ximgproc3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_xobjdetect3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_xphoto3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_shape3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_video3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_viz3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_phase_unwrapping3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_rgbd3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_calib3d3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_features2d3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_flann3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_objdetect3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_ml3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_highgui3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_photo3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_videoio3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_imgcodecs3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_imgproc3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: /opt/ros/kinetic/lib/libopencv_core3.so.3.2.0
../bin/30_Read_XML_and_YAML_File: src/CMakeFiles/30_Read_XML_and_YAML_File.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ou/Videos/opencv_learn/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/30_Read_XML_and_YAML_File"
	cd /home/ou/Videos/opencv_learn/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/30_Read_XML_and_YAML_File.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/30_Read_XML_and_YAML_File.dir/build: ../bin/30_Read_XML_and_YAML_File

.PHONY : src/CMakeFiles/30_Read_XML_and_YAML_File.dir/build

src/CMakeFiles/30_Read_XML_and_YAML_File.dir/requires: src/CMakeFiles/30_Read_XML_and_YAML_File.dir/30_Read_XML_and_YAML_File.cpp.o.requires

.PHONY : src/CMakeFiles/30_Read_XML_and_YAML_File.dir/requires

src/CMakeFiles/30_Read_XML_and_YAML_File.dir/clean:
	cd /home/ou/Videos/opencv_learn/build/src && $(CMAKE_COMMAND) -P CMakeFiles/30_Read_XML_and_YAML_File.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/30_Read_XML_and_YAML_File.dir/clean

src/CMakeFiles/30_Read_XML_and_YAML_File.dir/depend:
	cd /home/ou/Videos/opencv_learn/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ou/Videos/opencv_learn /home/ou/Videos/opencv_learn/src /home/ou/Videos/opencv_learn/build /home/ou/Videos/opencv_learn/build/src /home/ou/Videos/opencv_learn/build/src/CMakeFiles/30_Read_XML_and_YAML_File.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/30_Read_XML_and_YAML_File.dir/depend
