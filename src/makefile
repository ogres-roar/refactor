CXX = clang++
STD = -std=c++11
FLAG = -Werror -Wall
CFLAG = -c
SUBDIR = rent
DIR = ${BUILDDIR}

all: clean ${SUBDIR} main

main:main.o
	${CXX} ${STD} ${FLAG} ${CFLAG} main.cpp -o ../${DIR}/main.o

${SUBDIR}: 
	${MAKE} -C $ BUILDDIR=../${DIR}/rent

clean:
	rm -rf ../${DIR}/*.o



.cpp.o:
	$(CXX) ${STD} $(FLAG) ${CFLAG} $< -o ../${DIR}/$@