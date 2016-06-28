
CFLAGS = `pkg-config --cflags check`
LIBS = `pkg-config --libs check` -L../src -lroman -lroman_convert
VPATH=../src

TEST_OBJECTS = test_roman.o test_single.o test_complex.o test_arabic.o \
	       test_operators.o test_app.o

test: test_roman memtest
	./test_roman

test_roman: roman_app.o $(TEST_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

memtest: test_roman
	CK_FORK=no valgrind --leak-check=full ./test_roman

clean:
	rm -f *.o
	rm -f test_roman
