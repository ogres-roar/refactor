CXX = clang++
STD = -std=c++11
FLAG = -Werror
CFLAG = -c
DIR = ${BUILDDIR}

all: clean dir customer movie rental

dir:
	mkdir -p ../${DIR}

movie:movie.o
	${CXX} ${STD} ${FLAG} ${CFLAG} movie.cpp -o ../${DIR}/movie.o

rental:rental.o
	${CXX} ${STD} ${FLAG} ${CFLAG} rental.cpp -o ../${DIR}/rental.o

customer:customer.o
	${CXX} ${STD} ${FLAG} ${CFLAG} customer.cpp -o ../${DIR}/customer.o

clean:
	rm -rf ../${DIR}

.cpp.o:
	$(CXX) ${STD} $(FLAG) ${CFLAG} $< -o ../${DIR}/$@
