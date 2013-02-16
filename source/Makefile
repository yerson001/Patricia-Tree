patricia: Patricia_Tree.o main.o
	g++ -Wall -pedantic -g -o patricia Patricia_Tree.o main.o
	
main.o: Patricia_Tree.o
	g++ -Wall -pedantic -g -c main.cpp
	
Patricia_Tree.o: Patricia_Tree.h Patricia_Tree.cpp
	g++ -Wall -pedantic -g -c Patricia_Tree.cpp
	
clean: 
	rm -f patricia Patricia_Tree.o main.o