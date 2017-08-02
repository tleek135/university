lab7: lab7.cpp Sdisk.o Filesys.o Table.o
	g++ -o lab7 lab7.cpp Sdisk.o Filesys.o Table.o

Table.o: Table.h Table.cpp
	g++ -c Table.cpp

Filesys.o: Filesys.h Filesys.cpp
	g++ -c Filesys.cpp

Sdisk.o: Sdisk.h Sdisk.cpp
	g++ -c Sdisk.cpp

clean:
	rm *.o lab7
