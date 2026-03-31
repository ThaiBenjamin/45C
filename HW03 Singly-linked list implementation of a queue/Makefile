# please write Makefile here
CXX=g++
CXXFLAGS = -Wall -std=c++20 -Iinclude

all: problem1_main problem2_main

problem1_main: problem1_main.cpp src/gen_number.cpp src/post_process.cpp src/print_menu.cpp
	$(CXX) $(CXXFLAGS) -o problem1_main problem1_main.cpp src/gen_number.cpp src/post_process.cpp src/print_menu.cpp

problem2_main: problem2_main.cpp src/matrix.cpp
	$(CXX) $(CXXFLAGS) -o problem2_main problem2_main.cpp src/matrix.cpp

clean:
	rm problem1_main problem2_main *.o