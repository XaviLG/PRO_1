# Definición de compoñentes
CC = g++
CFLAGS = -std=c++11 -Wall

# Nome do executable e ruta
TARGET = ./bin/executable.exe

# Arquivos fontes e ruta
SRC = ./src/main.cpp ./src/funcions.cpp ./src/lectura.cpp	./src/utils.cpp
OBJ = $(SRC:.cpp=.o)

# Regra principal
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Regra para compilar os arquivos .cpp a .o
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos xerados
clean:
	rm -f $(OBJ) $(TARGET)*
