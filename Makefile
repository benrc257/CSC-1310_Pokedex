# TO COMPILE WITH MAKEFILE ON WINDOWS, DO "mingw32-make"
# IF ON MAC OR LINUX, USE "make"

# settings
CXX = @g++
CXXFLAGS = -c

# file names
functions := functions.cpp
driver := driver.cpp
pokemon := Classes/pokemon.cpp
files := ${functions} ${driver} ${pokemon}

# object names
output := Pokedex
all := all
driverout := driver.o
functionsout := functions.o
pokemonout := pokemon.o
objects := ${driverout} ${functionsout} ${pokemonout}

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
${pokemonout}: ${pokemon}
	${CXX} ${CXXFLAGS} ${pokemon} -o ${pokemonout}

# Make clean (Removes files)
clean:
	${RM} ${objects} ${output}
	@echo "Removed build files"