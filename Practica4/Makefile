SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/pruebaTrie

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
# Nota: Esto es solo una posible forma de compilar este proyecto. Modificar según sea necesario.

$(BIN)/pruebaTrie: $(OBJ)/pruebaTrie.o $(OBJ)/trie.o
	$(CXX) -o $(BIN)/pruebaTrie $(OBJ)/pruebaTrie.o $(OBJ)/trie.o

$(OBJ)/pruebaTrie.o : $(SRC)/pruebaTrie.cpp 
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pruebaTrie.o $(SRC)/pruebaTrie.cpp

$(OBJ)/trie.o : $(SRC)/trie.cpp $(INC)/trie.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/trie.o $(SRC)/trie.cpp


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
