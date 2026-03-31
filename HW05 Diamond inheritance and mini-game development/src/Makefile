CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -g -fsanitize=address -I ../include

all: ../lib/spotify_test

../lib/spotify_test: ../lib/artist.o ../lib/artistList.o ../lib/parse_csv.o ../lib/main.o
	$(CXX) $(CXXFLAGS) ../lib/artist.o ../lib/artistList.o ../lib/parse_csv.o ../lib/main.o -o ../lib/spotify_test

../lib/artist.o: artist.cpp
	mkdir -p ../lib
	$(CXX) $(CXXFLAGS) -c artist.cpp -o ../lib/artist.o

../lib/artistList.o: artistList.cpp ../include/artistList.hpp
	mkdir -p ../lib
	$(CXX) $(CXXFLAGS) -c artistList.cpp -o ../lib/artistList.o

../lib/parse_csv.o: parse_csv.cpp ../include/parse_csv.hpp
	mkdir -p ../lib
	$(CXX) $(CXXFLAGS) -c parse_csv.cpp -o ../lib/parse_csv.o

../lib/main.o: main.cpp
	mkdir -p ../lib
	$(CXX) $(CXXFLAGS) -c main.cpp -o ../lib/main.o

clean:
	rm -rf ../lib/*.o ../lib/spotify_test
