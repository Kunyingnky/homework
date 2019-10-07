object = fun.o fun2.o main.o
cc = gcc
main : $(object)
	gcc -o main $(object)	
fun.o : fun.c
	gcc -c fun.c
fun2.o : fun2.c
	gcc -c fun2.c
main.o : main.c 
	gcc -c main.c 
clean:
	rm -rf main $(object)