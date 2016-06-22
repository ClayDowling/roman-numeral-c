PACKAGE_NAME=roman-numeral
SUBDIRS=src test

.PHONY: all src test clean

all: test

clean:
	$(MAKE) -C src clean
	$(MAKE) -C test clean

src:
	$(MAKE) -C src


test: src
	$(MAKE) -C test



