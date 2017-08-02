lab4: lab4.cpp Sdisk.o Filesys.o
	g++ -o lab4 lab4.cpp Sdisk.o Filesys.o

Filesys.o: Filesys.h Filesys.cpp
	g++ -c Filesys.cpp

Sdisk.o: Sdisk.h Sdisk.cpp
	g++ -c Sdisk.cpp

clean:
	rm *.o lab4
