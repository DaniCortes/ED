CFLAGS=-Wall -g

ejercicio7: ejercicio7.o funciones_matrices.o
	g++ $(CFLAGS) ejercicio7.o funciones_matrices.o -o ejercicio7

ejercicio7.o: ejercicio7.cpp funciones_matrices.h
	g++ $(CFLAGS) -c ejercicio7.cpp -o ejercicio7.o

funciones_matrices.o: funciones_matrices.cpp funciones_matrices.cpp
	g++ $(CFLAGS) -c funciones_matrices.cpp -o funciones_matrices.o

clean:
	rm ejercicio7 *.o tiempos.dat