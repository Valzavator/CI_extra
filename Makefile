# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

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
CMAKE_SOURCE_DIR = /home/valzavator/GitHub/CI_extra

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/valzavator/GitHub/CI_extra

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running interactive CMake command-line interface..."
	/usr/bin/cmake -i .
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: install/local
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: install/strip
.PHONY : install/strip/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target test
test:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running tests..."
	/usr/bin/ctest --force-new-ctest-process $(ARGS)
.PHONY : test

# Special rule for the target test
test/fast: test
.PHONY : test/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/valzavator/GitHub/CI_extra/CMakeFiles /home/valzavator/GitHub/CI_extra/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/valzavator/GitHub/CI_extra/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named a.out

# Build rule for target.
a.out: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 a.out
.PHONY : a.out

# fast build rule for target.
a.out/fast:
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/build
.PHONY : a.out/fast

#=============================================================================
# Target rules for targets named a.out_coverage

# Build rule for target.
a.out_coverage: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 a.out_coverage
.PHONY : a.out_coverage

# fast build rule for target.
a.out_coverage/fast:
	$(MAKE) -f CMakeFiles/a.out_coverage.dir/build.make CMakeFiles/a.out_coverage.dir/build
.PHONY : a.out_coverage/fast

#=============================================================================
# Target rules for targets named mymodule

# Build rule for target.
mymodule: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 mymodule
.PHONY : mymodule

# fast build rule for target.
mymodule/fast:
	$(MAKE) -f CMakeFiles/mymodule.dir/build.make CMakeFiles/mymodule.dir/build
.PHONY : mymodule/fast

src/ci.o: src/ci.c.o
.PHONY : src/ci.o

# target to build an object file
src/ci.c.o:
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/src/ci.c.o
	$(MAKE) -f CMakeFiles/mymodule.dir/build.make CMakeFiles/mymodule.dir/src/ci.c.o
.PHONY : src/ci.c.o

src/ci.i: src/ci.c.i
.PHONY : src/ci.i

# target to preprocess a source file
src/ci.c.i:
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/src/ci.c.i
	$(MAKE) -f CMakeFiles/mymodule.dir/build.make CMakeFiles/mymodule.dir/src/ci.c.i
.PHONY : src/ci.c.i

src/ci.s: src/ci.c.s
.PHONY : src/ci.s

# target to generate assembly for a file
src/ci.c.s:
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/src/ci.c.s
	$(MAKE) -f CMakeFiles/mymodule.dir/build.make CMakeFiles/mymodule.dir/src/ci.c.s
.PHONY : src/ci.c.s

src/list.o: src/list.c.o
.PHONY : src/list.o

# target to build an object file
src/list.c.o:
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/src/list.c.o
	$(MAKE) -f CMakeFiles/mymodule.dir/build.make CMakeFiles/mymodule.dir/src/list.c.o
.PHONY : src/list.c.o

src/list.i: src/list.c.i
.PHONY : src/list.i

# target to preprocess a source file
src/list.c.i:
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/src/list.c.i
	$(MAKE) -f CMakeFiles/mymodule.dir/build.make CMakeFiles/mymodule.dir/src/list.c.i
.PHONY : src/list.c.i

src/list.s: src/list.c.s
.PHONY : src/list.s

# target to generate assembly for a file
src/list.c.s:
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/src/list.c.s
	$(MAKE) -f CMakeFiles/mymodule.dir/build.make CMakeFiles/mymodule.dir/src/list.c.s
.PHONY : src/list.c.s

tests/main.o: tests/main.c.o
.PHONY : tests/main.o

# target to build an object file
tests/main.c.o:
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/tests/main.c.o
.PHONY : tests/main.c.o

tests/main.i: tests/main.c.i
.PHONY : tests/main.i

# target to preprocess a source file
tests/main.c.i:
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/tests/main.c.i
.PHONY : tests/main.c.i

tests/main.s: tests/main.c.s
.PHONY : tests/main.s

# target to generate assembly for a file
tests/main.c.s:
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/tests/main.c.s
.PHONY : tests/main.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... a.out"
	@echo "... a.out_coverage"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... mymodule"
	@echo "... rebuild_cache"
	@echo "... test"
	@echo "... src/ci.o"
	@echo "... src/ci.i"
	@echo "... src/ci.s"
	@echo "... src/list.o"
	@echo "... src/list.i"
	@echo "... src/list.s"
	@echo "... tests/main.o"
	@echo "... tests/main.i"
	@echo "... tests/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

