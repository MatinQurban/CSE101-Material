CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = main
OBJS = main.o bst.o

all: $(TARGET) 

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp bst.h
	$(CXX) $(CXXFLAGS) -c main.cpp

bst.o: bst.cpp bst.h
	$(CXX) $(CXXFLAGS) -c bst.cpp

clean:
	rm -f $(OBJS) $(TARGET)