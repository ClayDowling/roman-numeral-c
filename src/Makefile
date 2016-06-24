ROMAN_LIBRARY_OBJECTS=roman.o
APP_OBJECTS=roman_app.o main.o

CFLAGS = -g

.PHONY: all clean

all: roman_calculator

libroman.a: $(ROMAN_LIBRARY_OBJECTS)
	ar r $@ $^

libroman_convert.a: roman_convert.o
	ar r $@ $^

clean:
	rm -f roman_calculator
	rm -f *.a
	rm -f *.o

roman_calculator: $(APP_OBJECTS) libroman.a libroman_convert.a
	$(CC) $(CFLAGS) -o $@ $^ -L. -lroman -lroman_convert

roman.c: roman.h
