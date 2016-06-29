PACKAGE_NAME=roman-numeral
SUBDIRS=src test
VPATH=src

all: test


src:
	$(MAKE) -C src


test: src
	$(MAKE) -C test

clean:
	$(MAKE) -C src clean
	$(MAKE) -C test clean

