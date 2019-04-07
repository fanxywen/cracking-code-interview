CC = g++
CFLAGS = -std=c++11 -ggdb3
three:three_in_one.cpp
	g++ -std=c++11 -o three three_in_one.cpp
plate:stackOfPlates.cpp
	g++ -ggdb3 -std=c++11 -o plate stackOfPlates.cpp
sortStack:sortStack.cpp
	$(CC) $(CFLAGS) -o sortStack sortStack.cpp
clean:
	rm -f *~ *.cpp~ *.h~
