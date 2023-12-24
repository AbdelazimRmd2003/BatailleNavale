CC = gcc

CFLAGS = -Wall -g

LDFLAGS =


SOURCES = main.c grid.c boats.c playfonction.c

OBJECTS = $(SOURCES:.c=.o)


EXECUTABLE = battleship


all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)


rebuild: clean all

.PHONY: all clean rebuild
