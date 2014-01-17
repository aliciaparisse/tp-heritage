MODE=RELEASE
CC=g++
CFLAGS=-std=c++11
LDFLAGS=
EXEC=heritage
SRC=Cercle.cpp Rectangle.cpp Point.cpp Polyligne.cpp Agregat.cpp heritage.cpp Ligne.cpp Modele.cpp ajoutForme.cpp delForme.cpp deplacerForme.cpp CommandReader.cpp Controleur.cpp
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
Modele.o : Forme.h Cercle.h Rectangle.h Ligne.h Polyligne.h Agregat.h Point.h
ajoutForme.o : Command.h
delForme.o : Command.h
deplacerForme.o : Command.h
Controleur.o : Command.h ajoutForme.h delForme.h deplacerForme.h Modele.h

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
