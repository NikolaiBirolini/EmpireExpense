CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -lSDL2 -lrt

SRC = test_affichage.c
OBJ = $(SRC:.c=.o)
EXEC = test_affichage

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJ) $(EXEC)
