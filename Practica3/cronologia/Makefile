SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/union_cronologias $(BIN)/filtradoPalabraClave $(BIN)/filtradoIntervalo $(BIN)/estadisticaEventos

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
# Nota: Esto es solo una posible forma de compilar este proyecto. Modificar según sea necesario.

$(BIN)/estadisticaEventos: $(OBJ)/estadisticaEventos.o $(OBJ)/cronologia.o $(OBJ)/fechahistorica.o
	$(CXX) -o $(BIN)/estadisticaEventos $(OBJ)/estadisticaEventos.o $(OBJ)/cronologia.o $(OBJ)/fechahistorica.o

$(OBJ)/estadisticaEventos.o : $(SRC)/estadisticaEventos.cpp 
	$(CXX) $(CPPFLAGS) -o $(OBJ)/estadisticaEventos.o $(SRC)/estadisticaEventos.cpp

$(BIN)/union_cronologias: $(OBJ)/union_cronologias.o $(OBJ)/cronologia.o $(OBJ)/fechahistorica.o
	$(CXX) -o $(BIN)/union_cronologias $(OBJ)/union_cronologias.o $(OBJ)/cronologia.o $(OBJ)/fechahistorica.o

$(OBJ)/union_cronologias.o : $(SRC)/union_cronologias.cpp 
	$(CXX) $(CPPFLAGS) -o $(OBJ)/union_cronologias.o $(SRC)/union_cronologias.cpp

$(BIN)/filtradoIntervalo: $(OBJ)/filtradoIntervalo.o $(OBJ)/cronologia.o $(OBJ)/fechahistorica.o
	$(CXX) -o $(BIN)/filtradoIntervalo $(OBJ)/filtradoIntervalo.o $(OBJ)/cronologia.o $(OBJ)/fechahistorica.o

$(OBJ)/filtradoIntervalo.o : $(SRC)/filtradoIntervalo.cpp 
	$(CXX) $(CPPFLAGS) -o $(OBJ)/filtradoIntervalo.o $(SRC)/filtradoIntervalo.cpp

$(BIN)/filtradoPalabraClave: $(OBJ)/filtradoPalabraClave.o $(OBJ)/cronologia.o $(OBJ)/fechahistorica.o
	$(CXX) -o $(BIN)/filtradoPalabraClave $(OBJ)/filtradoPalabraClave.o $(OBJ)/cronologia.o $(OBJ)/fechahistorica.o

$(OBJ)/filtradoPalabraClave.o : $(SRC)/filtradoPalabraClave.cpp 
	$(CXX) $(CPPFLAGS) -o $(OBJ)/filtradoPalabraClave.o $(SRC)/filtradoPalabraClave.cpp

$(OBJ)/cronologia.o : $(SRC)/cronologia.cpp $(INC)/cronologia_stl.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/cronologia.o $(SRC)/cronologia.cpp

$(OBJ)/fechahistorica.o : $(SRC)/fechahistorica.cpp $(INC)/fechahistorica_stl.h 
	$(CXX) $(CPPFLAGS) -o $(OBJ)/fechahistorica.o $(SRC)/fechahistorica.cpp



# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
