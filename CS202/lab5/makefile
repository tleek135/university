Person_main: Person.o Student.o Instructor.o Person_main_using_UML.cpp
	g++ -o Person_main Person.o Student.o Instructor.o Person_main_using_UML.cpp

Instructor.o: Instructor.h Instructor.cpp Person.o
	g++ -c Instructor.cpp

Student.o: Student.h Student.cpp Person.o
	g++ -c Student.cpp

Person.o: Person.h Person.cpp
	g++ -c Person.cpp

clean: 
	rm *.o Person_main
