MODE=RELEASE
CC=g++
CFLAGS=-std=c++11
LDFLAGS=
EXEC=heritage
INT= Agregat.h ajoutForme.h Cercle.h CommandReader.h Controleur.h delForme.h deplacerForme.h Executeur.h Ligne.h Modele.h Point.h Polyligne.h Rectangle.h
SRC=$(INT:.h=.cpp)
OBJ=$(SRC:.cpp=.o)

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
Controleur.o : Command.h ajoutForme.h delForme.h deplacerForme.h Modele.h
Executeur.o : Controleur.h
heritage.o : CommandReader.h Executeur.h Controleur.h

	
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
