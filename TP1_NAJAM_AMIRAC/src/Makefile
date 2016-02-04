# Options de compilation :
CXX = g++
O3 = #-O3 
CXXFLAGS = -Wall -Wextra -g $(O3) 
LDFLAGS = #-lm -pg
SRC = $(wildcard main*.cpp)
SRC2 = $(wildcard *.cpp)
BIN = $(patsubst %.cpp, bin/%, $(SRC))
BIN2 =  $(patsubst %.cpp, obj/%.o, $(SRC2))
BIN3 =  $(patsubst %.cpp, %.cpp, $(SRC))

all : $(BIN2) all2

all2 : $(BIN)

bin/main% : obj/Dvector.o  obj/main%.o
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

obj/%.o : %.cpp
	$(CXX) -c $^ $(CXXFLAGS) $(LDFLAGS) -o $@

.PHONY : clean
clean :
	rm -f *.o *~ gmon.out \#* $(BIN) obj/*.o bin/*
