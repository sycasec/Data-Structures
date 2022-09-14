main: game.o test.o
	g++ game.o test.o

game.o: game.cpp
	g++ -c game.cpp

test.o: test.cpp
	g++ -c test.cpp

clean:
	rm *.o main