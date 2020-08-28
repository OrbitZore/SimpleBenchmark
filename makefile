main : main.cpp timing.o random.o
	g++ -o main main.cpp timing.o random.o -std=c++11
timing.o : timing.cpp timing.hpp
	g++ -c -o timing.o timing.cpp -std=c++11
random.o : random.cpp random.hpp
	g++ -c -o random.o random.cpp -std=c++11
