
CFLAGS = `pkg-config --cflags check`
LIBS = `pkg-config --libs check` -L../src -lroman -lroman_convert
VPATH=../src

TEST_OBJECTS = test_roman.o test_single.o test_complex.o test_arabic.o \
	       test_operators.o test_app.o

test: test_roman
	./test_roman

test_roman: roman.o roman_app.o $(TEST_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f *.o
	rm -f test_roman
