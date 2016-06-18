
CFLAGS != pkg-config --cflags check
LIBS != pkg-config --libs check
VPATH=../src

TEST_OBJECTS = test_roman.o test_single.o test_complex.o test_arabic.o

test: test_roman
	./test_roman

test_roman: roman.o $(TEST_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f *.o
	rm -f test_roman
