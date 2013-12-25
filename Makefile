MODE=RELEASE
CC=g++
CFLAGS=-std=c++11
LDFLAGS=
EXEC=heritage
SRC=Cercle.cpp Rectangle.cpp Point.cpp Polyligne.cpp Agregat.cpp
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

#Framework de test à recréer
test: $(EXEC)
	@make -C Tests
	
