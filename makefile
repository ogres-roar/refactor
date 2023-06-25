CXX = clang++
STD = -std=c++11
TARGET = rent
SUBDIR = src
FLAG = -Werror
BUILDDIR = build

OBJ = ${BUILDDIR}/main.o ${BUILDDIR}/rent/customer.o ${BUILDDIR}/rent/movie.o ${BUILDDIR}/rent/rental.o

all: clean dir ${SUBDIR} ${TARGET}

dir:
	mkdir -p ${BUILDDIR}

${SUBDIR}:
	${MAKE} -C ${SUBDIR} BUILDDIR=${BUILDDIR}

${TARGET}:
	${CXX} ${STD} ${FLAG} ${OBJ} -o ${TARGET}

.PHONY : clean
clean:
	rm -rf ${BUILDDIR} 

