CPP := g++

all:

	$(CPP) -o prog main.cpp

clean:

	rm prog

run:

	./prog