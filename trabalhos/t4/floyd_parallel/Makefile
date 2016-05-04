CXX=g++
#CXXFLAGS=-Wall -I. -O2 -DNDEBUG
CXXFLAGS=-Wall -I. -fopenmp
OBJS=Graph.o floyd_parallel.o
PROGS=floyd_parallel
floyd_parallel: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)
all: $(PROGS)
clean:
	rm -f *.o $(PROGS)
