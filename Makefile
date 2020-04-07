CC = gcc

all: thanos thanoscat thanossay

install: thanos_install thanoscat_install thanossay_install

clean:
	rm -f thanos
	rm -f thanoscat
	rm -f thanossay
	rm -f quotes.dat

thanos: thanos.c
	$(CC) -o thanos thanos.c

thanoscat: thanoscat.c
	$(CC) -o thanoscat thanoscat.c

thanossay: thanossay.c
	$(CC) -o thanossay thanossay.c

thanos_install: thanos quotes quotes.dat
	cp thanos /usr/local/bin/thanos
	mkdir -p /usr/share/thanos
	cp quotes quotes.dat /usr/share/thanos

thanoscat_install: thanoscat
	cp thanoscat /usr/local/bin/thanoscat

thanossay_install: thanossay
	cp thanossay /usr/local/bin/thanossay

quotes.dat: quotes
	strfile quotes

