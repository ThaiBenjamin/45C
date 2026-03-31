CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -g -fsanitize=address -I include

all: lib/futsal_test

lib/futsal_test: lib/player.o lib/llqueue.o lib/futsal.o lib/hw03_main.o
	$(CXX) $(CXXFLAGS) lib/player.o lib/llqueue.o lib/futsal.o lib/hw03_main.o -o lib/futsal_test

lib/player.o: src/player.cpp include/player.h
	mkdir -p lib
	$(CXX) $(CXXFLAGS) -c src/player.cpp -o lib/player.o

lib/llqueue.o: src/llqueue.cpp include/llqueue.h
	mkdir -p lib
	$(CXX) $(CXXFLAGS) -c src/llqueue.cpp -o lib/llqueue.o

lib/futsal.o: src/futsal.cpp include/futsal.h
	mkdir -p lib
	$(CXX) $(CXXFLAGS) -c src/futsal.cpp -o lib/futsal.o

lib/hw03_main.o: src/hw03_main.cpp
	mkdir -p lib
	$(CXX) $(CXXFLAGS) -c src/hw03_main.cpp -o lib/hw03_main.o

clean:
	rm -rf lib