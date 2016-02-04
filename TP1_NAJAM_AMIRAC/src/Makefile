# Options de compilation :
CXX = g++
O3 = #-O3 
CXXFLAGS = -Wall -Wextra -g $(O3) 
LDFLAGS = #-lm -pg
SRC = $(wildcard main*.cpp)
BIN = $(patsubst %.cpp, %, $(SRC))

all : $(BIN)

main% : obj/Dvector.o  obj/main%.o
	$(CXX) -o bin/$@ $^ $(CXXFLAGS) $(LDFLAGS)

obj/main%.o : main%.cpp
	$(CXX) -c $^ $(CXXFLAGS) $(LDFLAGS) -o $@

obj/Dvector.o : Dvector.cpp
	$(CXX) -c $^ $(CXXFLAGS) $(LDFLAGS) -o $@

.PHONY : clean
clean :
	rm -f *.o *~ gmon.out \#* $(BIN) obj/*.o bin/*
