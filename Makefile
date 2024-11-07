# TO COMPILE WITH MAKEFILE ON WINDOWS, DO "mingw32-make"
# IF ON MAC OR LINUX, USE "make"

# settings
CXX = @g++
CXXFLAGS = -c

# file names
functions := functions.cpp
driver := driver.cpp
data := data.cpp
files := ${functions} ${driver} ${data}

# object names
output := 
all := all
driverout := driver.o
functionsout := functions.o
dataout := data.o
playlistout := playlist.o
objects := ${driverout} ${functionsout} ${dataout}

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
${dataout}: ${data}
	${CXX} ${CXXFLAGS} ${data} -o ${dataout}

# Make clean (Removes files)
clean:
	${RM} ${objects} ${output}
	@echo "Removed build files"