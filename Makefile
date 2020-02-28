CC = gcc

all: thanos thanoscat

install: thanos_install thanoscat_install

clean:
	rm -f thanos
	rm -f thanoscat
	rm -f quotes.dat

thanos: thanos.c
	$(CC) -o thanos thanos.c

thanoscat: thanoscat.c
	$(CC) -o thanoscat thanoscat.c

thanos_install: thanos quotes quotes.dat
	cp thanos /usr/local/bin/thanos
	mkdir -p /usr/share/thanos
	cp quotes quotes.dat /usr/share/thanos

thanoscat_install: thanoscat
	cp thanoscat /usr/local/bin/thanoscat

quotes.dat: quotes
	strfile quotes

