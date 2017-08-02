lab6: lab6.cpp Sdisk.o Filesys.o Shell.o
	g++ -o lab6 lab6.cpp Sdisk.o Filesys.o Shell.o

Shell.o: Shell.h Shell.cpp
	g++ -c Shell.cpp

Filesys.o: Filesys.h Filesys.cpp
	g++ -c Filesys.cpp

Sdisk.o: Sdisk.h Sdisk.cpp
	g++ -c Sdisk.cpp

clean:
	rm *.o lab6
