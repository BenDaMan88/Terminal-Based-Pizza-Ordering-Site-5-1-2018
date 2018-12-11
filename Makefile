compiler = g++
exe = Assignment_2_exe

$(exe): Menu.o Pizza.o Restaurant.o main.o
	$(compiler) Menu.o Pizza.o Restaurant.o main.o -o $(exe)
Menu.o: Menu.cpp Menu.h
	$(compiler) -c Menu.cpp
Pizza.o: Pizza.cpp Pizza.h
	$(compiler) -c Pizza.cpp
Restaurant.o: Restaurant.cpp Restaurant.h
	$(compiler) -c Restaurant.cpp
main.o: main.cpp
	$(compiler) -c main.cpp
clean:
	rm -f *.out *.o $(exe)
