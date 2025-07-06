CXX = clang++
CXXFLAGS = -std=c++23 -O1 -Wall -Wextra -Wpedantic
INCLUDE = -I./include

main.exe : main.cpp ./build/big_integer.o ./include/big_integer.hpp ./src/big_integer.cpp 
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ ./build/big_integer.o main.cpp

./build/big_integer.o : ./src/big_integer.cpp ./include/big_integer.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c -o $@ $<

clean : 
	$(RM) main.exe

run : main.exe
	./main.exe

.PHONY : run clean

