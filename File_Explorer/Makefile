# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall

# Target executable
TARGET = File_Explorer

# Test executable
TEST_TARGET = test_file_explorer

# Source files
SRCS = main.cpp file_operations.cpp directory_operations.cpp search_operations.cpp permission_operations.cpp logger.cpp

# Test source files
TEST_SRCS = test_file_explorer.cpp file_operations.cpp directory_operations.cpp search_operations.cpp permission_operations.cpp logger.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Test object files
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# Header files
HEADERS = file_operations.h directory_operations.h search_operations.h permission_operations.h logger.h

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJS)

# Compiling
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(TARGET) $(OBJS) $(TEST_TARGET) $(TEST_OBJS)
	
     	
