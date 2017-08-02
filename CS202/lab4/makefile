Person: Person_main.o Person.o
	g++ -o Person Person_main.o Person.o

Person_main.o: Person_main.cpp Person.h
	g++ -c Person_main.cpp

Person.o: Person.cpp Person.h
	g++ -c Person.cpp

clean:
	rm *.o Person