all:
	gcc -Wall -c main.c
	gcc -Wall -fPIC -c calc.c
	gcc -shared -o libcalc.so calc.o -ldl
	gcc main.o -L. -lcalc -o calc
	gcc -o main main.o libcalc.so -Wl,-rpath,. 
	rm  -f  *.o  *.so 

