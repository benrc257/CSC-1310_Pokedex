# TO COMPILE WITH MAKEFILE ON WINDOWS, DO "mingw32-make"
# IF ON MAC OR LINUX, USE "make"

# settings
CXX = @g++
CXXFLAGS = -c

# file names
functions := functions.cpp
driver := driver.cpp
sorter := Classes/sorter.cpp
playlist := Classes/playlist.cpp
files := ${functions} ${driver} ${playlist} ${sorter}

# object names
output := PlaylistSorter
all := all
driverout := driver.o
functionsout := functions.o
sorterout := sorter.o
playlistout := playlist.o
objects := ${driverout} ${functionsout} ${sorterout} ${playlistout}

# Detect OS for clean
ifdef OS
   RM = @del -force
else
   ifeq ($(shell uname), Linux)
      RM = @rm -f
   endif
endif

# Compile output (All)
${all}: ${objects}
	${CXX} ${objects} -o ${output}
	${RM} ${objects}
	@echo "Output built successfully"

# Compile main
${driverout}: ${driver}
	${CXX} ${CXXFLAGS} ${driver} -o ${driverout}

${functionsout}: ${functions}
	${CXX} ${CXXFLAGS} ${functions} -o ${functionsout}

# Compile classes
${sorterout}: ${sorter}
	${CXX} ${CXXFLAGS} ${sorter} -o ${sorterout}

${playlistout}: ${playlist}
	${CXX} ${CXXFLAGS} ${playlist} -o ${playlistout}

# Make clean (Removes files)
clean:
	${RM} ${objects} ${output}
	@echo "Removed build files"