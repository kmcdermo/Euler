CPPFLAGS := -pthread -m64
CXXFLAGS := -std=c++20 -O3 -g
LDFLAGS  := -lpthread -lm -ldl

TGTS := main

EXES := ${TGTS}

SRCS := $(wildcard *.cc)
DEPS := $(SRCS:.cc=.d)
OBJS := $(SRCS:.cc=.o)

-include ${DEPS}

main: ${OBJS} 
	${CXX} ${CXXFLAGS} -o $@ ${OBJS}  ${LDFLAGS}

${OBJS}: %.o: %.cc
	${CXX} ${CPPFLAGS} ${CXXFLAGS} -c -o $@ $<

HEADERS := $(wildcard *.hh)

dict.cc: ${HEADERS} 
	rootcling -f $@ -c -p $^

clean:
	-rm -f ${EXES} *.d *.o *.pcm *~

