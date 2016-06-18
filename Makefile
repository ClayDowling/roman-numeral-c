PACKAGE_NAME=roman-numeral
SUBDIRS=src test

.PHONY: all src test

all: test


src:
	$(MAKE) -C src


test: src
	$(MAKE) -C test



