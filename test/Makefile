
CFLAGS != pkg-config --cflags check
LIBS != pkg-config --libs check
VPATH=../src

test: test_roman
	./test_roman

test_roman: roman.o test_roman.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f *.o
	rm -f test_roman
