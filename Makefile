MODE=RELEASE
CC=g++
CFLAGS=-std=c++11
LDFLAGS=
EXEC=heritage
SRC=Cercle.cpp Rectangle.cpp Point.cpp Polyligne.cpp Agregat.cpp heritage.cpp Ligne.cpp Modele.cpp ajoutForme.cpp delForme.cpp deplacerForme.cpp CommandReader.cpp Controleur.cpp Executeur.cpp LoadFile.cpp
INT=$(SRC:.cpp=.h)
OBJ=$(SRC:.cpp=.o) heritage.o


#ifeq ($(MODE), DEBUG)
        #CFLAGS:=$(CFLAGS) -g
#endif

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

#ici, les différentes dépendances des .cpp par rapport aux différents .h, à relier avec les #include
Cercle.o : Forme.h Point.h
Rectangle.o : Point.h Forme.h
Ligne.o : Point.h
Modele.o : Forme.h Cercle.h Rectangle.h Ligne.h Polyligne.h Agregat.h Point.h
ajoutForme.o : Command.h
delForme.o : Command.h
deplacerForme.o : Command.h
Controleur.o : Command.h ajoutForme.h delForme.h deplacerForme.h LoadFile.h Modele.h
Executeur.o : Controleur.h
heritage.o : CommandReader.h Executeur.h Controleur.h
LoadFile.o : Command.h Controleur.h Executeur.h CommandReader.h


	
%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

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
