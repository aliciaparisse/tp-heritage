MODE=RELEASE
CC=g++
CFLAGS=-std=c++11
LDFLAGS=
EXEC=heritage
SRC=Cercle.cpp Rectangle.cpp Point.cpp Polyligne.cpp Agregat.cpp heritage.cpp Ligne.cpp
#CommandReader.cpp 
OBJ=$(SRC:.cpp=.o)

#ifeq ($(MODE), DEBUG)
	#CFLAGS:=$(CFLAGS) -g
#endif

all: $(EXEC)

heritage: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

#ici, les différentes dépendances des .cpp par rapport aux différents .h, à relier avec les #include
Cercle.o : Forme.h Point.h
Rectangle.o : Point.h Forme.h
CommandReader.o : CommandReader.h
Point.o : Point.h
Ligne.o : Point.h

#Framework de test à recréer
test: $(EXEC)
	@make -C Tests

#t: $(EXEC)
	#@make -C Tests 

clean:
	@rm -rf *.o
	#@make clean -C Test

mrproper: clean
	@rm -rf $(EXEC)
