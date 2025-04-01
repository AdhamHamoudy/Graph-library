EMAIL = adhamhamoudy3@gmail.com

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Executables
MAIN_EXEC = main
TEST_EXEC = test

# Source files
SRCS = Graph.cpp Algorithms.cpp
OBJS = $(SRCS:.cpp=.o)

# Main demo target
main: main.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(MAIN_EXEC) main.cpp $(OBJS)

# Unit test target
test: test.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_EXEC) test.cpp $(OBJS)
	./$(TEST_EXEC)

# Valgrind memory leak check
valgrind: test.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_EXEC) test.cpp $(OBJS)
	valgrind --leak-check=full ./$(TEST_EXEC)

# Clean up
clean:
	rm -f *.o $(MAIN_EXEC) $(TEST_EXEC)
	
