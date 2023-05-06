#use the following commands
# 1. make person.o
#    this will compile your extPersonTypeImp.cpp file
#    into an object file called person.o
# 2. make test
#    this will make the unit test on person.o
#    and generate an execute file called test
# 3. make
#    this will compile your project3.cpp and
#    generate a.out
# 4. make clean
#    this will delete all the files g++ generated

# first you need to make the following changes


#change the file name project3.cpp to project3_YourName.cpp
#on the following two lines
a.out: project3_KodyKnight.cpp person.o personTypeImp.o addressTypeImp.o dateTypeImp.o
	g++ project3_KodyKnight.cpp *.o

test: extPersonTypeUnitTest.cpp person.o personTypeImp.o addressTypeImp.o dateTypeImp.o
	g++ extPersonTypeUnitTest.cpp *.o -o test

#change the file name extPersonTypeImp.cpp to
#extPersonTypeImp_YourName.cpp on
#the following two lines
person.o: extPersonType.h extPersonTypeImp_KodyKnight.cpp
	g++ -c extPersonTypeImp_KodyKnight.cpp -o person.o

clean:
	rm a.out person.o test *~

