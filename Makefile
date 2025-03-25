OPTIMIZATION = -O3 -s

SRC = src
OBJ = obj
BIN = bin

TARGET = main
TARGET_FILE = $(TARGET)

SDL_CFLAGS = $(shell sdl2-config --cflags)
SDL_LIBS   = $(shell sdl2-config --libs)

hello: $(OBJ)/$(TARGET)/main.o
	echo "Создание bin $(TARGET_FILE)"
	mkdir -p $(BIN)/$(TARGET)
	g++ -o $(BIN)/$(TARGET)/$(TARGET_FILE) $(OPTIMIZATION) $^ $(SDL_LIBS)

$(OBJ)/$(TARGET)/main.o: main.cpp
	echo "Создание OBJ main.o"
	mkdir -p $(OBJ)/$(TARGET)
	g++ -c -o $@ $(OPTIMIZATION) -I$(SRC) $<


clean:
	echo "ОЧИСТКА"
	rm -rf $(OBJ)/*
	rm -rf $(BIN)/*