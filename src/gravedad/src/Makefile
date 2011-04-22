LIBS =  -lSDL
CFLAGS = -Wall
BIN = gravedad
OBJ = main.o pelota.o fps.o util.o

all: $(OBJ) 
	gcc -o $(BIN) $(OBJ) $(LIBS)
clean:
	$(RM) $(BIN) $(OBJ)
