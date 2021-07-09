default: build

build: sl.c 
	cc sl.c -o sl -lncurses

run: build
	./sl

install: build
	cp sl /usr/local/bin

clean: 
	rm sl
