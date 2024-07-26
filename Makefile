run1: sample1
	./sample1

run2: sample2
	./sample2

sample1: code1.S.o main.cpp.o
	c++ -o sample1 code1.S.o main.cpp.o

sample2: code2.S.o main.cpp.o
	c++ -o sample2 code2.S.o main.cpp.o

code1.S.o: code1.S
	cc -o code1.S.o -O3 code1.S -c

code2.S.o: code2.S
	cc -o code2.S.o -O3 code2.S -c

main.cpp.o: main.cpp
	c++ -o main.cpp.o main.cpp -c

clean: 
	rm sample1 sample2 code1.S.o code2.S.o main.cpp.o
