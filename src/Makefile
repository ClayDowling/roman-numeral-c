OBJECTS=roman.o roman_app.o main.o
CFLAGS = -g

.PHONY: all clean

all: roman_calculator

clean:
	rm -f roman_calculator
	rm -f *.o

roman_calculator: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

roman.c: roman.h
