#Provide a Makefile for testing the library(with targets clean, test)
CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++17
LFLAGS = -lgtest

.PHONY: clean all test rebuild

HEADERS = s21_containerplus.hpp

TEST_SOURCES = $(wildcard tests/*.cpp)
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: test

test: $(TEST_OBJECTS) $(HEADERS)
	$(CXX) $^ $(LFLAGS) -o $@
	./test

clean:
	rm -rf tests/*.o test